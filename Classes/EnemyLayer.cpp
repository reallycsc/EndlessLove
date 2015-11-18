#include "EnemyLayer.h"

EnemyLayer::EnemyLayer(void)
{
	m_pGameMediator = GameMediator::getInstance();
	m_pPlayerData = m_pGameMediator->getPlayerData();
	m_pTextLevelUp = NULL;
	m_pSpriteEnemyBar = NULL;
	m_pLevelData = NULL;

	m_vAllEnemysDown.clear();
	m_vAllEnemysUp.clear();
	m_vAllItems.clear();
	m_mSpriteMap.clear();

	m_nEnemyDownMinInterval = 0;
	m_nEnemyDownMaxInterval = 0;
	m_nAddEnemyDownDistance = 0;
	m_nAccEnemyDownDistance = 0;
	m_nAddEnemyUpDistance = 0;
	m_nAccEnemyUpDistance = 0;
	m_nAddItemDistance = 0;
	m_nAccItemDistance = 0;
}


EnemyLayer::~EnemyLayer(void)
{
	m_vAllEnemysDown.clear();
	m_vAllEnemysUp.clear();
	m_vAllItems.clear();
	m_mSpriteMap.clear();
}

bool EnemyLayer::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!Layer::init());
		Size winSize = Director::getInstance()->getWinSize();

		// load csb
		auto rootNode = CSLoader::createNode("EnemyLayer.csb");
		this->addChild(rootNode);

		m_pSpriteEnemyBar = dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_EnemyBar"));
		
		m_mSpriteMap.insert(ITEMTYPE_GOLD, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_GoldCoin")));
		m_mSpriteMap.insert(ITEMTYPE_GUIDELINE, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_GuideLine")));
		m_mSpriteMap.insert(ITEMTYPE_HEART, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_Heart")));
		m_mSpriteMap.insert(ITEMTYPE_ENLARGE, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_Enlarge")));
		m_mSpriteMap.insert(ITEMTYPE_SHRINK, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_Shink")));
		m_mSpriteMap.insert(ITEMTYPE_BOMB, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_Bomb")));
		m_mSpriteMap.insert(ITEMTYPE_HEARTBROKENLEFT, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_HeartBrokenLeft")));
		m_mSpriteMap.insert(ITEMTYPE_HEARTBROKENRIGHT, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_HeartBrokenRight")));
		m_mSpriteMap.insert(ITEMTYPE_HEARTPLUS, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_HeartPlus")));
		m_mSpriteMap.insert(ITEMTYPE_HEARTSECRET, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_HeartSecret")));
		m_mSpriteMap.insert(ITEMTYPE_HEARTGREENTEA, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_HeartGreenTea")));
		m_mSpriteMap.insert(ITEMTYPE_SHIELD, dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Item_Shield")));

		m_pTextLevelUp = dynamic_cast<Text*>(rootNode->getChildByName("Text_LevelUp"));
		m_pTextLevelUp->setVisible(false);

		// set all text
		auto mapGameText = m_pGameMediator->getGameText();
		m_pTextLevelUp->setString(mapGameText->at(GAMETEXT_ENEMYLAYER_LEVELUP));

		// set default game level to level 1
		m_pLevelData = &(*m_pGameMediator->getGameLevelData())[0];
		m_pGameMediator->setGameLevel(m_pLevelData->getLevel());

		// calculate min & max interval for enemy down
		float jumpTime = sqrt((float)(2 * m_pLevelData->getEnemyDownMaxHeight()) / (float)GRAVITY) * 2;
		float powerTime = m_pPlayerData->getPowerTime();
		float speed = m_pLevelData->getPlayerMoveSpeed();
		m_nEnemyDownMinInterval = int(speed * (jumpTime + powerTime));
		m_nEnemyDownMaxInterval = int(winSize.width * 0.5);
		m_nAddEnemyDownDistance = MAX(MIN(m_pLevelData->getEnemyDownInterval(), m_nEnemyDownMaxInterval), m_nEnemyDownMinInterval);
		m_nAddEnemyUpDistance = m_pLevelData->getEnemyUpInterval();
		m_nAddItemDistance = m_pLevelData->getItemInterval();
		m_nAccEnemyDownDistance = m_nAccEnemyUpDistance = m_nAccItemDistance = winSize.width * 0.75;

		// Add first guide line item
		Item* item = Item::createItem(m_mSpriteMap.at(ITEMTYPE_GUIDELINE)->getSpriteFrame(), ITEMTYPE_GUIDELINE, m_pLevelData->getItemMoveSpeed());
		item->setPosition(winSize.width * 0.25 + 150, 0);
		this->addChild(item, ZORDER_ENEMYLAYER_ITEM);
		m_vAllItems.pushBack(item);

		this->scheduleUpdate();

		bRet = true;
	} while (0);
	return bRet;
}

void EnemyLayer::update(float dt)
{
	if (m_pGameMediator->getGameState() == STATE_GAME_RUN)
	{
		// add random item
		m_nAccItemDistance += moveAllItems(dt);
		if (m_nAccItemDistance > m_nAddItemDistance)
		{
			this->addItem();
			m_nAccItemDistance = 0;
			m_nAddItemDistance = m_pLevelData->getItemInterval();
		}
		// add Enemy Up
		bool isWithUp = m_pLevelData->getEnemyUpIsSamePos();
		bool isEnemyUpShow = m_pLevelData->getEnemyUpIsShow();
		m_nAccEnemyUpDistance += moveAllEnemys(&m_vAllEnemysUp, dt);
		if (isEnemyUpShow && !isWithUp)
		{
			if (m_nAccEnemyUpDistance > m_nAddEnemyUpDistance)
			{
				this->addEnemyUp(m_pLevelData->getEnemyUpMoveSpeed());
				m_nAccEnemyUpDistance = 0;
				m_nAddEnemyUpDistance = m_pLevelData->getEnemyUpInterval();
			}
		}
		// add Enemy Down
		if (m_pLevelData->getEnemyDownIsShow())
		{
			m_nAccEnemyDownDistance += moveAllEnemys(&m_vAllEnemysDown, dt);
			if (m_nAccEnemyDownDistance > m_nAddEnemyDownDistance)
			{
				this->addEnemyDown(isWithUp && isEnemyUpShow);
				m_nAccEnemyDownDistance = 0;
				m_nAddEnemyDownDistance = MAX(MIN(m_pLevelData->getEnemyDownInterval(), m_nEnemyDownMaxInterval), m_nEnemyDownMinInterval);
			}
		}
	}
}

void EnemyLayer::addEnemyDown(bool isWithUp)
{
	Size winSize = Director::getInstance()->getWinSize(); 
	// Enemy Down
	int moveSpeed = m_pLevelData->getEnemyDownMoveSpeed();
	Enemy* enemyDown = Enemy::createEnemy(m_pSpriteEnemyBar->getSpriteFrame(), moveSpeed);
	Size enemyDownSize = enemyDown->getBoundingBox().size;
	// random height and width
	int enemyDownHeightNew = m_pLevelData->getEnemyDownHeight();
	int enemyDownWidthNew = m_pLevelData->getEnemyDownWidth(enemyDownSize.width);
	int playerSpeed = m_pLevelData->getPlayerMoveSpeed();
	int playerStrength = m_pPlayerData->getStrength();
	int maxHeight = playerStrength*playerStrength*0.5 / GRAVITY - enemyDownWidthNew*enemyDownWidthNew*GRAVITY*0.125 / (playerSpeed*playerSpeed);
	enemyDown->setScaleX(enemyDownWidthNew / enemyDownSize.width);
	enemyDown->setScaleY(MIN(enemyDownHeightNew, maxHeight) / enemyDownSize.height);
	// set position out of screen
	int positionX = winSize.width + enemyDownWidthNew / 2;
	enemyDown->setPosition(positionX, 0);
	this->addChild(enemyDown, ZORDER_ENEMYLAYER_ENEMY);
	m_vAllEnemysDown.pushBack(enemyDown);

	// Add Gold
	if (m_pLevelData->getEnemyDownIsBindItem())
	{
		Item* item = Item::createItem(m_mSpriteMap.at(ITEMTYPE_GOLD)->getSpriteFrame(), ITEMTYPE_GOLD, moveSpeed);
		int itemHeight = enemyDownHeightNew + 24;
		item->setPosition(positionX, itemHeight);
		this->addChild(item, ZORDER_ENEMYLAYER_ITEM);
		m_vAllItems.pushBack(item);
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
	Enemy* enemyUp = Enemy::createEnemy(m_pSpriteEnemyBar->getSpriteFrame(), speed);
	enemyUp->setAnchorPoint(Point(0.5f, 1));
	Size enemyUpSize = enemyUp->getBoundingBox().size;
	// random height and width
	int enemyUpHeightNew = winSize.height / 2;
	int enemyUpWidthNew = m_pLevelData->getEnemyUpWidth(enemyUpSize.width);
	if (m_vAllEnemysDown.size() > 0)
	{
		Size enemyDownSize = (*m_vAllEnemysDown.rbegin())->getBoundingBox().size;
		enemyUpHeightNew = winSize.height - enemyDownSize.height - m_pLevelData->getEnemyUpHeightOffset();
		if (m_pLevelData->getEnemyUpIsSamePos())
			enemyUpWidthNew = enemyDownSize.width;
	}
	if (!m_pLevelData->getEnemyUpIsSamePos())
	{
		enemyUpHeightNew = MIN(winSize.height / 2 - 50, enemyUpHeightNew);
	}
	enemyUp->setScaleX(enemyUpWidthNew / enemyUpSize.width);
	enemyUp->setScaleY(enemyUpHeightNew / enemyUpSize.height);
	// set position out of screen
	enemyUp->setPosition(winSize.width + enemyUpWidthNew / 2, winSize.height);
	this->addChild(enemyUp, ZORDER_ENEMYLAYER_ENEMY);
	m_vAllEnemysUp.pushBack(enemyUp);
}

void EnemyLayer::addItem()
{
	int maxProp = m_pLevelData->getItemAddMapMaxProp();
	if (maxProp == 0)
		return;

	Size winSize = Director::getInstance()->getWinSize();
	map<int, int>* _itemAddMap = m_pLevelData->getItemAddMap();
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
	Item* item = Item::createItem(m_mSpriteMap.at(itemType)->getSpriteFrame(), itemType, m_pLevelData->getItemMoveSpeed());
	int minHeight = winSize.height / 4;
	int maxHeight = winSize.height / 2;
	int actualHeight = CCRANDOM_0_1()*(maxHeight - minHeight) + minHeight;
	item->setPosition(winSize.width + item->getBoundingBox().size.width / 2, actualHeight);
	this->addChild(item, ZORDER_ENEMYLAYER_ITEM);
	m_vAllItems.pushBack(item);
}

int EnemyLayer::moveAllEnemys(Vector<Enemy*>* pAllEnemys, float dt)
{
	int playerSpeed = m_pLevelData->getPlayerMoveSpeed();
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
	int playerSpeed = m_pLevelData->getPlayerMoveSpeed();
	int moveDistance = 0;
	Vector<Item*>::iterator iterItems = m_vAllItems.begin();
	while (iterItems != m_vAllItems.end())
	{
		if ((*iterItems)->getPositionX() < 0)
		{
			(*iterItems)->removeFromParent();
			iterItems = m_vAllItems.erase(iterItems);
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
	Size size1 = player->getSprite()->getBoundingBox().size;
	Rect rect1 = Rect(Point(player->getPositionX() - size1.width/2, player->getPositionY()), size1 * player->getScale());
	for (auto obj : m_vAllEnemysDown)
	{
		if (rect1.intersectsRect(obj->getBoundingBox()))
		{
			if (obj->getIsIntersect() == false)
			{
				obj->setIsIntersect(true);
				isIntersect = true;
			}
		}
	}
	for (auto obj : m_vAllEnemysUp)
	{
		if (rect1.intersectsRect(obj->getBoundingBox()))
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
	Size size1 = player->getSprite()->getBoundingBox().size;
	Rect rect1 = Rect(Point(player->getPositionX() - size1.width / 2, player->getPositionY()), size1 * player->getScale());
	for (auto obj : m_vAllItems)
	{
		if (rect1.intersectsRect(obj->getBoundingBox()))
		{
			int itemType = obj->getItemType();
			obj->removeFromParent();
			m_vAllItems.eraseObject(obj);
			return itemType;
		}
	}
	return 0;
}

bool EnemyLayer::isJumpOver(PlayerLayer* playerLayer, Player* player)
{
	bool isJumpOver = false;
	int count = 0;
	for (auto obj : m_vAllEnemysDown)
	{
		if (!obj->getIsOver())
		{
			Point pos1 = obj->getPosition();
			Point pos2 = player->getPosition();
			Size size1 = obj->getBoundingBox().size;
			Size size2 = player->getSprite()->getBoundingBox().size * player->getScale();
			if (pos1.x+size1.width/2 < pos2.x-size2.width/2)
			{
				isJumpOver = true;
				count++;
				obj->setIsOver(true);
				if (!obj->getIsEvluate())
				{
					playerLayer->showEvaluation(pos2.y - size1.height);
					obj->setIsEvluate(true);
				}
			}
		}
	}
	if (isJumpOver)
	{
		player->setIsIntersect(false);
		m_pPlayerData->addScore(count);
	}

	return isJumpOver;
}

void EnemyLayer::increaseGameLevel()
{
	int level = m_pGameMediator->getGameLevel();
	if (level >= m_pGameMediator->getGameLevelMax())
	{
		return;
	}
	level++;
	m_pGameMediator->setGameLevel(level);
	m_pLevelData = &(*m_pGameMediator->getGameLevelData())[level-1];

	// change the min Interval
	float jumpTime = sqrt((float)(2 * m_pLevelData->getEnemyDownMaxHeight()) / (float)GRAVITY) * 2;
	float powerTime = m_pPlayerData->getPowerTime();
	float speed = m_pLevelData->getPlayerMoveSpeed();
	m_nEnemyDownMinInterval = int(speed * (jumpTime + powerTime));

	// flow the text
	m_pTextLevelUp->setVisible(true);
	m_pTextLevelUp->setOpacity(255);
	m_pTextLevelUp->setPositionY(Director::getInstance()->getWinSize().height / 3);
	m_pTextLevelUp->runAction(Sequence::create(
		MoveTo::create(0.5f, Point(m_pTextLevelUp->getPositionX(), m_pTextLevelUp->getPositionY() + 100)),
		FadeOut::create(0.5f),
		NULL));
}