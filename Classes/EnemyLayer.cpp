#include "EnemyLayer.h"

EnemyLayer::EnemyLayer(void)
{
	_gameMediator = GameMediator::getInstance();
	_textLevelUp = NULL;
	_spriteEnemyBar = NULL;
	_levelData = NULL;

	_allEnemysDown.clear();
	_allEnemysUp.clear();
	_allItems.clear();
	_spriteMap.clear();

	m_nEnemyDownMinInterval = 0;
	m_nAddEnemyDownDistance = 0;
	m_nAccEnemyDownDistance = 0;
	m_nAddEnemyUpDistance = 0;
	m_nAccEnemyUpDistance = 0;
	m_nAddItemDistance = 0;
	m_nAccItemDistance = 0;
}


EnemyLayer::~EnemyLayer(void)
{
	_allEnemysDown.clear();
	_allEnemysUp.clear();
	_allItems.clear();
	_spriteMap.clear();
}

bool EnemyLayer::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());
		Size winSize = Director::getInstance()->getWinSize();

		// load csb
		auto rootNode = CSLoader::createNode("EnemyLayer.csb");
		this->addChild(rootNode);

		_spriteEnemyBar = dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_EnemyBar"));
		
		_spriteMap.insert(ITEMTYPE_GOLD, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_GoldCoin")));
		_spriteMap.insert(ITEMTYPE_GUIDELINE, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_GuideLine")));
		_spriteMap.insert(ITEMTYPE_HEART, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_Heart")));
		_spriteMap.insert(ITEMTYPE_ENLARGE, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_Enlarge")));
		_spriteMap.insert(ITEMTYPE_SHRINK, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_Shink")));
		_spriteMap.insert(ITEMTYPE_BOMB, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_Bomb")));
		_spriteMap.insert(ITEMTYPE_HEARTBROKENLEFT, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_HeartBrokenLeft")));
		_spriteMap.insert(ITEMTYPE_HEARTBROKENRIGHT, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_HeartBrokenRight")));
		_spriteMap.insert(ITEMTYPE_HEARTPLUS, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_HeartPlus")));
		_spriteMap.insert(ITEMTYPE_HEARTSECRET, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_HeartSecret")));
		_spriteMap.insert(ITEMTYPE_HEARTGREENTEA, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_HeartGreenTea")));
		_spriteMap.insert(ITEMTYPE_SHIELD, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_Shield")));

		_textLevelUp = dynamic_cast<Text*>(rootNode->getChildByName("Text_LevelUp"));
		_textLevelUp->setVisible(false);

		// set all text
		auto mapGameText = _gameMediator->getGameText();
		_textLevelUp->setString(mapGameText->at(GAMETEXT_ENEMYLAYER_LEVELUP));

		// 读取初始游戏难度
		_levelData = &(*_gameMediator->getGameLevelData())[0];
		_gameMediator->setGameLevel(_levelData->getLevel());

		// 累积移动距离初始化
		float jumpTime = sqrt((float)(2 * _levelData->getEnemyDownMaxHeight()) / (float)GRAVITY) * 2;
		float powerTime = _gameMediator->getPlayerData()->getPowerTime();
		float speed = _levelData->getPlayerMoveSpeed();
		m_nEnemyDownMinInterval = int(speed * (jumpTime + powerTime));
		m_nAddEnemyDownDistance = MAX(_levelData->getEnemyDownInterval(), m_nEnemyDownMinInterval);
		m_nAddEnemyUpDistance = _levelData->getEnemyUpInterval();
		m_nAddItemDistance = _levelData->getItemInterval();
		m_nAccEnemyDownDistance = m_nAccEnemyUpDistance = m_nAccItemDistance = winSize.width * 0.75;

		// 加入第一个敌人
		//this->addEnemyDown(_levelData->getEnemyUpIsSamePos() && _levelData->getEnemyUpIsShow());

		// 加入第一个辅助虚线道具在玩家面前
		Item* item = Item::createItem(_spriteMap.at(ITEMTYPE_GUIDELINE)->getSpriteFrame(), ITEMTYPE_GUIDELINE, _levelData->getItemMoveSpeed());
		item->setPosition(winSize.width * 0.25 + 150, 0);
		this->addChild(item, ZORDER_ENEMYLAYER_ITEM);
		_allItems.pushBack(item);

		this->scheduleUpdate();

		bRet = true;
	} while (0);
	return bRet;
}

void EnemyLayer::update(float dt)
{
	if (_gameMediator->getGameState() == STATE_GAME_RUN)
	{
		// add random item
		m_nAccItemDistance += moveAllItems(dt);
		if (m_nAccItemDistance > m_nAddItemDistance)
		{
			this->addItem();
			m_nAccItemDistance = 0;
			m_nAddItemDistance = _levelData->getItemInterval();
		}
		// add Enemy Up
		bool isWithUp = _levelData->getEnemyUpIsSamePos();
		bool isEnemyUpShow = _levelData->getEnemyUpIsShow();
		m_nAccEnemyUpDistance += moveAllEnemys(&_allEnemysUp, dt);
		if (isEnemyUpShow && !isWithUp)
		{
			if (m_nAccEnemyUpDistance > m_nAddEnemyUpDistance)
			{
				this->addEnemyUp(_levelData->getEnemyUpMoveSpeed());
				m_nAccEnemyUpDistance = 0;
				m_nAddEnemyUpDistance = _levelData->getEnemyUpInterval();
			}
		}
		// add Enemy Down
		if (_levelData->getEnemyDownIsShow())
		{
			m_nAccEnemyDownDistance += moveAllEnemys(&_allEnemysDown, dt);
			if (m_nAccEnemyDownDistance > m_nAddEnemyDownDistance)
			{
				this->addEnemyDown(isWithUp && isEnemyUpShow);
				m_nAccEnemyDownDistance = 0;
				m_nAddEnemyDownDistance = MAX(_levelData->getEnemyDownInterval(), m_nEnemyDownMinInterval);
			}
		}
	}
}

void EnemyLayer::addEnemyDown(bool isWithUp)
{
	Size winSize = Director::getInstance()->getWinSize(); 
	// Enemy Down
	int moveSpeed = _levelData->getEnemyDownMoveSpeed();
	Enemy* enemyDown = Enemy::createEnemy(_spriteEnemyBar->getSpriteFrame(), moveSpeed);
	Size enemyDownSize = enemyDown->getSprite()->getContentSize();
	// random height and width
	int enemyDownHeightNew = _levelData->getEnemyDownHeight();
	int enemyDownWidthNew = _levelData->getEnemyDownWidth(enemyDownSize.width);
	enemyDown->getSprite()->setScaleX(enemyDownWidthNew / enemyDownSize.width);
	enemyDown->getSprite()->setScaleY(enemyDownHeightNew / enemyDownSize.height);
	// set position out of screen
	int positionX = winSize.width + enemyDownWidthNew / 2;
	enemyDown->setPosition(positionX, 0);
	this->addChild(enemyDown, ZORDER_ENEMYLAYER_ENEMY);
	_allEnemysDown.pushBack(enemyDown);

	// Add Gold
	if (_levelData->getEnemyDownIsBindItem())
	{
		Item* item = Item::createItem(_spriteMap.at(ITEMTYPE_GOLD)->getSpriteFrame(), ITEMTYPE_GOLD, moveSpeed);
		int itemHeight = enemyDownHeightNew + 24;
		item->setPosition(positionX, itemHeight);
		this->addChild(item, ZORDER_ENEMYLAYER_ITEM);
		_allItems.pushBack(item);
	}

	// with enemy up
	if (isWithUp)
	{
		this->addEnemyUp(moveSpeed);
	}
}

void EnemyLayer::addEnemyUp(int speed)
{
	Size winSize = Director::getInstance()->getWinSize();
	// Enemy Up
	Enemy* enemyUp = Enemy::createEnemy(_spriteEnemyBar->getSpriteFrame(), speed);
	enemyUp->setAnchorPoint(Point(0.5f, 1));
	enemyUp->getSprite()->setAnchorPoint(Point(0.5f, 1));
	Size enemyUpSize = enemyUp->getSprite()->getContentSize();
	// random height and width
	int enemyUpHeightNew = winSize.height / 2;
	int enemyUpWidthNew = _levelData->getEnemyUpWidth(enemyUpSize.width);
	if (_allEnemysDown.size() > 0)
	{
		Size enemyDownSize = (*_allEnemysDown.rbegin())->getSprite()->getBoundingBox().size;
		enemyUpHeightNew = winSize.height - enemyDownSize.height - _levelData->getEnemyUpHeightOffset();
		if (_levelData->getEnemyUpIsSamePos())
			enemyUpWidthNew = enemyDownSize.width;
	}
	if (!_levelData->getEnemyUpIsSamePos())
	{
		enemyUpHeightNew = MIN(winSize.height / 2 - 50, enemyUpHeightNew);
	}
	enemyUp->getSprite()->setScaleX(enemyUpWidthNew / enemyUpSize.width);
	enemyUp->getSprite()->setScaleY(enemyUpHeightNew / enemyUpSize.height);
	// set position out of screen
	enemyUp->setPosition(winSize.width + enemyUpWidthNew / 2, winSize.height);
	this->addChild(enemyUp, ZORDER_ENEMYLAYER_ENEMY);
	_allEnemysUp.pushBack(enemyUp);
}

void EnemyLayer::addItem()
{
	int maxProp = _levelData->getItemAddMapMaxProp();
	if (maxProp == 0)
		return;

	Size winSize = Director::getInstance()->getWinSize();
	map<int, int>* _itemAddMap = _levelData->getItemAddMap();
	//随机道具种类
	int itemType = ITEMTYPE_MIN;
	int rand = random(1, maxProp); // delete the zero
	int randAcc = 0;
	for (map<int, int>::const_iterator iter = _itemAddMap->begin(); iter != _itemAddMap->end(); iter++)
	{
		randAcc += iter->second;
		if (rand <= randAcc)
		{
			itemType = iter->first;
			break;
		}
	}
	if ((itemType <= ITEMTYPE_MIN) | (itemType >= ITEMTYPE_MAX))
	{
		return;
	}
	//在屏幕最右侧加入道具
	Item* item = Item::createItem(_spriteMap.at(itemType)->getSpriteFrame(), itemType, _levelData->getItemMoveSpeed());
	int minHeight = winSize.height / 4;
	int maxHeight = winSize.height / 2;
	int actualHeight = CCRANDOM_0_1()*(maxHeight - minHeight) + minHeight;
	item->setPosition(winSize.width + item->getSprite()->getContentSize().width / 2, actualHeight);
	this->addChild(item, ZORDER_ENEMYLAYER_ITEM);
	_allItems.pushBack(item);
}

int EnemyLayer::moveAllEnemys(Vector<Enemy*>* pAllEnemys, float dt)
{
	int playerSpeed = _levelData->getPlayerMoveSpeed();
	int moveDistance = 0;
	Vector<Enemy*>::iterator iterEnemy = pAllEnemys->begin();
	while (iterEnemy != pAllEnemys->end())
	{
		if ((*iterEnemy)->getPositionX() < 0)
		{
			(*iterEnemy)->removeFromParent();
			iterEnemy = pAllEnemys->erase(iterEnemy);
		}
		else
		{
			moveDistance = ((*iterEnemy)->getMoveSpeed() + playerSpeed) * dt;
			(*iterEnemy)->setPositionX((*iterEnemy)->getPositionX() - moveDistance);
			iterEnemy++;
		}
	}
	if (moveDistance == 0)
		moveDistance = playerSpeed * dt;
	return moveDistance;
}

int EnemyLayer::moveAllItems(float dt)
{
	int playerSpeed = _levelData->getPlayerMoveSpeed();
	int moveDistance = 0;
	Vector<Item*>::iterator iterItems = _allItems.begin();
	while (iterItems != _allItems.end())
	{
		if ((*iterItems)->getPositionX() < 0)
		{
			(*iterItems)->removeFromParent();
			iterItems = _allItems.erase(iterItems);
		}
		else
		{
			moveDistance = ((*iterItems)->getMoveSpeed() + playerSpeed) * dt;
			(*iterItems)->setPositionX((*iterItems)->getPositionX() - moveDistance);
			iterItems++;
		}
	}
	if (moveDistance == 0)
		moveDistance = playerSpeed * dt;
	return moveDistance;
}

bool EnemyLayer::playerEnemyIntersect(Player* player)
{
	bool isIntersect = false;
	Rect rect1 = Rect(player->getPosition(), player->getSprite()->getBoundingBox().size * player->getScale());
	for (auto obj : _allEnemysDown)
	{
		Rect rect2 = Rect(obj->getPosition(), obj->getSprite()->getBoundingBox().size);
		if (rect2.intersectsRect(rect1))
		{
			if (obj->getIsIntersect() == false)
			{
				obj->setIsIntersect(true);
				isIntersect = true;
			}
		}
	}
	for (auto obj : _allEnemysUp)
	{
		Point pos = obj->getPosition();
		Size size = obj->getSprite()->getBoundingBox().size;
		Rect rect2 = Rect(Point(pos.x, pos.y - size.height), size);
		if (rect2.intersectsRect(rect1))
		{
			if (obj->getIsIntersect() == false)
			{
				obj->setIsIntersect(true);
				isIntersect = true;
			}
		}
	}
	if (isIntersect)
		player->setIsIntersect(isIntersect);
	return isIntersect;
}

int EnemyLayer::playerItemIntersect(Player* player)
{
	Rect rect1 = Rect(player->getPosition(), player->getSprite()->getBoundingBox().size * player->getScale());
	for (auto obj : _allItems)
	{
		Rect rect2 = Rect(obj->getPosition(), obj->getSprite()->getBoundingBox().size);
		if (rect2.intersectsRect(rect1))
		{
			int itemType = obj->getItemType();
			obj->removeFromParent();
			_allItems.eraseObject(obj);
			return itemType;
		}
	}
	return 0;
}

bool EnemyLayer::isJumpOver(Player* player)
{
	bool isJumpOver = false;
	int count = 0;
	int deltaY = 0;
	for (auto obj : _allEnemysDown)
	{
		if (!obj->getIsOver())
		{
			Point pos1 = obj->getPosition();
			Point pos2 = player->getPosition();
			Size size1 = obj->getSprite()->getBoundingBox().size;
			Size size2 = player->getSprite()->getBoundingBox().size * player->getScale();
			if (pos2.x >= pos1.x && !obj->getIsEvluate())
			{
				player->showEvaluation(pos2.y - size1.height);
				obj->setIsEvluate(true);
			}
			else if (pos1.x+size1.width/2 < pos2.x-size2.width/2)
			{
				isJumpOver = true;
				count++;
				obj->setIsOver(true);
			}
		}
	}
	if (isJumpOver)
	{
		player->setIsIntersect(false);
		_gameMediator->getPlayerData()->addScore(count);
	}

	return isJumpOver;
}

void EnemyLayer::increaseGameLevel()
{
	int level = _gameMediator->getGameLevel();
	if (level >= _gameMediator->getGameLevelMax())
	{
		return;
	}
	level++;
	_gameMediator->setGameLevel(level);
	_levelData = &(*_gameMediator->getGameLevelData())[level-1];

	// change the min Interval
	float jumpTime = sqrt((float)(2 * _levelData->getEnemyDownMaxHeight()) / (float)GRAVITY) * 2;
	float powerTime = _gameMediator->getPlayerData()->getPowerTime();
	float speed = _levelData->getPlayerMoveSpeed();
	m_nEnemyDownMinInterval = int(speed * (jumpTime + powerTime));

	// flow the text
	_textLevelUp->setVisible(true);
	_textLevelUp->setOpacity(255);
	_textLevelUp->setPositionY(Director::getInstance()->getWinSize().height / 3);
	_textLevelUp->runAction(Sequence::create(
		MoveTo::create(0.5f, Point(_textLevelUp->getPositionX(), _textLevelUp->getPositionY() + 100)),
		FadeOut::create(0.5f),
		NULL));
}