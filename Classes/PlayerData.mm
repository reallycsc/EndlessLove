#include "PlayerData.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#import "GameKitHelper.h"
#endif

PlayerData::PlayerData(void)
{
	m_fHeartNumber = 0.0f;
	m_fMaxHeartNumber = 0.0f;
	m_nStrength = 0;
	m_fPowerTime = 0.0f;

	m_nScore = 0;
	m_nHighscore = 0;
	m_nGoldNumber = 0;
	m_nGoldNumberAll = 0;

	m_nMinStrength = 0;
	m_fDefaultHeartNumber = 0.0f;

	m_mLevels.clear();
	m_mInfoName.clear();
	m_vJumpTypeLevelInfo.clear();
	m_mLevelInfo.clear();
}

PlayerData::~PlayerData(void)
{
	m_mLevels.clear();
	m_mInfoName.clear();
	m_vJumpTypeLevelInfo.clear();
	m_mLevelInfo.clear();
}

PlayerData* PlayerData::create()
{
	PlayerData* pRet = new(std::nothrow) PlayerData();
	if (pRet && pRet->init())
	{
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool PlayerData::init()
{  
    bool bRet = false;  
    do   
    {  
        cocos2d::Size winSize = Director::getInstance()->getWinSize();

		// load player upgrade config file
		this->loadPlayerUpgradeConfigFile();
		this->loadPlayerData();

		// set default
		m_fDefaultHeartNumber = 1;
		m_nMinStrength = sqrt(winSize.height * GRAVITY);

		this->initPlayerData();
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        // add custom event lisenter
        EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
        auto listener = EventListenerCustom::create(EVENT_GAMECENTER_SCORERETRIVED, [=](EventCustom* event){
            char* buf = static_cast<char*>(event->getUserData());
            long long score;
            sscanf(buf, "%lld", &score);
            m_nHighscore = score;
            this->savePlayerData();
            dispatcher->dispatchCustomEvent(EVENT_PLARERDATA_SCOREUPDATED);
        });
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
#endif
        
        bRet = true;
    } while (0);
    
    return bRet;
}

bool PlayerData::loadLevelDataForFloat(XMLElement* root, const char* elementName, int id)
{
	bool bRet = false;
	do
	{
		XMLElement* surface1 = root->FirstChildElement(elementName);
		CC_BREAK_IF(!surface1);
		m_mInfoName.insert(pair<int, string>(id, elementName));
		m_mLevels.insert(pair<int, int>(id, 1));
		vector<FLOAT_LEVEL_INFO> vData;
		for (XMLElement* surface2 = surface1->FirstChildElement("Level"); surface2 != NULL; surface2 = surface2->NextSiblingElement("Level"))
		{
			FLOAT_LEVEL_INFO data;
			data.level = surface2->IntAttribute("level");
			data.needGold = surface2->IntAttribute("needGold");
			data.number = surface2->FloatAttribute("number");
			vData.push_back(data);
		}
		m_mLevelInfo.insert(pair<int, vector<FLOAT_LEVEL_INFO>>(id, vData));

		bRet = true;
	} while (false);
	return bRet;
}

bool PlayerData::loadPlayerUpgradeConfigFile()
{
	bool bRet = false;
	do
	{
		tinyxml2::XMLDocument document;
        string filename = FileUtils::getInstance()->fullPathForFilename("config/PlayerUpgradeConfig.xml");
        document.LoadFile(filename.c_str());
		XMLElement* root = document.RootElement();
		CC_BREAK_IF(!root);

		// load game level config
		XMLElement* surface1 = root->FirstChildElement("JumpType");
		CC_BREAK_IF(!surface1);
		m_mInfoName.insert(pair<int, string>(ID_JUMP_TYPE, "JumpType"));
		m_mLevels.insert(pair<int, int>(ID_JUMP_TYPE, 1));
		for (XMLElement* surface2 = surface1->FirstChildElement("Level"); surface2 != NULL; surface2 = surface2->NextSiblingElement("Level"))
		{
			JUMP_TYPE data;
			data.level = surface2->IntAttribute("level");
			data.needGold = surface2->IntAttribute("needGold");
			data.powerUpOnTheGround = surface2->BoolAttribute("powerUpOnTheGround");
			data.jumpOnTheGround = surface2->BoolAttribute("jumpOnTheGround");
			data.freeJumpTime = surface2->IntAttribute("freeJumpTime");
			m_vJumpTypeLevelInfo.push_back(data);
		}

		CC_BREAK_IF(!loadLevelDataForFloat(root, "MaxHeartNumber", ID_MAXHEART_NUMBER));
		CC_BREAK_IF(!loadLevelDataForFloat(root, "Strength", ID_STRENGTH));
		CC_BREAK_IF(!loadLevelDataForFloat(root, "PowerTime", ID_POWER_TIME));
		CC_BREAK_IF(!loadLevelDataForFloat(root, "GuidelineTime", ID_GUIDELINE_TIME));
		CC_BREAK_IF(!loadLevelDataForFloat(root, "EnlargeTime", ID_ENLARGE_TIME));
		CC_BREAK_IF(!loadLevelDataForFloat(root, "ShrinkTime", ID_SHRINK_TIME));
		CC_BREAK_IF(!loadLevelDataForFloat(root, "ShieldTime", ID_SHIELD_TIME));

	bRet = true;
	} while (false);
	return bRet;
}

void PlayerData::initPlayerData()
{
	m_fMaxHeartNumber = m_mLevelInfo.at(ID_MAXHEART_NUMBER).at(m_mLevels.at(ID_MAXHEART_NUMBER) - 1).number;
	m_fHeartNumber = m_fDefaultHeartNumber;
	m_nStrength = m_nMinStrength * (m_mLevelInfo.at(ID_STRENGTH).at(m_mLevels.at(ID_STRENGTH) - 1).number + 99) * 0.01;
	m_fPowerTime = m_mLevelInfo.at(ID_POWER_TIME).at(m_mLevels.at(ID_POWER_TIME) - 1).number;
	m_fGuidelineTime = m_mLevelInfo.at(ID_GUIDELINE_TIME).at(m_mLevels.at(ID_GUIDELINE_TIME) - 1).number;
	m_fEnlargeTime = m_mLevelInfo.at(ID_ENLARGE_TIME).at(m_mLevels.at(ID_ENLARGE_TIME) - 1).number;
	m_fShrinkTime = m_mLevelInfo.at(ID_SHRINK_TIME).at(m_mLevels.at(ID_SHRINK_TIME) - 1).number;
	m_fShieldTime = m_mLevelInfo.at(ID_SHIELD_TIME).at(m_mLevels.at(ID_SHIELD_TIME) - 1).number;

	m_nScore = 0;
	m_nGoldNumber = 0;
}

void PlayerData::saveDefaultData(UserDefault* user)
{
	user->setBoolForKey("isHaveSaveFileXml", true);
	user->setIntegerForKey("Highscore", 0);
	user->setIntegerForKey("GoldNumber", 0);
	for (int i = ID_MIN + 1; i < ID_MAX; i++)
	{
		string str = m_mInfoName.at(i) + "Level";
		user->setIntegerForKey(str.c_str(), 1);
	}
	user->flush();
}

bool PlayerData::loadPlayerData()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    // get data from game center
    GameKitHelper* helper = [GameKitHelper sharedHelper];
    if (helper.isAuthenticated == YES)
    {
        [[GameKitHelper sharedHelper] retirieveLocalPlayerScore:@"Highscore"];
    }
#endif
    
    // get local data
	UserDefault* user = UserDefault::getInstance();
	if (!user->getBoolForKey("isHaveSaveFileXml"))
	{
		saveDefaultData(user);
		return false;
	}
	else
	{
        if (helper.isAuthenticated == NO)
        {
            m_nHighscore = user->getIntegerForKey("Highscore", 0);
        }
		m_nGoldNumberAll = user->getIntegerForKey("GoldNumber", 0);
		for (int i = ID_MIN + 1; i < ID_MAX; i++)
		{
			string str = m_mInfoName.at(i) + "Level";
			m_mLevels.at(i) = user->getIntegerForKey(str.c_str(), 1);
		}

		return true;
	}
}

bool PlayerData::savePlayerData()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    // save data to game center
    GameKitHelper* helper = [GameKitHelper sharedHelper];
    if (helper.isAuthenticated == YES)
    {
        [helper reportScore:m_nHighscore forLeaderboard:@"Highscore"];
    }
#endif
    
    // save to local data
	UserDefault* user = UserDefault::getInstance();
	if (!user->getBoolForKey("isHaveSaveFileXml"))
	{
		saveDefaultData(user);
		return false;
	}
	else
	{
		user->setIntegerForKey("Highscore", (int)m_nHighscore);
		user->setIntegerForKey("GoldNumber", m_nGoldNumberAll);
		for (int i = ID_MIN + 1; i < ID_MAX; i++)
		{
			string str = m_mInfoName.at(i) + "Level";
			user->setIntegerForKey(str.c_str(), m_mLevels.at(i));
		}

		return true;
	}
}