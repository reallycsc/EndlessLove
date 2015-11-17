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
    static GameMediator* sharedMediator(){ return GameMediator::getInstance(); }

	void initGame();

	void reloadAllConfigFiles();

	// getter function
	map<int, string>* getGameText() { return &m_mGameText; }
	map<int, vector<string>>* getGameStory() { return &m_mGameStory; }
	vector<GameLevelData>* getGameLevelData() { return &m_vGameLevelData; }

	// common function
	// percent: 0 - gray, 1 - color
	void spriteToGray(Node* pNode, float percent);
	Widget* replaceNodeWithWidget(Node* node);

private:
    string& replace_all_distinct(string& str, string& old_value, string& new_value);
    
	bool loadGameConfigFile();
	bool loadGameTextFile();
	bool loadGameStoryFile();

public:
	CC_SYNTHESIZE(PlayerData*, m_pPlayerData, PlayerData);
	CC_SYNTHESIZE(int, m_nGameState, GameState);
	CC_SYNTHESIZE(int, m_nGameLevel, GameLevel);
	CC_SYNTHESIZE(int, m_nGameLevelMax, GameLevelMax);
	CC_SYNTHESIZE(int, m_nGameOverReason, GameOverReason);

private:
	vector<GameLevelData>	m_vGameLevelData;
	map<int, string>	m_mGameText;
	map<int, vector<string>>	m_mGameStory;
	
};


