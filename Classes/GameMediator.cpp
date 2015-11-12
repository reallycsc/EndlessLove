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
	m_iGameState = STATE_GAME_ENTER;
	m_iGameLevel = 0;
	m_iGameLevelMax = 0;
	_mapGameStory.clear();
	_mapGameText.clear();
	_vectorGameLevelData.clear();
}

GameMediator::~GameMediator(void)
{
	_mapGameStory.clear();
	_mapGameText.clear();
	_vectorGameLevelData.clear();
}

bool GameMediator::init(){
	do
	{
		_playerData = PlayerData::create();
		CHECKFALSE(_playerData);

		CHECKFALSE(this->loadGameConfigFile());

		CHECKFALSE(this->loadGameTextFile());

		CHECKFALSE(this->loadGameStoryFile());

	} while (false);
	
	return true;
}

string& replace_all_distinct(string& str, const string& old_value, const string& new_value)
{
	for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
		if ((pos = str.find(old_value, pos)) != string::npos)
			str.replace(pos, old_value.length(), new_value);
		else   break;
	}
	return   str;
}

bool GameMediator::loadGameConfigFile()
{
	tinyxml2::XMLDocument document;
	document.LoadFile("config/GameConfig.xml");
	XMLElement* root = document.RootElement();
	CHECKFALSE(root);

	Size winSize = Director::getInstance()->getWinSize();

	// load game level config
	XMLElement* surface1 = root->FirstChildElement("GameLevel");
	CHECKFALSE(surface1);
	for (XMLElement* surface2 = surface1->FirstChildElement("Level"); surface2 != NULL; surface2 = surface2->NextSiblingElement("Level"))
	{
		m_iGameLevelMax++;
		GameLevelData* data = NULL;
		if (m_iGameLevelMax == 1)
		{
			data = GameLevelData::create();
		}
		else
		{
			data = GameLevelData::create(&_vectorGameLevelData[m_iGameLevelMax-2]);
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

		int mostMinInterval = int(data->getPlayerMoveSpeed() * (2 * winSize.height / GRAVITY + 1));
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
				data->setEnemyDownMinHeight(int(surface4->FloatAttribute("minScale") * winSize.height + surface4->IntAttribute("minOffset")));
				data->setEnemyDownMaxHeight(int(surface4->FloatAttribute("maxScale") * winSize.height + surface4->IntAttribute("maxOffset")));
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
				data->setEnemyDownMinInterval(MAX(int(mostMinInterval * surface4->FloatAttribute("minScale")), mostMinInterval));
				data->setEnemyDownMaxInterval(MAX(int(mostMinInterval * surface4->FloatAttribute("maxScale")), mostMinInterval));
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
				data->setEnemyUpMinInterval(MAX(int(mostMinInterval * surface4->FloatAttribute("minScale")), mostMinInterval));
				data->setEnemyUpMaxInterval(MAX(int(mostMinInterval * surface4->FloatAttribute("maxScale")), mostMinInterval));
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
				data->setItemMinInterval(MAX(int(mostMinInterval * surface4->FloatAttribute("minScale")), mostMinInterval));
				data->setItemMaxInterval(MAX(int(mostMinInterval * surface4->FloatAttribute("maxScale")), mostMinInterval));
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

		_vectorGameLevelData.push_back((*data));
	}
	return true;
}

bool GameMediator::loadGameTextFile()
{
	tinyxml2::XMLDocument document;

#if defined LANGUAGE_CHINESE
	document.LoadFile("config/GameText_Chinese.xml");
#elif defined LANGUAGE_ENGLISH
	document.LoadFile("config/GameText_English.xml");
#endif

	XMLElement* root = document.RootElement();
	CHECKFALSE(root);

	for (XMLElement* surface1 = root->FirstChildElement("Text"); surface1 != NULL;
	surface1 = surface1->NextSiblingElement("Text"))
	{
		_mapGameText.insert(pair<int, string>(surface1->IntAttribute("id"), replace_all_distinct(string(surface1->GetText()), "\\n", "\n")));
	}
	return true;
}

bool GameMediator::loadGameStoryFile()
{
	tinyxml2::XMLDocument document;
	document.LoadFile("config/GameStory.xml");
	XMLElement* root = document.RootElement();
	CHECKFALSE(root);
	vector<string> _vString;
	for (XMLElement* surface1 = root->FirstChildElement("GameOver");surface1 != NULL;
		surface1 = surface1->NextSiblingElement("GameOver"))
	{
		// load intersect story
		_vString.clear();
		for (XMLElement* surface2 = surface1->FirstChildElement("Bomb");surface2 != NULL;surface2 = surface2->NextSiblingElement("Bomb"))
		{
			_vString.push_back(replace_all_distinct(string(surface2->GetText()), "\\n", "\n"));
		}
		_mapGameStory.insert(pair<int, vector<string>>(GAMEOVER_REASON_BOMB, _vString));
		
		// load noheart story
		_vString.clear();
		for (XMLElement* surface2 = surface1->FirstChildElement("Noheart"); surface2 != NULL; surface2 = surface2->NextSiblingElement("Noheart"))
		{
			_vString.push_back(replace_all_distinct(string(surface2->GetText()), "\\n", "\n"));
		}
		_mapGameStory.insert(pair<int, vector<string>>(GAMEOVER_REASON_NOHEART, _vString));
	}
	return true;
}

void GameMediator::initGame()
{
	m_iGameState = STATE_GAME_ENTER;
	m_iGameLevel = 0;
	_playerData->initPlayerData();
}

// Common function
void GameMediator::spriteToGrey(Node* pNode, float percent)
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
			float grey = dot(col.rgb, vec3(0.299, 0.587, 0.114)); \n\
			float r = (col.r-grey)*%f + grey; \n\
			float g = (col.g-grey)*%f + grey; \n\
			float b = (col.b-grey)*%f + grey; \n\
			gl_FragColor = vec4(r, g, b, col.a); \n\
		}";
	if (percent < 0)
		percent = 0;
	if (percent > 1)
		percent = 1;
	const GLchar* pszFragSource = String::createWithFormat(format, percent, percent, percent)->getCString();

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