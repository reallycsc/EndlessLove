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
	map<int, string>* getGameText() { return &_mapGameText; }
	map<int, vector<string>>* getGameStory() { return &_mapGameStory; }
	vector<GameLevelData>* getGameLevelData() { return &_vectorGameLevelData; }

	// common function
	void spriteToGrey(Node* pNode, float percent);
	Widget* replaceNodeWithWidget(Node* node);

private:
	bool loadGameConfigFile();
	bool loadGameTextFile();
	bool loadGameStoryFile();

public:
	CC_SYNTHESIZE(PlayerData*, _playerData, PlayerData);
	CC_SYNTHESIZE(int, m_iGameState, GameState);
	CC_SYNTHESIZE(int, m_iGameLevel, GameLevel);
	CC_SYNTHESIZE(int, m_iGameLevelMax, GameLevelMax);

private:
	vector<GameLevelData>	_vectorGameLevelData;
	map<int, string>	_mapGameText;
	map<int, vector<string>>	_mapGameStory;
	
};


