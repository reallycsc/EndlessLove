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
	int getEnemyDownHeight() { return random(m_iEnemyDownMinHeight, m_iEnemyDownMaxHeight); }
	int getEnemyDownWidth(int enemyWidth) { return random(enemyWidth * m_iEnemyDownMinWidthScale, enemyWidth * m_iEnemyDownMaxWidthScale); }
	int getEnemyDownMoveSpeed() { return random(m_iEnemyDownMinMoveSpeed, m_iEnemyDownMaxMoveSpeed); }
	int getEnemyDownInterval() { return random(m_iEnemyDownMinInterval, m_iEnemyDownMaxInterval); }

	int getEnemyUpHeightOffset() { return random(m_iEnemyUpMinHeightOffset, m_iEnemyUpMaxHeightOffset); }
	int getEnemyUpWidth(int enemyWidth) { return random(enemyWidth * m_iEnemyUpMinWidthScale, enemyWidth * m_iEnemyUpMaxWidthScale); }
	int getEnemyUpMoveSpeed() { return random(m_iEnemyUpMinMoveSpeed, m_iEnemyUpMaxMoveSpeed); }
	int getEnemyUpInterval() { return random(m_iEnemyUpMinInterval, m_iEnemyUpMaxInterval); }

	int getItemMoveSpeed() { return random(m_iItemMinMoveSpeed, m_iItemMaxMoveSpeed); }
	int getItemInterval() { return random(m_iItemMinInterval, m_iItemMaxInterval); }

	// getter
	map<int, int>* getItemAddMap() { return &_itemAddMap; }

public:
	CC_SYNTHESIZE(int, m_iLevel, Level);
	CC_SYNTHESIZE(int, m_iLevelUpScore, LevelUpScore);

	CC_SYNTHESIZE(int, m_iPlayerMoveSpeed, PlayerMoveSpeed);

	CC_SYNTHESIZE(bool, m_bEnemyDownIsShow, EnemyDownIsShow);
	CC_SYNTHESIZE(bool, m_bEnemyDownIsBindItem, EnemyDownIsBindItem);
	CC_SYNTHESIZE(int, m_iEnemyDownMinHeight, EnemyDownMinHeight);
	CC_SYNTHESIZE(int, m_iEnemyDownMaxHeight, EnemyDownMaxHeight);
	CC_SYNTHESIZE(float, m_iEnemyDownMinWidthScale, EnemyDownMinWidthScale);
	CC_SYNTHESIZE(float, m_iEnemyDownMaxWidthScale, EnemyDownMaxWidthScale);
	CC_SYNTHESIZE(int, m_iEnemyDownMinMoveSpeed, EnemyDownMinMoveSpeed);
	CC_SYNTHESIZE(int, m_iEnemyDownMaxMoveSpeed, EnemyDownMaxMoveSpeed);
	CC_SYNTHESIZE(int, m_iEnemyDownMinInterval, EnemyDownMinInterval);
	CC_SYNTHESIZE(int, m_iEnemyDownMaxInterval, EnemyDownMaxInterval);

	CC_SYNTHESIZE(bool, m_bEnemyUpIsShow, EnemyUpIsShow);
	CC_SYNTHESIZE(bool, m_bEnemyUpIsSamePos, EnemyUpIsSamePos);
	CC_SYNTHESIZE(int, m_iEnemyUpMinHeightOffset, EnemyUpMinHeightOffset);
	CC_SYNTHESIZE(int, m_iEnemyUpMaxHeightOffset, EnemyUpMaxHeightOffset);
	CC_SYNTHESIZE(float, m_iEnemyUpMinWidthScale, EnemyUpMinWidthScale);
	CC_SYNTHESIZE(float, m_iEnemyUpMaxWidthScale, EnemyUpMaxWidthScale);
	CC_SYNTHESIZE(int, m_iEnemyUpMinMoveSpeed, EnemyUpMinMoveSpeed);
	CC_SYNTHESIZE(int, m_iEnemyUpMaxMoveSpeed, EnemyUpMaxMoveSpeed);
	CC_SYNTHESIZE(int, m_iEnemyUpMinInterval, EnemyUpMinInterval);
	CC_SYNTHESIZE(int, m_iEnemyUpMaxInterval, EnemyUpMaxInterval);

	CC_SYNTHESIZE(bool, m_bItemIsCurve, ItemIsCurve);
	CC_SYNTHESIZE(int, m_iItemMinMoveSpeed, ItemMinMoveSpeed);
	CC_SYNTHESIZE(int, m_iItemMaxMoveSpeed, ItemMaxMoveSpeed);
	CC_SYNTHESIZE(int, m_iItemMinInterval, ItemMinInterval);
	CC_SYNTHESIZE(int, m_iItemMaxInterval, ItemMaxInterval);

	CC_SYNTHESIZE(int, m_iItemAddMapMaxProp, ItemAddMapMaxProp);

private:
	map<int, int> _itemAddMap;
};

