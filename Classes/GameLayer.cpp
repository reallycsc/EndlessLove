#include "GameLayer.h"
#include "GameOverLayer.h"

GameLayer::GameLayer(void)
{
	m_pGameMediator = GameMediator::getInstance();
	m_pPlayerData = m_pGameMediator->getPlayerData();
	m_pBackLayer = NULL;
	m_pControlLayer = NULL;
	m_pEnemyLayer = NULL;
	m_pPlayerLayer = NULL;
}


GameLayer::~GameLayer(void)
{
}

bool GameLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();  

	//设定随机数种子
	struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned int time = ((unsigned int)tv.tv_sec) * 1000 + tv.tv_usec / 1000;
	srand(time);

    //建立触摸监听
	auto touchListener = EventListenerTouchOneByOne::create(); 
	//touchListener->setSwallowTouches(false); 
	touchListener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this); 
	touchListener->onTouchMoved = CC_CALLBACK_2(GameLayer::onTouchMoved, this); 
	touchListener->onTouchEnded = CC_CALLBACK_2(GameLayer::onTouchEnded, this); 
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this); 

    /////////////////////////////
    // 3. add your codes below...

	// Set default game data
	m_pGameMediator->initGame();

	// add backlayer
	m_pBackLayer = BackLayer::create();
	this->addChild(m_pBackLayer, ZORDER_GAMELAYER_BACKLAYER);

	// add enemy
	m_pEnemyLayer = EnemyLayer::create();
	this->addChild(m_pEnemyLayer, ZORDER_GAMELAYER_ENEMYLAYER);

	// add player
	m_pPlayerLayer = PlayerLayer::create();
	this->addChild(m_pPlayerLayer, ZORDER_GAMELAYER_PLAYERLAYER);

	// add controllayer
	m_pControlLayer = ControlLayer::create();
	this->addChild(m_pControlLayer, ZORDER_GAMELAYER_CONTROLLAYER);

	this->scheduleUpdate();

    return true;
}

bool GameLayer::onTouchBegan(Touch *touch, Event *event) 
{
	return true;
} 

void GameLayer::onTouchMoved(Touch *touch, Event *event) 
{ 
} 

void GameLayer::onTouchEnded(Touch *touch, Event *event) 
{
	if (m_pGameMediator->getGameState() == STATE_GAME_ENTER)
	{
		m_pControlLayer->gameStart();
		GameLevelData* levelData = &(*m_pGameMediator->getGameLevelData())[m_pGameMediator->getGameLevel() - 1];
		m_pBackLayer->moveBackSprite(levelData->getStage());
	}
}

void GameLayer::update(float dt)
{
	if(m_pGameMediator->getGameState() == STATE_GAME_RUN)
	{
		Player* player = m_pPlayerLayer->getPlayer();
		// intersect reduce heart (when without shield)
		if (!player->getIsShield())
		{
			if (m_pEnemyLayer->playerEnemyIntersect(player))
			{
				this->runAction(Shake::create(0.2f, 3));
				m_pPlayerLayer->addHeartNumber(-1);
			}
		}
		// test item itersection
		this->checkItemIntersect(player);
#if DEBUGFLAG == 0
		// game over if heart is zero
		if (m_pPlayerData->getHeartNumber() <= 0)
		{
			m_pGameMediator->setGameOverReason(GAMEOVER_REASON_NOHEART);
			m_pControlLayer->gameOver();
		}
#endif
		// check if jump over & update score
		do
		{
			if (!m_pEnemyLayer->isJumpOver(m_pPlayerLayer, player))
				break;
			m_pPlayerLayer->updateScoreText();
			// level up when score is correct
			int level = m_pGameMediator->getGameLevel();
			if (level == m_pGameMediator->getGameLevelData()->size()) // last level fo infinity
				break;
			GameLevelData* levelData = &(*m_pGameMediator->getGameLevelData())[level - 1];
			int levelUpScore = levelData->getLevelUpScore();
			if (levelUpScore <= 0) // < 0 for infinity # for DEBUG & incase config bug
				break;
			if ((m_pPlayerData->getScore() % levelUpScore) != 0)
				break;
			m_pEnemyLayer->increaseGameLevel();
			m_pBackLayer->moveBackSprite(levelData->getStage());
		} while (false);
	}
}

void GameLayer::checkItemIntersect(Player* player)
{
	int type = m_pEnemyLayer->playerItemIntersect(m_pPlayerLayer->getPlayer());
	switch (type)
	{
	case 0:
		break;
	case ITEMTYPE_GOLD:
		m_pPlayerLayer->updateGoldNumberText();
		break;
	case ITEMTYPE_HEART:
		m_pPlayerLayer->addHeartNumber(1);
		break;
	case ITEMTYPE_GUIDELINE:
		m_pPlayerLayer->startShowGuideLine(m_pPlayerData->getGuidelineTime());
		break;
	case ITEMTYPE_ENLARGE:
		m_pPlayerLayer->startPlayerEnlarge(m_pPlayerData->getEnlargeTime());
		break;
	case ITEMTYPE_SHRINK:
		m_pPlayerLayer->startPlayerShrink(m_pPlayerData->getShrinkTime());
		break;
	case ITEMTYPE_BOMB:
	{
#if DEBUGFLAG == 0
		if (!player->getIsShield())
		{
			this->runAction(Shake::create(0.2f, 5));
			m_pGameMediator->setGameOverReason(GAMEOVER_REASON_BOMB);
			m_pControlLayer->gameOver();
		}
#endif
		break;
	}
	case ITEMTYPE_HEARTBROKENLEFT:
		m_pPlayerLayer->addHeartNumber(0.5);
		break;
	case ITEMTYPE_HEARTBROKENRIGHT:
		m_pPlayerLayer->addHeartNumber(0.5);
		break;
	case ITEMTYPE_HEARTPLUS:
		m_pPlayerLayer->addHeartNumber(2);
		break;
	case ITEMTYPE_HEARTSECRET:
		if (!player->getIsShield())
		{
			this->runAction(Shake::create(0.2f, 3));
			m_pPlayerLayer->addHeartNumber(-1);
		}
		break;
	case ITEMTYPE_HEARTGREENTEA:
		if (!player->getIsShield())
		{
			this->runAction(Shake::create(0.2f, 3));
			m_pPlayerLayer->addHeartNumber(-2);
		}
		break;
	case ITEMTYPE_SHIELD:
		m_pPlayerLayer->startPlayerShield(m_pPlayerData->getShieldTime());
		break;
	default:
		break;
	}
}