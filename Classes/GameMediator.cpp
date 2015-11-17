#include "GameMediator.h"

static GameMediator _sharedContext;

GameMediator* GameMediator::getInstance()
{
	static bool s_bFirstUse = true; 
	if (s_bFirstUse) 
		{ 
		_sharedContext.init(); 
		s_bFirstUse = false; 
		} 
	return &_sharedContext; 
}

GameMediator::GameMediator(void)
{
	m_nGameState = STATE_GAME_ENTER;
	m_nGameLevel = 0;
	m_nGameLevelMax = 0;
	m_nGameOverReason = 0;
	m_mGameStory.clear();
	m_mGameText.clear();
	m_vGameLevelData.clear();
}

GameMediator::~GameMediator(void)
{
	m_mGameStory.clear();
	m_mGameText.clear();
	m_vGameLevelData.clear();
}

bool GameMediator::init()
{
	bool bRet = false;
	do
	{
		m_pPlayerData = PlayerData::create();
		CC_BREAK_IF(!m_pPlayerData);

		CC_BREAK_IF(!this->loadGameConfigFile());

		CC_BREAK_IF(!this->loadGameTextFile());

		CC_BREAK_IF(!this->loadGameStoryFile());

		bRet = true;
	} while (false);
	
	return bRet;
}

void GameMediator::reloadAllConfigFiles()
{
	bool ret;

	m_nGameLevelMax = 0;

	m_vGameLevelData.clear();
	ret = this->loadGameConfigFile();
	if (!ret)
		return;

	m_mGameText.clear();
	ret = this->loadGameTextFile();
	if (!ret)
		return;

	m_mGameStory.clear();
	ret = this->loadGameStoryFile();
	if (!ret)
		return;

	m_pPlayerData->loadPlayerData();
}

bool GameMediator::loadGameConfigFile()
{
	bool bRet = false;
	do
	{
		tinyxml2::XMLDocument document;
        string filename = FileUtils::getInstance()->fullPathForFilename("config/GameConfig.xml");
		document.LoadFile(filename.c_str());
		XMLElement* root = document.RootElement();
		CC_BREAK_IF(!root);

		Size winSize = Director::getInstance()->getWinSize();

		// load game level config
		XMLElement* surface1 = root->FirstChildElement("GameLevel");
		CC_BREAK_IF(!surface1);
		for (XMLElement* surface2 = surface1->FirstChildElement("Level"); surface2 != NULL; surface2 = surface2->NextSiblingElement("Level"))
		{
			m_nGameLevelMax++;
			GameLevelData* data = NULL;
			if (m_nGameLevelMax == 1)
			{
				data = GameLevelData::create();
			}
			else
			{
				data = GameLevelData::create(&m_vGameLevelData[m_nGameLevelMax - 2]);
			}

			data->setLevel(surface2->IntAttribute("level"));
			data->setLevelUpScore(surface2->IntAttribute("levelUpScore"));

			// Player attribute
			do
			{
				XMLElement* surface3 = surface2->FirstChildElement("Player");
				if (!surface3)
					break;

				XMLElement* surface4 = surface3->FirstChildElement("PlayerMoveTime");
				if (surface4)
				{
					data->setPlayerMoveSpeed(int(winSize.width / surface4->FloatAttribute("time")));
				}
			} while (false);

			// Enemy down attribute
			do
			{
				XMLElement* surface3 = surface2->FirstChildElement("EnemyDown");
				if (!surface3)
					break;
				bool isShow = surface3->BoolAttribute("isShow");
				data->setEnemyDownIsShow(isShow);
				if (!isShow)
					break;
				data->setEnemyDownIsBindItem(surface3->BoolAttribute("isBindItem"));

				XMLElement* surface4 = surface3->FirstChildElement("EnemyHeight");
				if (surface4)
				{
					data->setEnemyDownMinHeight(int(surface4->FloatAttribute("minScale") * winSize.height));
					data->setEnemyDownMaxHeight(int(surface4->FloatAttribute("maxScale") * winSize.height));
				}

				surface4 = surface3->FirstChildElement("EnemyWidth");
				if (surface4)
				{
					data->setEnemyDownMinWidthScale(surface4->FloatAttribute("minScale"));
					data->setEnemyDownMaxWidthScale(surface4->FloatAttribute("maxScale"));
				}

				surface4 = surface3->FirstChildElement("EnemyMoveSpeed");
				if (surface4)
				{
					data->setEnemyDownMinMoveSpeed(int(data->getPlayerMoveSpeed() * surface4->FloatAttribute("minScale")));
					data->setEnemyDownMaxMoveSpeed(int(data->getPlayerMoveSpeed() * surface4->FloatAttribute("maxScale")));
				}

				surface4 = surface3->FirstChildElement("EnemyInterval");
				if (surface4)
				{
					data->setEnemyDownMinInterval(int(winSize.width * surface4->FloatAttribute("minScale")));
					data->setEnemyDownMaxInterval(int(winSize.width * surface4->FloatAttribute("maxScale")));
				}
			} while (false);

			// Enemy up attribute
			do
			{
				XMLElement* surface3 = surface2->FirstChildElement("EnemyUp");
				if (!surface3)
					break;
				bool isShow = surface3->BoolAttribute("isShow");
				data->setEnemyUpIsShow(isShow);
				if (!isShow)
					break;
				data->setEnemyUpIsSamePos(surface3->BoolAttribute("isSamePos"));

				XMLElement* surface4 = surface3->FirstChildElement("EnemyHeight");
				if (surface4)
				{
					data->setEnemyUpMinHeightOffset(surface4->IntAttribute("minOffset"));
					data->setEnemyUpMaxHeightOffset(surface4->IntAttribute("maxOffset"));
				}

				surface4 = surface3->FirstChildElement("EnemyWidth");
				if (surface4)
				{
					data->setEnemyUpMinWidthScale(surface4->FloatAttribute("minScale"));
					data->setEnemyUpMaxWidthScale(surface4->FloatAttribute("maxScale"));
				}

				surface4 = surface3->FirstChildElement("EnemyMoveSpeed");
				if (surface4)
				{
					data->setEnemyUpMinMoveSpeed(int(data->getPlayerMoveSpeed() * surface4->FloatAttribute("minScale")));
					data->setEnemyUpMaxMoveSpeed(int(data->getPlayerMoveSpeed() * surface4->FloatAttribute("maxScale")));
				}

				surface4 = surface3->FirstChildElement("EnemyInterval");
				if (surface4)
				{
					data->setEnemyUpMinInterval(int(winSize.width * surface4->FloatAttribute("minScale")));
					data->setEnemyUpMaxInterval(int(winSize.width * surface4->FloatAttribute("maxScale")));
				}
			} while (false);

			// Item attribute
			do
			{
				XMLElement* surface3 = surface2->FirstChildElement("Item");
				if (!surface3)
					break;
				data->setItemIsCurve(surface3->BoolAttribute("isCurve"));

				XMLElement* surface4 = surface3->FirstChildElement("ItemMoveSpeed");
				if (surface4)
				{
					data->setItemMinMoveSpeed(int(data->getPlayerMoveSpeed() * surface4->FloatAttribute("minScale")));
					data->setItemMaxMoveSpeed(int(data->getPlayerMoveSpeed() * surface4->FloatAttribute("maxScale")));
				}

				surface4 = surface3->FirstChildElement("ItemInterval");
				if (surface4)
				{
					data->setItemMinInterval(int(winSize.width * surface4->FloatAttribute("minScale")));
					data->setItemMaxInterval(int(winSize.width * surface4->FloatAttribute("maxScale")));
				}

				surface4 = surface3->FirstChildElement("ItemAddProp");
				if (surface4)
				{
					data->setItemAddMapMaxProp(surface4->IntAttribute("MaxProp"));
					map<int, int>* map = data->getItemAddMap();
					map->clear();
					for (XMLElement* surface5 = surface4->FirstChildElement("Item"); surface5 != NULL; surface5 = surface5->NextSiblingElement("Item"))
					{
						map->insert(pair<int, int>(surface5->IntAttribute("ItemType"), surface5->IntAttribute("ItemProp")));
					}
				}
			} while (false);

			m_vGameLevelData.push_back((*data));
		}
		bRet = true;
	} while (false);

	return bRet;
}

string& GameMediator::replace_all_distinct(string& str, string& old_value, string& new_value)
{
    for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
        if ((pos = str.find(old_value, pos)) != string::npos)
        str.replace(pos, old_value.length(), new_value);
        else   break;
    }
    return   str;
}

bool GameMediator::loadGameTextFile()
{
	bool bRet = false;
	do
	{
		tinyxml2::XMLDocument document;
        string filename = FileUtils::getInstance()->fullPathForFilename("config/GameText_English.xml");
#if defined LANGUAGE_CHINESE
        filename = FileUtils::getInstance()->fullPathForFilename("config/GameText_Chinese.xml");
#elif defined LANGUAGE_ENGLISH
        //filename = FileUtils::getInstance()->fullPathForFilename("config/GameText_English.xml");
#endif
        document.LoadFile(filename.c_str());
		XMLElement* root = document.RootElement();
		CC_BREAK_IF(!root);

		for (XMLElement* surface1 = root->FirstChildElement("Text"); surface1 != NULL;
		surface1 = surface1->NextSiblingElement("Text"))
		{
            string str = string(surface1->GetText());
            string oldStr = "\\n";
            string newStr = "\n";
			m_mGameText.insert(pair<int, string>(surface1->IntAttribute("id"), replace_all_distinct(str, oldStr, newStr)));
		}

		bRet = true;
	} while (false);
	return bRet;
}

bool GameMediator::loadGameStoryFile()
{
	bool bRet = false;
	do
	{
		tinyxml2::XMLDocument document;
        string filename = FileUtils::getInstance()->fullPathForFilename("config/GameStory.xml");
		document.LoadFile(filename.c_str());
		XMLElement* root = document.RootElement();
		CC_BREAK_IF(!root);
		vector<string> _vString;
		for (XMLElement* surface1 = root->FirstChildElement("GameOver"); surface1 != NULL;
		surface1 = surface1->NextSiblingElement("GameOver"))
		{
			// load intersect story
			_vString.clear();
			for (XMLElement* surface2 = surface1->FirstChildElement("Bomb"); surface2 != NULL; surface2 = surface2->NextSiblingElement("Bomb"))
			{
                string str = string(surface2->GetText());
                string oldStr = "\\n";
                string newStr = "\n";
				_vString.push_back(replace_all_distinct(str, oldStr, newStr));
			}
			m_mGameStory.insert(pair<int, vector<string>>(GAMEOVER_REASON_BOMB, _vString));

			// load noheart story
			_vString.clear();
			for (XMLElement* surface2 = surface1->FirstChildElement("Noheart"); surface2 != NULL; surface2 = surface2->NextSiblingElement("Noheart"))
			{
                string str = string(surface2->GetText());
                string oldStr = "\\n";
                string newStr = "\n";
				_vString.push_back(replace_all_distinct(str, oldStr, newStr));
			}
			m_mGameStory.insert(pair<int, vector<string>>(GAMEOVER_REASON_NOHEART, _vString));
		}
		bRet = true;
	} while (false);
	return bRet;
}

void GameMediator::initGame()
{
	m_nGameState = STATE_GAME_ENTER;
	m_nGameLevel = 0;
	m_pPlayerData->initPlayerData();
}

// Common function
void GameMediator::spriteToGray(Node* pNode, float percent)
{
	ImageView* imgView = dynamic_cast<ImageView*>(pNode);
	Sprite* imgView2 = dynamic_cast<Sprite*>(pNode);
	Sprite* sp = nullptr;
	if (imgView) {
		Scale9Sprite* scale9sp = dynamic_cast<Scale9Sprite*>(imgView->getVirtualRenderer());
		if (scale9sp) {
			sp = scale9sp->getSprite();
		}
	}
	else if (imgView2) {
		sp = imgView2;
	}
	if (!sp) {
		return;
	}
	
	const char* format = 
		"#ifdef GL_ES \n\
			precision mediump float; \n\
		#endif \n\
		varying vec2 v_texCoord; \n\
		varying vec4 v_fragmentColor; \n\
		void main(void) \n\
		{ \n\
			// Convert to greyscale using NTSC weightings \n\
			vec4 col = v_fragmentColor * texture2D(CC_Texture0, v_texCoord); \n\
			float gray = dot(col.rgb, vec3(0.299, 0.587, 0.114)); \n\
			float r = (col.r-gray)*%f + gray; \n\
			float g = (col.g-gray)*%f + gray; \n\
			float b = (col.b-gray)*%f + gray; \n\
			gl_FragColor = vec4(r, g, b, col.a); \n\
		}";
	if (percent < 0)
		percent = 0;
	if (percent > 1)
		percent = 1;
    const GLchar* pszFragSource = StringUtils::format(format, percent, percent, percent).c_str();

	GLProgram* pProgram = new GLProgram();
	pProgram->initWithByteArrays(ccPositionTextureColor_noMVP_vert, pszFragSource);
	sp->setGLProgram(pProgram);
	pProgram->release();
	CHECK_GL_ERROR_DEBUG();
	sp->getGLProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
	sp->getGLProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
	sp->getGLProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);
	CHECK_GL_ERROR_DEBUG();
	sp->getGLProgram()->link();
	CHECK_GL_ERROR_DEBUG();
	sp->getGLProgram()->updateUniforms();
	CHECK_GL_ERROR_DEBUG();
}

Widget* GameMediator::replaceNodeWithWidget(Node* node)
{
	Widget* widget = Widget::create();
	widget->setAnchorPoint(node->getAnchorPoint());
	widget->setName(node->getName());
	widget->setPosition(node->getPosition());
	widget->setContentSize(node->getContentSize());
	widget->setScaleX(node->getScaleX());
	widget->setScaleY(node->getScaleY());
	widget->setRotation(node->getRotationSkewX());

	// 将Node的孩子挂到widget上
	auto children = node->getChildren();
	for (int i = 0; i < children.size(); i++)
	{
		auto child = children.at(i);
		child->retain();
		node->removeChild(child);
		widget->addChild(child, child->getLocalZOrder());
		child->release();
	}

	// 从父节点摘除
	auto parent = node->getParent();
	if (parent)
	{
		parent->addChild(widget, node->getLocalZOrder());
		parent->removeChild(node);
	}
	return widget;
}