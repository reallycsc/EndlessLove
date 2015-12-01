#pragma once
#include "CommonHeader.h"
#include "PlayerData.h"
#include "GameLevelData.h"

class GameMediator
{
public:
	GameMediator();
	~GameMediator();
	bool init();
	// singlar
    static GameMediator* getInstance();

	void initGame();

	void reloadAllConfigFiles();

	void increaseReviveNumber() {
        m_nReviveNumber++;
        m_pPlayerData->addReviveNumber();
    }

	void changeLanguageTo(LanguageType &type);

	// getter function
	map<string, string>* getGameText() { return &m_mGameText; }
	vector<GameLevelData>* getGameLevelData() { return &m_vGameLevelData; }

	// common function
	// percent: 0 - gray, 1 - color
	static void spriteToGray(Node* pNode, float percent);

	static void setLineWrap(ScrollView* scrollView, Text* text);
    
private:
    string& replace_all_distinct(string& str, string& old_value, string& new_value);
    
	bool loadGameConfigFile();
	bool loadGameTextFile();

public:
	CC_SYNTHESIZE(LanguageType, m_languageType, LanguageType);

	CC_SYNTHESIZE(PlayerData*, m_pPlayerData, PlayerData);
	CC_SYNTHESIZE(int, m_nGameState, GameState);
	CC_SYNTHESIZE(int, m_nGameLevel, GameLevel);
	CC_SYNTHESIZE(int, m_nGameLevelMax, GameLevelMax);

	// Purchase point
	CC_SYNTHESIZE(bool, m_bAd, IsAd);
	CC_SYNTHESIZE(bool, m_bGuidelineForever, IsGuidelineForever);

	// Ad point
	CC_SYNTHESIZE(int, m_nReviveNumber, ReviveNumber);

private:
	vector<GameLevelData>	m_vGameLevelData;
	map<string, string>	m_mGameText;
};


