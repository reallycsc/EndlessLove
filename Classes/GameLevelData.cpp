#include "GameLevelData.h"

GameLevelData::GameLevelData(void)
{
	m_iLevel = 0;
	m_iLevelUpScore = 0;

	m_iPlayerMoveSpeed = 0;

	m_bEnemyDownIsShow = false;
	m_bEnemyDownIsBindItem = false;
	m_iEnemyDownMinHeight = 0;
	m_iEnemyDownMaxHeight = 0;
	m_iEnemyDownMinWidthScale = 0;
	m_iEnemyDownMaxWidthScale = 0;
	m_iEnemyDownMinMoveSpeed = 0;
	m_iEnemyDownMaxMoveSpeed = 0;
	m_iEnemyDownMinInterval = 0;
	m_iEnemyDownMaxInterval = 0;

	m_bEnemyUpIsShow = false;
	m_bEnemyUpIsSamePos = false;
	m_iEnemyUpMinHeightOffset = 0;
	m_iEnemyUpMaxHeightOffset = 0;
	m_iEnemyUpMinWidthScale = 0;
	m_iEnemyUpMaxWidthScale = 0;
	m_iEnemyUpMinMoveSpeed = 0;
	m_iEnemyUpMaxMoveSpeed = 0;
	m_iEnemyUpMinInterval = 0;
	m_iEnemyUpMaxInterval = 0;

	m_bItemIsCurve = false;
	m_iItemMinMoveSpeed = 0;
	m_iItemMaxMoveSpeed = 0;
	m_iItemMinInterval = 0;
	m_iItemMaxInterval = 0;

	m_iItemAddMapMaxProp = 0;
}

GameLevelData::~GameLevelData(void)
{
	_itemAddMap.clear();
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
		m_iLevel = gamedata->getLevel();
		m_iLevelUpScore = gamedata->getLevelUpScore();

		m_iPlayerMoveSpeed = gamedata->getPlayerMoveSpeed();

		m_bEnemyDownIsShow = gamedata->getEnemyDownIsShow();
		m_bEnemyDownIsBindItem = gamedata->getEnemyDownIsBindItem();
		m_iEnemyDownMinHeight = gamedata->getEnemyDownMinHeight();
		m_iEnemyDownMaxHeight = gamedata->getEnemyDownMaxHeight();
		m_iEnemyDownMinWidthScale = gamedata->getEnemyDownMinWidthScale();
		m_iEnemyDownMaxWidthScale = gamedata->getEnemyDownMaxWidthScale();
		m_iEnemyDownMinMoveSpeed = gamedata->getEnemyDownMinMoveSpeed();
		m_iEnemyDownMaxMoveSpeed = gamedata->getEnemyDownMaxMoveSpeed();
		m_iEnemyDownMinInterval = gamedata->getEnemyDownMinInterval();
		m_iEnemyDownMaxInterval = gamedata->getEnemyDownMaxInterval();

		m_bEnemyUpIsShow = gamedata->getEnemyUpIsShow();
		m_bEnemyUpIsSamePos = gamedata->getEnemyUpIsSamePos();
		m_iEnemyUpMinHeightOffset = gamedata->getEnemyUpMinHeightOffset();
		m_iEnemyUpMaxHeightOffset = gamedata->getEnemyUpMaxHeightOffset();
		m_iEnemyUpMinWidthScale = gamedata->getEnemyUpMinWidthScale();
		m_iEnemyUpMaxWidthScale = gamedata->getEnemyUpMaxWidthScale();
		m_iEnemyUpMinMoveSpeed = gamedata->getEnemyUpMinMoveSpeed();
		m_iEnemyUpMaxMoveSpeed = gamedata->getEnemyUpMaxMoveSpeed();
		m_iEnemyUpMinInterval = gamedata->getEnemyUpMinInterval();
		m_iEnemyUpMaxInterval = gamedata->getEnemyUpMaxInterval();

		m_bItemIsCurve = gamedata->getItemIsCurve();
		m_iItemMinMoveSpeed = gamedata->getItemMinMoveSpeed();
		m_iItemMaxMoveSpeed = gamedata->getItemMaxMoveSpeed();
		m_iItemMinInterval = gamedata->getItemMinInterval();
		m_iItemMaxInterval = gamedata->getItemMaxInterval();

		m_iItemAddMapMaxProp = gamedata->getItemAddMapMaxProp();

		for (map<int, int>::const_iterator iter = gamedata->getItemAddMap()->begin(); iter != gamedata->getItemAddMap()->end(); iter++)
		{
			_itemAddMap.insert(pair<int, int>(iter->first, iter->second));
		}

		bRet = true;
	} while (0);

	return bRet;
}
