#include "GameLayer.h"
#include "GameOverLayer.h"

GameLayer::GameLayer(void)
{
	_gameMediator = GameMediator::getInstance();
	_playerData = _gameMediator->getPlayerData();
	_controlLayer = NULL;
	_enemyLayer = NULL;
	_playerLayer = NULL;
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
    long long time = ((long long)tv.tv_sec) * 1000 + tv.tv_usec / 1000;
	srand(time);

    //建立触摸监听
	auto touchListener = EventListenerTouchOneByOne::create(); 
	touchListener->setSwallowTouches(true); 
	touchListener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this); 
	touchListener->onTouchMoved = CC_CALLBACK_2(GameLayer::onTouchMoved, this); 
	touchListener->onTouchEnded = CC_CALLBACK_2(GameLayer::onTouchEnded, this); 
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this); 

    /////////////////////////////
    // 3. add your codes below...

	// Set default game data
	_gameMediator->initGame();

	// add scene
	// load csb
	auto rootNode = CSLoader::createNode("BackgroundLayer.csb");
	this->addChild(rootNode);

	//加入player
	_playerLayer = PlayerLayer::create();
	this->addChild(_playerLayer, ZORDER_PLAYER_LAYER);

	//加入enemy
	_enemyLayer = EnemyLayer::create();
	this->addChild(_enemyLayer, ZORDER_ENEMY_LAYER);

	//加入controllayer
	_controlLayer = ControlLayer::create();
	this->addChild(_controlLayer, ZORDER_CONTROL_LAYER);

	this->scheduleUpdate();

    return true;
}

bool GameLayer::onTouchBegan(Touch *touch, Event *event) 
{
	if (_gameMediator->getGameState() == STATE_GAME_RUN)
	{
		//Point point = touch->getLocation();  //获取触摸坐标
		_playerLayer->startPlayerPowerUp();
	}
	return true;
} 

void GameLayer::onTouchMoved(Touch *touch, Event *event) 
{ 
	//Point point = touch->getLocation();  //获取触摸坐标
} 

void GameLayer::onTouchEnded(Touch *touch, Event *event) 
{
	if (_gameMediator->getGameState() == STATE_GAME_ENTER)
	{
		_controlLayer->gameStart();
	}
	else if(_gameMediator->getGameState() == STATE_GAME_RUN)
	{
		_playerLayer->schedulePlayerJump();
		_enemyLayer->setIsPlayerJump(true);
	}
}

void GameLayer::update(float dt)
{
	if(_gameMediator->getGameState() == STATE_GAME_RUN)
	{
		// test item itersection
		this->checkItemIntersect();

		Player* player = _playerLayer->getPlayer();
		if (player->getIsOnTheGround())
		{
			if (_enemyLayer->getIsPlayerJump())
			{
				_enemyLayer->setIsPlayerJump(false);
			}
			return;
		}

		// intersect reduce heart (when without shield)
		if (!player->getIsShield())
		{
			if (_enemyLayer->playerEnemyIntersect(player))
			{
				this->runAction(Shake::create(0.2f, 3));
				_playerLayer->updateHeartNumber(player->addHeartNumber(-1));
			}
		}
		// game over if heart is zero
		if (_playerData->getHeartNumber() <= 0)
		{
			//_controlLayer->gameOver();
			//auto gameOverLayer = GameOverLayer::create();
			//this->addChild(gameOverLayer, ZORDER_GAMEOVER_LAYER);
			//gameOverLayer->showScoreAndStory(GAMEOVER_REASON_NOHEART);
		}
		// check if jump over & update score
		do
		{
			if (!_enemyLayer->isJumpOver(player))
				break;
			_playerLayer->updateScoreText();
			// level up when score is correct
			int level = _gameMediator->getGameLevel();
			if (level == _gameMediator->getGameLevelData()->size())
				break;
			GameLevelData* levelData = &(*_gameMediator->getGameLevelData())[level - 1];
			int levelUpScore = levelData->getLevelUpScore();
			if (levelUpScore <= 0)
				break;
			if ((_playerData->getScore() % levelUpScore) != 0)
				break;
			_enemyLayer->increaseGameLevel();
		} while (false);
	}
}

inline void GameLayer::checkItemIntersect()
{
	Player* player = _playerLayer->getPlayer();
	int itemType = _enemyLayer->playerItemIntersect(_playerLayer->getPlayer());
	switch (itemType)
	{
	case 0:
		break;
	case ITEMTYPE_GOLD:
		_playerData->addGoldNumber(1);
		_playerLayer->updateGoldNumberText();
		break;
	case ITEMTYPE_HEART:
		_playerLayer->updateHeartNumber(_playerLayer->getPlayer()->addHeartNumber(1));
		break;
	case ITEMTYPE_GUIDELINE:
		_playerLayer->startShowGuideLine(_playerData->getGuidelineTime());
		break;
	case ITEMTYPE_ENLARGE:
		_playerLayer->startPlayerEnlarge(_playerData->getEnlargeTime());
		break;
	case ITEMTYPE_SHRINK:
		_playerLayer->startPlayerShrink(_playerData->getShrinkTime());
		break;
	case ITEMTYPE_BOMB:
	{
		if (!player->getIsShield())
		{
			this->runAction(Shake::create(0.2f, 5));
			_controlLayer->gameOver();
			auto gameOverLayer = GameOverLayer::create();
			this->addChild(gameOverLayer, ZORDER_GAMEOVER_LAYER);
			gameOverLayer->showScoreAndStory(GAMEOVER_REASON_BOMB);
		}
		break;
	}
	case ITEMTYPE_HEARTBROKENLEFT:
		_playerLayer->updateHeartNumber(_playerLayer->getPlayer()->addHeartNumber(0.5));
		break;
	case ITEMTYPE_HEARTBROKENRIGHT:
		_playerLayer->updateHeartNumber(_playerLayer->getPlayer()->addHeartNumber(0.5));
		break;
	case ITEMTYPE_HEARTPLUS:
		_playerLayer->updateHeartNumber(_playerLayer->getPlayer()->addHeartNumber(2));
		break;
	case ITEMTYPE_HEARTSECRET:
		if (!player->getIsShield())
		{
			this->runAction(Shake::create(0.2f, 3));
			_playerLayer->updateHeartNumber(_playerLayer->getPlayer()->addHeartNumber(-1));
		}
		break;
	case ITEMTYPE_HEARTGREENTEA:
		if (!player->getIsShield())
		{
			this->runAction(Shake::create(0.2f, 3));
			_playerLayer->updateHeartNumber(_playerLayer->getPlayer()->addHeartNumber(-2));
		}
		break;
	case ITEMTYPE_SHIELD:
		_playerLayer->startPlayerShield(_playerData->getShieldTime());
		break;
	default:
		break;
	}
}