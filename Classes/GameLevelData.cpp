#include "GameLevelData.h"

GameLevelData::GameLevelData(void)
{
	m_nLevel = 0;
	m_nStage = 0;
	m_nLevelUpScore = 0;

	m_nPlayerMoveSpeed = 0;

	m_bEnemyDownIsShow = false;
	m_bEnemyDownIsBindItem = false;
	m_nEnemyDownMinHeight = 0;
	m_nEnemyDownMaxHeight = 0;
	m_fEnemyDownMinWidthScale = 0;
	m_fEnemyDownMaxWidthScale = 0;
	m_nEnemyDownMinInterval = 0;
	m_nEnemyDownMaxInterval = 0;

	m_bEnemyUpIsShow = false;
	m_bEnemyUpIsSamePos = false;
	m_nEnemyUpMinHeightOffset = 0;
	m_nEnemyUpMaxHeightOffset = 0;
	m_fEnemyUpMinWidthScale = 0;
	m_fEnemyUpMaxWidthScale = 0;
	m_nEnemyUpMinInterval = 0;
	m_nEnemyUpMaxInterval = 0;

	m_nItemMinMoveSpeed = 0;
	m_nItemMaxMoveSpeed = 0;
	m_nItemMinInterval = 0;
	m_nItemMaxInterval = 0;

	m_nItemAddMapMaxProp = 0;
}

GameLevelData::~GameLevelData(void)
{
	m_mItemAddMap.clear();
}

GameLevelData* GameLevelData::create()
{
	GameLevelData* pRet = new(std::nothrow) GameLevelData();
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

GameLevelData* GameLevelData::create(GameLevelData* gamedata)
{	
	GameLevelData* pRet = new(std::nothrow) GameLevelData();
	if (pRet && pRet->init(gamedata))
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
bool GameLevelData::init()
{  
    bool bRet = false;  
    do   
    {  
        bRet = true;
    } while (0);
    
    return bRet;
}

bool GameLevelData::init(GameLevelData* gamedata)
{
	bool bRet = false;
	do
	{
		m_nLevel = gamedata->getLevel();
		m_nStage = gamedata->getStage();
		m_nLevelUpScore = gamedata->getLevelUpScore();

		m_nPlayerMoveSpeed = gamedata->getPlayerMoveSpeed();

		m_bEnemyDownIsShow = gamedata->getEnemyDownIsShow();
		m_bEnemyDownIsBindItem = gamedata->getEnemyDownIsBindItem();
		m_nEnemyDownMinHeight = gamedata->getEnemyDownMinHeight();
		m_nEnemyDownMaxHeight = gamedata->getEnemyDownMaxHeight();
		m_fEnemyDownMinWidthScale = gamedata->getEnemyDownMinWidthScale();
		m_fEnemyDownMaxWidthScale = gamedata->getEnemyDownMaxWidthScale();
		m_nEnemyDownMinInterval = gamedata->getEnemyDownMinInterval();
		m_nEnemyDownMaxInterval = gamedata->getEnemyDownMaxInterval();

		m_bEnemyUpIsShow = gamedata->getEnemyUpIsShow();
		m_bEnemyUpIsSamePos = gamedata->getEnemyUpIsSamePos();
		m_nEnemyUpMinHeightOffset = gamedata->getEnemyUpMinHeightOffset();
		m_nEnemyUpMaxHeightOffset = gamedata->getEnemyUpMaxHeightOffset();
		m_fEnemyUpMinWidthScale = gamedata->getEnemyUpMinWidthScale();
		m_fEnemyUpMaxWidthScale = gamedata->getEnemyUpMaxWidthScale();
		m_nEnemyUpMinInterval = gamedata->getEnemyUpMinInterval();
		m_nEnemyUpMaxInterval = gamedata->getEnemyUpMaxInterval();

		m_nItemMinMoveSpeed = gamedata->getItemMinMoveSpeed();
		m_nItemMaxMoveSpeed = gamedata->getItemMaxMoveSpeed();
		m_nItemMinInterval = gamedata->getItemMinInterval();
		m_nItemMaxInterval = gamedata->getItemMaxInterval();

		m_nItemAddMapMaxProp = gamedata->getItemAddMapMaxProp();

		for (map<int, int>::const_iterator iter = gamedata->getItemAddMap()->begin(); iter != gamedata->getItemAddMap()->end(); iter++)
		{
			m_mItemAddMap.insert(pair<int, int>(iter->first, iter->second));
		}

		bRet = true;
	} while (0);

	return bRet;
}
