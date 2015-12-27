#include "PlayerData.h"
#include "CSCClass/CSC_IOSHelper.h"

static PlayerData _sharedContext;

PlayerData* PlayerData::getInstance()
{
	static bool s_bFirstUse = true;
	if (s_bFirstUse)
	{
		_sharedContext.init();
		s_bFirstUse = false;
	}
	return &_sharedContext;
}

PlayerData::PlayerData(void)
{
	m_languageType = LanguageType::ENGLISH;
	m_fHeartNumber = 0.0f;
	m_fMaxHeartNumber = 0.0f;
	m_bPowerUpOnTheGround = true;
	m_bJumpOnTheGround = true;
	m_nFreeJumpTime = 0;
	m_nStrength = 0;
	m_fPowerTime = 0.0f;

	m_nScore = 0;
	m_nHighscore = 0;
	m_nGoldNumber = 0;
	m_nGoldNumberAll = 0;
    
    m_nGoldNumberAcc = 0;
    m_nReviveNumber = 0;
    m_nDoubleNumber = 0;

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

bool PlayerData::init()
{  
    bool bRet = false;  
    do   
    {  
		m_languageType = Application::getInstance()->getCurrentLanguage();

        cocos2d::Size winSize = Director::getInstance()->getWinSize();

		// load player upgrade config file
		this->loadPlayerUpgradeConfigFile();
		this->loadPlayerData();

		// set default
		m_fDefaultHeartNumber = 1;
		m_nMinStrength = sqrt(winSize.height * GRAVITY);

		this->initPlayerData();
        
        // add custom event lisenter
        this->addCustomEventLisenter("Highscore", &m_nHighscore);
        this->addCustomEventLisenter("GoldNumber", &m_nGoldNumberAll);
        this->addCustomEventLisenter("GoldNumberAll", &m_nGoldNumberAcc);
        this->addCustomEventLisenter("ReviveNumber", &m_nReviveNumber);
        this->addCustomEventLisenter("DoubleNumber", &m_nDoubleNumber);
        
        bRet = true;
    } while (0);
    
    return bRet;
}

void PlayerData::changeLanguageTo(LanguageType &type)
{
	if (m_languageType == type)
	{
		return;
	}
	m_languageType = type;

	m_vJumpTypeLevelInfo.clear();
	m_mLevelInfo.clear();
	this->loadPlayerUpgradeConfigFile();
}

inline void PlayerData::addCustomEventLisenter(const string suffix, long long* pScore)
{
    EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerCustom::create(EVENT_GAMECENTER_SCORERETRIVED + suffix, [=](EventCustom* event){
        char* buf = static_cast<char*>(event->getUserData());
        long long score;
        sscanf(buf, "%lld", &score);
        (*pScore) = score;
        this->saveIntPlayerDara(suffix.c_str(), static_cast<int>(score), false);
        dispatcher->dispatchCustomEvent(EVENT_PLARERDATA_SCOREUPDATED + suffix);
    });
    dispatcher->addEventListenerWithFixedPriority(listener, 1);
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
			switch (m_languageType)
			{
                case LanguageType::CHINESE:
                    data.description = surface2->Attribute("description_cn");
                    break;
                case LanguageType::ENGLISH:
                    data.description = surface2->Attribute("description_en");
                    break;
                default:
                    data.description = surface2->Attribute("description_en");
                    break;
		}
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
	JUMP_TYPE* jumpType = &m_vJumpTypeLevelInfo.at(m_mLevels.at(ID_JUMP_TYPE) - 1);
	m_bPowerUpOnTheGround = jumpType->powerUpOnTheGround;
	m_bJumpOnTheGround = jumpType->jumpOnTheGround;
	m_nFreeJumpTime = jumpType->freeJumpTime;
	m_nStrength = m_nMinStrength * (m_mLevelInfo.at(ID_STRENGTH).at(m_mLevels.at(ID_STRENGTH) - 1).number + 99) * 0.01;
	m_fPowerTime = m_mLevelInfo.at(ID_POWER_TIME).at(m_mLevels.at(ID_POWER_TIME) - 1).number;

	m_fGuidelineTime = m_mLevelInfo.at(ID_GUIDELINE_TIME).at(m_mLevels.at(ID_GUIDELINE_TIME) - 1).number;
	m_fEnlargeTime = m_mLevelInfo.at(ID_ENLARGE_TIME).at(m_mLevels.at(ID_ENLARGE_TIME) - 1).number;
	m_fShrinkTime = m_mLevelInfo.at(ID_SHRINK_TIME).at(m_mLevels.at(ID_SHRINK_TIME) - 1).number;
	m_fShieldTime = m_mLevelInfo.at(ID_SHIELD_TIME).at(m_mLevels.at(ID_SHIELD_TIME) - 1).number;

	m_nScore = 0;
	m_nGoldNumber = 0;
}

void PlayerData::initPlayerHeartNumber()
{
	m_fHeartNumber = m_fDefaultHeartNumber;
}

// add data
void PlayerData::finishGameAddGoldNumber()
{
    m_nGoldNumberAll += m_nGoldNumber;
    m_nGoldNumberAcc += m_nGoldNumber;
    this->saveIntPlayerDara("GoldNumber", static_cast<int>(m_nGoldNumberAll));
    this->saveIntPlayerDara("GoldNumberAll", static_cast<int>(m_nGoldNumberAcc));
	CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.gold50", m_nGoldNumberAcc * 2);
    if (m_nGoldNumberAcc > 50)
		CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.gold100", m_nGoldNumberAcc);
    if (m_nGoldNumberAcc > 100)
		CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.gold500", m_nGoldNumberAcc / 5);
    if (m_nGoldNumberAcc > 500)
		CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.gold1000", m_nGoldNumberAcc / 10);
    if (m_nGoldNumberAcc > 1000)
		CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.gold5000", m_nGoldNumberAcc / 50);
}

void PlayerData::finishGameAddScore()
{
    if (m_nScore > m_nHighscore)
    {
        m_nHighscore = m_nScore;
        this->saveIntPlayerDara("Highscore", static_cast<int>(m_nHighscore));
		CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.score25", m_nHighscore * 4);
        if (m_nHighscore > 25)
			CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.score50", m_nHighscore * 2);
        if (m_nHighscore > 50)
			CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.score75", m_nHighscore * 4 / 3);
        if (m_nHighscore > 75)
			CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.score100", m_nHighscore);
        if (m_nHighscore > 100)
			CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.score150", m_nHighscore * 2 / 3);
        if (m_nHighscore > 150)
			CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.score200", m_nHighscore / 2);
        if (m_nHighscore > 200)
			CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.score300", m_nHighscore / 3);
        if (m_nHighscore > 300)
	        CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.score400", m_nHighscore / 4);
	    if (m_nHighscore > 400)
		    CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.score500", m_nHighscore / 5);
    }
}

void PlayerData::setLevelFor(int id, int level)
{
    m_mLevels.at(id) = level;
    this->saveLevelPlayerData(id);
}
// save & load data
void PlayerData::saveDefaultData(UserDefault* user)
{
	user->setBoolForKey("isHaveSaveFileXml", true);
    user->setIntegerForKey("Highscore", 0);
    user->setIntegerForKey("GoldNumber", 0);
    user->setIntegerForKey("GoldNumberAll", 0);
    user->setIntegerForKey("ReviveNumber", 0);
    user->setIntegerForKey("DoubleNumber", 0);
	for (int i = ID_MIN + 1; i < ID_MAX; i++)
	{
		string str = m_mInfoName.at(i) + "Level";
		user->setIntegerForKey(str.c_str(), 1);
	}
	user->flush();
}

bool PlayerData::loadPlayerData()
{
	bool isGameCenterLogged = CSC_IOSHelper::GameCenter_isAuthenticated();
	// get data from game center
	if (isGameCenterLogged)
	{
		CSC_IOSHelper::GameCenter_retriveScoreFromLeaderboard("Highscore");
		CSC_IOSHelper::GameCenter_retriveScoreFromLeaderboard("GoldNumber");
		CSC_IOSHelper::GameCenter_retriveScoreFromLeaderboard("GoldNumberAll");
		CSC_IOSHelper::GameCenter_retriveScoreFromLeaderboard("ReviveNumber");
		CSC_IOSHelper::GameCenter_retriveScoreFromLeaderboard("DoubleNumber");
	}

	// get local data
	UserDefault* user = UserDefault::getInstance();
	if (!user->getBoolForKey("isHaveSaveFileXml"))
	{
		saveDefaultData(user);
		return false;
	}
	else
	{
		// get data from local file
		if (!isGameCenterLogged)
		{
			m_nHighscore = user->getIntegerForKey("Highscore", 0);
			m_nGoldNumberAll = user->getIntegerForKey("GoldNumber", 0);
			m_nGoldNumberAcc = user->getIntegerForKey("GoldNumberAll", 0);
			m_nReviveNumber = user->getIntegerForKey("ReviveNumber", 0);
			m_nDoubleNumber = user->getIntegerForKey("DoubleNumber", 0);
		}
    
		for (int i = ID_MIN + 1; i < ID_MAX; i++)
		{
			string str = m_mInfoName.at(i) + "Level";
			m_mLevels.at(i) = user->getIntegerForKey(str.c_str(), 1);
		}

		return true;
	}
}

bool PlayerData::saveAllPlayerData()
{
	if (CSC_IOSHelper::GameCenter_isAuthenticated())
	{
		// save data to game center
		CSC_IOSHelper::GameCenter_reportScoreForLeaderboard("Highscore", m_nHighscore);
		CSC_IOSHelper::GameCenter_reportScoreForLeaderboard("GoldNumber", m_nGoldNumberAll);
		CSC_IOSHelper::GameCenter_reportScoreForLeaderboard("GoldNumberAll", m_nGoldNumberAcc);
		CSC_IOSHelper::GameCenter_reportScoreForLeaderboard("ReviveNumber", m_nReviveNumber);
		CSC_IOSHelper::GameCenter_reportScoreForLeaderboard("DoubleNumber", m_nDoubleNumber);
	}

    // save to local data
	UserDefault* user = UserDefault::getInstance();
    user->setIntegerForKey("Highscore", (int)m_nHighscore);
    user->setIntegerForKey("GoldNumber", (int)m_nGoldNumberAll);
    user->setIntegerForKey("GoldNumberAll", (int)m_nGoldNumberAcc);
    user->setIntegerForKey("ReviveNumber", (int)m_nReviveNumber);
    user->setIntegerForKey("DoubleNumber", (int)m_nDoubleNumber);
    for (int i = ID_MIN + 1; i < ID_MAX; i++)
    {
        string str = m_mInfoName.at(i) + "Level";
        user->setIntegerForKey(str.c_str(), m_mLevels.at(i));
    }
    
    return true;
}

bool PlayerData::saveIntPlayerDara(const char* dataName, int data, bool isGameCenter)
{
    if (isGameCenter)
    {
		if (CSC_IOSHelper::GameCenter_isAuthenticated())
		{
			// save data to game center
			CSC_IOSHelper::GameCenter_reportScoreForLeaderboard(dataName, data);
		}
    }
    
    // save to local data
    UserDefault::getInstance()->setIntegerForKey(dataName, data);

    return true;
}

bool PlayerData::saveLevelPlayerData(int id)
{
    string str = m_mInfoName.at(id) + "Level";
    UserDefault::getInstance()->setIntegerForKey(str.c_str(), m_mLevels.at(id));
    return true;
}