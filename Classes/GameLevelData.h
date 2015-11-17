#pragma once
#include "CommonHeader.h"

class GameLevelData
{
public:
	GameLevelData(void);
	~GameLevelData(void);

	static GameLevelData* create();
	static GameLevelData* create(GameLevelData* gamedata);

	bool init();
	bool init(GameLevelData* gamedata);

	// random getters
	int getEnemyDownHeight() { return random(m_nEnemyDownMinHeight, m_nEnemyDownMaxHeight); }
	int getEnemyDownWidth(int enemyWidth) { return random(enemyWidth * m_fEnemyDownMinWidthScale, enemyWidth * m_fEnemyDownMaxWidthScale); }
	int getEnemyDownMoveSpeed() { return random(m_nEnemyDownMinMoveSpeed, m_nEnemyDownMaxMoveSpeed); }
	int getEnemyDownInterval() { return random(m_nEnemyDownMinInterval, m_nEnemyDownMaxInterval); }

	int getEnemyUpHeightOffset() { return random(m_nEnemyUpMinHeightOffset, m_nEnemyUpMaxHeightOffset); }
	int getEnemyUpWidth(int enemyWidth) { return random(enemyWidth * m_fEnemyUpMinWidthScale, enemyWidth * m_fEnemyUpMaxWidthScale); }
	int getEnemyUpMoveSpeed() { return random(m_nEnemyUpMinMoveSpeed, m_nEnemyUpMaxMoveSpeed); }
	int getEnemyUpInterval() { return random(m_nEnemyUpMinInterval, m_nEnemyUpMaxInterval); }

	int getItemMoveSpeed() { return random(m_nItemMinMoveSpeed, m_nItemMaxMoveSpeed); }
	int getItemInterval() { return random(m_nItemMinInterval, m_nItemMaxInterval); }

	// getter
	map<int, int>* getItemAddMap() { return &m_mItemAddMap; }

public:
	CC_SYNTHESIZE(int, m_nLevel, Level);
	CC_SYNTHESIZE(int, m_nLevelUpScore, LevelUpScore);

	CC_SYNTHESIZE(int, m_nPlayerMoveSpeed, PlayerMoveSpeed);

	CC_SYNTHESIZE(bool, m_bEnemyDownIsShow, EnemyDownIsShow);
	CC_SYNTHESIZE(bool, m_bEnemyDownIsBindItem, EnemyDownIsBindItem);
	CC_SYNTHESIZE(int, m_nEnemyDownMinHeight, EnemyDownMinHeight);
	CC_SYNTHESIZE(int, m_nEnemyDownMaxHeight, EnemyDownMaxHeight);
	CC_SYNTHESIZE(float, m_fEnemyDownMinWidthScale, EnemyDownMinWidthScale);
	CC_SYNTHESIZE(float, m_fEnemyDownMaxWidthScale, EnemyDownMaxWidthScale);
	CC_SYNTHESIZE(int, m_nEnemyDownMinMoveSpeed, EnemyDownMinMoveSpeed);
	CC_SYNTHESIZE(int, m_nEnemyDownMaxMoveSpeed, EnemyDownMaxMoveSpeed);
	CC_SYNTHESIZE(int, m_nEnemyDownMinInterval, EnemyDownMinInterval);
	CC_SYNTHESIZE(int, m_nEnemyDownMaxInterval, EnemyDownMaxInterval);

	CC_SYNTHESIZE(bool, m_bEnemyUpIsShow, EnemyUpIsShow);
	CC_SYNTHESIZE(bool, m_bEnemyUpIsSamePos, EnemyUpIsSamePos);
	CC_SYNTHESIZE(int, m_nEnemyUpMinHeightOffset, EnemyUpMinHeightOffset);
	CC_SYNTHESIZE(int, m_nEnemyUpMaxHeightOffset, EnemyUpMaxHeightOffset);
	CC_SYNTHESIZE(float, m_fEnemyUpMinWidthScale, EnemyUpMinWidthScale);
	CC_SYNTHESIZE(float, m_fEnemyUpMaxWidthScale, EnemyUpMaxWidthScale);
	CC_SYNTHESIZE(int, m_nEnemyUpMinMoveSpeed, EnemyUpMinMoveSpeed);
	CC_SYNTHESIZE(int, m_nEnemyUpMaxMoveSpeed, EnemyUpMaxMoveSpeed);
	CC_SYNTHESIZE(int, m_nEnemyUpMinInterval, EnemyUpMinInterval);
	CC_SYNTHESIZE(int, m_nEnemyUpMaxInterval, EnemyUpMaxInterval);

	CC_SYNTHESIZE(bool, m_bItemIsCurve, ItemIsCurve);
	CC_SYNTHESIZE(int, m_nItemMinMoveSpeed, ItemMinMoveSpeed);
	CC_SYNTHESIZE(int, m_nItemMaxMoveSpeed, ItemMaxMoveSpeed);
	CC_SYNTHESIZE(int, m_nItemMinInterval, ItemMinInterval);
	CC_SYNTHESIZE(int, m_nItemMaxInterval, ItemMaxInterval);

	CC_SYNTHESIZE(int, m_nItemAddMapMaxProp, ItemAddMapMaxProp);

private:
	map<int, int> m_mItemAddMap;
};

