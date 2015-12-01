#pragma once
#include "CommonHeader.h"

typedef struct tagJUMP_TYPE
{
	int level;
	int needGold;
	bool powerUpOnTheGround;
	bool jumpOnTheGround;
	int freeJumpTime;
	string description;
}JUMP_TYPE;

typedef struct tagFLOAT_LEVEL_INFO
{
	int level;
	int needGold;
	float number;
}FLOAT_LEVEL_INFO;

enum
{
	ID_MIN = 0,

	ID_JUMP_TYPE,
	ID_MAXHEART_NUMBER,
	ID_STRENGTH,
	ID_POWER_TIME,
	ID_GUIDELINE_TIME,
	ID_ENLARGE_TIME,
	ID_SHRINK_TIME,
	ID_SHIELD_TIME,

	ID_MAX,
};

class PlayerData
{
public:
	PlayerData(void);
	~PlayerData(void);

	// singlar
	static PlayerData* getInstance();

	bool init();

	void initPlayerData();

	void changeLanguageTo(LanguageType &type);

	void initPlayerHeartNumber();

	void doublePlayerGoldNumber() {
        this->addGoldNumber(m_nGoldNumber);
        this->addDoubleNumber();
    }

	float addHeartNumber(float number) { // return real change number
		float before = m_fHeartNumber;
		m_fHeartNumber += number;
		m_fHeartNumber = MAX(0, MIN(m_fHeartNumber, m_fMaxHeartNumber));
		return m_fHeartNumber - before;
	}
    void addGoldNumber(int number) { m_nGoldNumber += number; }
    void addScore(int number) { m_nScore += number; }
	bool subGoldNumber(int number) {
		if (m_nGoldNumberAll < number) 
			return false;
		else
		{
			m_nGoldNumberAll -= number;
			return true;
		}
	}
    void addReviveNumber() { m_nReviveNumber++; }
    void addDoubleNumber() { m_nDoubleNumber++; }
    
    void finishGameAddGoldNumber();
    void finishGameAddScore();

	// data load & save
	bool loadPlayerData();
	bool saveAllPlayerData(bool isGameCenter = true);

	bool loadPlayerUpgradeConfigFile();

	// getter & setter function
	vector<JUMP_TYPE>* getJumpTypeLevelInfoVector() { return &m_vJumpTypeLevelInfo; }
	vector<FLOAT_LEVEL_INFO>* getLevelInfoVectorFor(int id) { return &m_mLevelInfo.at(id);}
	int getLevelFor(int id) { return m_mLevels.at(id); }
    void setLevelFor(int id, int level);

private:
	bool loadLevelDataForFloat(XMLElement* root, const char* elementName, int id);
	void saveDefaultData(UserDefault* user);
    
    void addCustomEventLisenter(const string suffix, long long* pScore);
    
    bool saveIntPlayerDara(const char* dataName, int data, bool isGameCenter = true);
    bool saveLevelPlayerData(int id);

public:
	CC_SYNTHESIZE(float, m_fHeartNumber, HeartNumber);
	CC_SYNTHESIZE(float, m_fMaxHeartNumber, MaxHeartNumber);
	CC_SYNTHESIZE(bool, m_bPowerUpOnTheGround, IsPowerUpOnTheGround);
	CC_SYNTHESIZE(bool, m_bJumpOnTheGround, IsJumpOnTheGround);
	CC_SYNTHESIZE(int, m_nFreeJumpTime, FreeJumpTime);
	CC_SYNTHESIZE(int, m_nStrength, Strength);
	CC_SYNTHESIZE(float, m_fPowerTime, PowerTime);

	CC_SYNTHESIZE(float, m_fGuidelineTime, GuidelineTime);
	CC_SYNTHESIZE(float, m_fEnlargeTime, EnlargeTime);
	CC_SYNTHESIZE(float, m_fShrinkTime, ShrinkTime);
	CC_SYNTHESIZE(float, m_fShieldTime, ShieldTime);

	CC_SYNTHESIZE(int, m_nScore, Score);
	CC_SYNTHESIZE(long long, m_nHighscore, Highscore);
	CC_SYNTHESIZE(int, m_nGoldNumber, GoldNumber);
	CC_SYNTHESIZE(long long, m_nGoldNumberAll, GoldNumberAll);
    
    CC_SYNTHESIZE(long long, m_nGoldNumberAcc, GoldNumberAcc);
    CC_SYNTHESIZE(long long, m_nReviveNumber, ReviveNumber);
    CC_SYNTHESIZE(long long, m_nDoubleNumber, DoubleNumber);

private:
	LanguageType	m_languageType;
	int	m_nMinStrength;
	float m_fDefaultHeartNumber;

	map<int, int>	m_mLevels;
	map<int, string>	m_mInfoName;
	vector<JUMP_TYPE>	m_vJumpTypeLevelInfo;
	map<int, vector<FLOAT_LEVEL_INFO>>	m_mLevelInfo;
};

