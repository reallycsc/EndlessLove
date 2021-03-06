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
	m_languageType = LanguageType::ENGLISH;
	m_nGameState = GAMESTATE_ENTER;
	m_nGameLevel = 1;
	m_nGameLevelMax = 0;

	m_bAd = true;
	m_bGuidelineForever = false;

	m_nReviveNumber = 0;

	m_mGameText.clear();
	m_vGameLevelData.clear();
}

GameMediator::~GameMediator(void)
{
	m_mGameText.clear();
	m_vGameLevelData.clear();
}

bool GameMediator::init()
{
	bool bRet = false;
	do
	{
		m_languageType = Application::getInstance()->getCurrentLanguage();

		m_pPlayerData = PlayerData::getInstance();
		CC_BREAK_IF(!m_pPlayerData);

		CC_BREAK_IF(!this->loadGameConfigFile());

		CC_BREAK_IF(!this->loadGameTextFile());

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

	m_pPlayerData->loadPlayerUpgradeConfigFile();
	m_pPlayerData->loadPlayerData();
}

void GameMediator::changeLanguageTo(LanguageType &type)
{
	if (m_languageType == type)
	{
		return;
	}
	m_languageType = type;

	m_mGameText.clear();
	this->loadGameTextFile();

	m_pPlayerData->changeLanguageTo(type);
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
			data->setStage(surface2->IntAttribute("stage"));
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
		string filename;
		switch (m_languageType)
		{
		case LanguageType::CHINESE:
			filename = FileUtils::getInstance()->fullPathForFilename("config/GameText_Chinese.xml");
			break;
		case LanguageType::ENGLISH:
			filename = FileUtils::getInstance()->fullPathForFilename("config/GameText_English.xml");
			break;
		default:
			filename = FileUtils::getInstance()->fullPathForFilename("config/GameText_English.xml");
			break;
		}

        document.LoadFile(filename.c_str());
		XMLElement* root = document.RootElement();
		CC_BREAK_IF(!root);

		for (XMLElement* surface1 = root->FirstChildElement("Text"); surface1 != NULL;
		surface1 = surface1->NextSiblingElement("Text"))
		{
            string str = string(surface1->GetText());
            string oldStr = "\\n";
            string newStr = "\n";
			m_mGameText.insert(pair<string, string>(surface1->Attribute("id"), replace_all_distinct(str, oldStr, newStr)));
		}

		bRet = true;
	} while (false);
	return bRet;
}

void GameMediator::initGame()
{
	m_nGameState = GAMESTATE_ENTER;
	m_nGameLevel = 1;
	m_nReviveNumber = 0;
	m_pPlayerData->initPlayerData();
}