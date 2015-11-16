#include "PlayerLayer.h"
#include "GameMediator.h"

PlayerLayer::PlayerLayer(void)
{
	_gameMediator = GameMediator::getInstance();
	_playerData = _gameMediator->getPlayerData();
	_spriteGuideLine = NULL;

	_textScore = NULL;
	_textGoldNum = NULL;
	_spriteGold = NULL;
	_nodeGoldNum = NULL;
	_spriteHeart = NULL;
	_spriteHalfHeartLeft = NULL;
	_spriteHalfHeartRight = NULL;

	_nodeHeart = NULL;
	_textHeartNumber = NULL;
	_textGood = NULL;
	_textGreat = NULL;
	_textPerfect = NULL;

	_vectorSpriteHeart.clear();
	_mapCountDown.clear();
	_vectorCountDown.clear();

	_mapCurCountDownTime.clear();
	_mapMaxCountDownTime.clear();
}


PlayerLayer::~PlayerLayer(void)
{
	_vectorSpriteHeart.clear();
	_mapCountDown.clear();
	_vectorCountDown.clear();
	_mapCurCountDownTime.clear();
	_mapMaxCountDownTime.clear();
}

bool PlayerLayer::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());
		Size winSize = Director::getInstance()->getWinSize();

		// Load csb
		auto rootNode = CSLoader::createNode("PlayerLayer.csb");
		this->addChild(rootNode);

		// Add Player
		_player = Player::create();
		_player->setPosition(winSize.width / 4, 0);
		this->addChild(_player, ZORDER_PLAYERLAYER_PLAYER);

		Node* nodePlayer = dynamic_cast<Node*>(rootNode->getChildByName("Node_Player"));
		_nodeHeart = dynamic_cast<Node*>(nodePlayer->getChildByName("Node_Heart"));
		_nodeHeart->setVisible(false);
		_textHeartNumber = dynamic_cast<Text*>(_nodeHeart->getChildByName("Text_HeartNumber"));
		_textGood = dynamic_cast<Text*>(nodePlayer->getChildByName("Text_Good"));
		_textGood->setVisible(false);
		_textGreat = dynamic_cast<Text*>(nodePlayer->getChildByName("Text_Great"));
		_textGreat->setVisible(false);
		_textPerfect = dynamic_cast<Text*>(nodePlayer->getChildByName("Text_Perfect"));
		_textPerfect->setVisible(false);

		// Add text
		_textScore = dynamic_cast<Text*>(rootNode->getChildByName("Text_Score"));
		_nodeGoldNum = dynamic_cast<Node*>(rootNode->getChildByName("Node_GoldNumber"));
		_textGoldNum = dynamic_cast<Text*>(_nodeGoldNum->getChildByName("Text_GoldNumber"));
		_spriteGold = dynamic_cast<Sprite*>(_nodeGoldNum->getChildByName("Sprite_GoldCoin"));
		_textHeartNum = dynamic_cast<Text*>(rootNode->getChildByName("Text_HeartNumber"));
		_textHeartNum->setVisible(false);

		// Add heart
		_spriteHeart = dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Heart"));
		_spriteHalfHeartLeft = dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_HeartBrokenLeft"));
		_spriteHalfHeartLeft->setGlobalZOrder(ZORDER_PLAYERLAYER_HEARTHALF);
		_spriteHalfHeartRight = dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_HeartBrokenRight"));
		_spriteHalfHeartLeft->setGlobalZOrder(ZORDER_PLAYERLAYER_HEARTHALF);

		auto spriteGrey = dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_HeartGrey"));
		auto spriteLeftGrey = dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_HeartLeftGrey"));
		float maxHeartNumber = _playerData->getMaxHeartNumber();
		int posY = winSize.height - 10;
		int i = 0;
		while(maxHeartNumber - i >= 1)
		{
			Sprite* sprite = Sprite::createWithSpriteFrame(spriteGrey->getSpriteFrame());
			sprite->setAnchorPoint(spriteGrey->getAnchorPoint());
			sprite->setPosition(10 + i * 60, posY);
			this->addChild(sprite, ZORDER_PLAYERLAYER_HEARTGREY);
			i++;
		}
		if (maxHeartNumber - i > 0)
		{
			Sprite* sprite = Sprite::createWithSpriteFrame(spriteLeftGrey->getSpriteFrame());
			sprite->setAnchorPoint(spriteLeftGrey->getAnchorPoint());
			sprite->setPosition(10 + floor(maxHeartNumber) * 60, posY);
			this->addChild(sprite, ZORDER_PLAYERLAYER_HEARTGREY);
		}

		for (int i = 0; i < _playerData->getHeartNumber(); i++)
		{
			Sprite* sprite = Sprite::createWithSpriteFrame(_spriteHeart->getSpriteFrame());
			sprite->setAnchorPoint(_spriteHeart->getAnchorPoint());
			sprite->setPosition(10 + i * 60, posY);
			_vectorSpriteHeart.pushBack(sprite);
			this->addChild(sprite, ZORDER_PLAYERLAYER_HEART);
		}

		// 加入辅助虚线
		_spriteGuideLine = dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_GuideLine"));
		_spriteGuideLine->setVisible(false);

		// 加入倒计时指示
		Node* nodeGuideLine = dynamic_cast<Node*>(rootNode->getChildByName("Node_GuideLineCountDown"));
		Node* nodeEnlarge = dynamic_cast<Node*>(rootNode->getChildByName("Node_EnlargeCountDown"));
		Node* nodeShrink = dynamic_cast<Node*>(rootNode->getChildByName("Node_ShrinkCountDown"));
		Node* nodeShield = dynamic_cast<Node*>(rootNode->getChildByName("Node_ShieldCountDown"));
		_mapCountDown.insert(COUNTDOWN_GUIDELINE, nodeGuideLine);
		_mapCountDown.insert(COUNTDOWN_ENLARGE, nodeEnlarge);
		_mapCountDown.insert(COUNTDOWN_SHRINK, nodeShrink);
		_mapCountDown.insert(COUNTDOWN_SHIELD, nodeShield);
		for (auto iter : _mapCountDown)
		{
			iter.second->setVisible(false);
		}

		// set all text
		auto mapGameText = GameMediator::getInstance()->getGameText();
		_textGood->setString(mapGameText->at(GAMETEXT_PLAYER_GOOD));
		_textGreat->setString(mapGameText->at(GAMETEXT_PLAYER_GREAT));
		_textPerfect->setString(mapGameText->at(GAMETEXT_PLAYER_PERFECT));

		_textScore->setString(String::createWithFormat("%s%d",
			mapGameText->at(GAMETEXT_PLAYERLAYER_SCORE).c_str(),
			_playerData->getScore())->getCString());
		dynamic_cast<Text*>(nodeGuideLine->getChildByName("Text_CountDown"))->setString(String::createWithFormat("%s%.1f",
			mapGameText->at(GAMETEXT_PLAYERLAYER_GUIDELINE).c_str(),
			10)->getCString());
		dynamic_cast<Text*>(nodeEnlarge->getChildByName("Text_CountDown"))->setString(String::createWithFormat("%s%.1f",
			mapGameText->at(GAMETEXT_PLAYERLAYER_ENLARGE).c_str(),
			10)->getCString());
		dynamic_cast<Text*>(nodeShrink->getChildByName("Text_CountDown"))->setString(String::createWithFormat("%s%.1f",
			mapGameText->at(GAMETEXT_PLAYERLAYER_SHRINK).c_str(),
			10)->getCString());
		dynamic_cast<Text*>(nodeShield->getChildByName("Text_CountDown"))->setString(String::createWithFormat("%s%.1f",
			mapGameText->at(GAMETEXT_PLAYERLAYER_SHIELD).c_str(),
			10)->getCString());

		this->scheduleUpdate();

		bRet = true;
	} while (0);
	return bRet;
}

// schedule functions
void PlayerLayer::update(float dt)
{
	if (_gameMediator->getGameState() == STATE_GAME_RUN)
	{
		// 蓄力中调整辅助虚线的位置
		if (_spriteGuideLine->isVisible() == true)
		{
			if (_player->getIsPowerUp() == true)
			{
				auto speed = _player->getCurPower() * _playerData->getStrength() / MAXPOWER;
				int positionY = (speed * speed) / (2 * GRAVITY);
				_spriteGuideLine->setPositionY(positionY);
			}
		}
	}
}

void PlayerLayer::startCountDown(float dt, int countDownType, int textType)
{
	if (countDownType <= COUNTDOWN_MIN || countDownType >= COUNTDOWN_MAX)
		return;
	if (_gameMediator->getGameState() == STATE_GAME_RUN)
	{
		float curTime = _mapCurCountDownTime.at(countDownType);
		Node* node = _mapCountDown.at(countDownType);
		curTime -= dt;
		_mapCurCountDownTime.at(countDownType) = curTime;
		if (curTime <= 0)
		{
			_vectorCountDown.eraseObject(node, true);
			node->setVisible(false);
			this->setCountDownPosition();
			switch (countDownType)
			{
			case COUNTDOWN_GUIDELINE:
				_spriteGuideLine->runAction(Sequence::create(
					FadeOut::create(1.0f),
					CallFuncN::create(CC_CALLBACK_1(PlayerLayer::guideLineFadeOutFinished, this)),
					NULL));
				break;
			case COUNTDOWN_ENLARGE:
				_player->runAction(ScaleTo::create(0.5f, 1));
				break;
			case COUNTDOWN_SHRINK:
				_player->runAction(ScaleTo::create(0.5f, 1));
				break;
			default:
				break;
			}
		}
		dynamic_cast<Text*>(node->getChildByName("Text_CountDown"))->setString(String::createWithFormat("%s%.1f", 
			_gameMediator->getGameText()->at(textType).c_str(),
			curTime)->getCString());
		dynamic_cast<LoadingBar*>(node->getChildByName("LoadingBar_CountDown"))->setPercent(100 * curTime / _mapMaxCountDownTime.at(countDownType));
	}
}

void PlayerLayer::guideLineFadeOutFinished(Node* pSender)
{
	pSender->setVisible(false);
}

// update score text function
void PlayerLayer::updateScoreText()
{
	_textScore->setString(String::createWithFormat("%s%d", 
		_gameMediator->getGameText()->at(GAMETEXT_PLAYERLAYER_SCORE).c_str(), 
		_playerData->getScore())->getCString());
}

void PlayerLayer::updateGoldNumberText()
{
	// Gold animation from player to icon top-left
	Sprite* sprite = Sprite::createWithSpriteFrame(_spriteGold->getSpriteFrame());
	sprite->setAnchorPoint(Point(0, 0.5));
	Size size = _player->getBoundingBox().size;
	sprite->setPosition(_player->getPositionX(), _player->getPositionY() + size.height);
	sprite->runAction(Sequence::create(
		EaseIn::create(MoveTo::create(0.3, _nodeGoldNum->getPosition() + _spriteGold->getPosition()), 2),
		CallFuncN::create(CC_CALLBACK_1(PlayerLayer::goldMoveFinished, this)),
		NULL
		));
	this->addChild(sprite, ZORDER_PLAYERLAYER_FLOWINGGOLD);
}

void PlayerLayer::goldMoveFinished(Node* pSender)
{
	pSender->removeFromParent();
	_playerData->addGoldNumber(1);
	_textGoldNum->setString(String::createWithFormat("%d", _playerData->getGoldNumber())->getCString());
}

inline void PlayerLayer::createProgressAction(Sprite* obj, float duration, int type)
{
	obj->setVisible(false);
	ProgressTimer* progress = ProgressTimer::create(obj);
	progress->setType(ProgressTimer::Type::BAR);
	progress->setMidpoint(Point(0.5, 0));
	progress->setBarChangeRate(Point(0, 1));
	progress->setAnchorPoint(obj->getAnchorPoint());
	progress->setPosition(obj->getPosition());
	progress->runAction(Sequence::create(
		ProgressTo::create(duration, 100),
		CallFuncN::create(CC_CALLBACK_1(PlayerLayer::progressToFinished, this, obj, type)),
		NULL));
	this->addChild(progress, ZORDER_PLAYERLAYER_HEARTPROGRESS);
}

void PlayerLayer::progressToFinished(Node* pSender, Sprite* obj, int type)
{
	pSender->removeFromParent();

	switch (type)
	{
	case TYPE_HEARTLEFT: // sprite left
		_spriteHalfHeartLeft->setVisible(true);
		_spriteHalfHeartLeft->setPosition(obj->getPosition());
		obj->removeFromParent();
		break;
	case TYPE_HEART: // sprite heart
		obj->setVisible(true);
		break;
	case TYPE_HEARTRIGHT: // sprite right
	{
		obj->removeFromParent();
		_spriteHalfHeartLeft->setVisible(false);
		Sprite* sprite = Sprite::createWithSpriteFrame(_spriteHeart->getSpriteFrame());
		sprite->setAnchorPoint(_spriteHeart->getAnchorPoint());
		sprite->setPosition(10 + int(_playerData->getHeartNumber() - 1) * 60, Director::getInstance()->getWinSize().height - 10);
		this->addChild(sprite, ZORDER_PLAYERLAYER_HEART);
		_vectorSpriteHeart.pushBack(sprite);
		break;
	}
	default:
		break;
	}
}

void PlayerLayer::addHeartNumber(float number) // return heart number before change
{
	// heart number increase
	float realNumber = _gameMediator->getPlayerData()->addHeartNumber(number);
	// change player to color
	if (realNumber != 0)
	{
		_player->changePlayerColorToGrey();
	}
	// show flowing sprite
	if (int(number * 10) % 10 != 0)
	{
		if (number >= 0)
			_textHeartNumber->setString(String::createWithFormat("+%.1f", number)->getCString());
		else
			_textHeartNumber->setString(String::createWithFormat("%.1f", number)->getCString());
	}
	else
	{
		if (number >= 0)
			_textHeartNumber->setString(String::createWithFormat("+%d", int(number))->getCString());
		else
			_textHeartNumber->setString(String::createWithFormat("%d", int(number))->getCString());
	}
	_nodeHeart->setVisible(true);
	_nodeHeart->setOpacity(255);
	_nodeHeart->setPosition(_player->getPositionX(), _player->getPositionY() + _player->getBoundingBox().size.height + 20);
	_nodeHeart->runAction(Sequence::create(
		MoveTo::create(0.5f, Point(_nodeHeart->getPositionX(), _nodeHeart->getPositionY() + 100)),
		FadeOut::create(0.5f),
		NULL));

	this->updateHeartNumber(realNumber);
}

void PlayerLayer::updateHeartNumber(float addNumber)
{
	if (addNumber == 0)
		return;
	Size winSize = Director::getInstance()->getWinSize();
	int posY = winSize.height - 10;

	float heartNumber = _playerData->getHeartNumber();
	_textHeartNum->setString(String::createWithFormat("X %.1f", heartNumber)->getCString());
	int iterger = floor(heartNumber);
	float heartNumberBefore = heartNumber - addNumber;
	int decimalBefore = int(heartNumberBefore * 10) % 10;

	if (addNumber >= 0)
	{
		// n.5 + 0.5
		if (decimalBefore != 0)
		{
			//Sprite* sprite = Sprite::createWithSpriteFrame(_spriteHalfHeartRight->getSpriteFrame());
			//sprite->setAnchorPoint(_spriteHalfHeartRight->getAnchorPoint());
			//sprite->setPosition(10 + (iterger - 1) * 60 + 21, posY);
			//this->addChild(sprite, ZORDER_PLAYERLAYER_HEARTHALF);

			Sprite* sprite = Sprite::createWithSpriteFrame(_spriteHeart->getSpriteFrame());
			sprite->setAnchorPoint(_spriteHeart->getAnchorPoint());
			sprite->setPosition(10 + floor(heartNumberBefore) * 60, posY);
			this->addChild(sprite, ZORDER_PLAYERLAYER_HEART);
			_vectorSpriteHeart.pushBack(sprite);
			_spriteHalfHeartLeft->setVisible(false);

			addNumber -= 0.5;
			//this->createProgressAction(sprite, 0.5, TYPE_HEARTRIGHT);
		}
		// n + m
		while (addNumber >= 1)
		{
			Sprite* sprite = Sprite::createWithSpriteFrame(_spriteHeart->getSpriteFrame());
			sprite->setAnchorPoint(_spriteHeart->getAnchorPoint());
			sprite->setPosition(10 + _vectorSpriteHeart.size() * 60, posY);
			this->addChild(sprite, ZORDER_PLAYERLAYER_HEART);
			_vectorSpriteHeart.pushBack(sprite);
			addNumber -= 1;
			//this->createProgressAction(sprite, 0.5, TYPE_HEART);
		}
		// n + 0.5
		if (addNumber > 0)
		{
			//Sprite* sprite = Sprite::createWithSpriteFrame(_spriteHalfHeartLeft->getSpriteFrame());
			//sprite->setAnchorPoint(_spriteHalfHeartLeft->getAnchorPoint());
			//sprite->setPosition(10 + iterger * 60, posY);
			//this->addChild(sprite, ZORDER_PLAYERLAYER_HEARTHALF);

			_spriteHalfHeartLeft->setVisible(true);
			_spriteHalfHeartLeft->setPosition(10 + iterger * 60, posY);
			//this->createProgressAction(sprite, 0.5, TYPE_HEARTLEFT);
		}
	}
	else
	{	
		// n.5 - 0.5
		if (decimalBefore != 0)
		{
			Sprite* sprite = Sprite::createWithSpriteFrame(_spriteHalfHeartLeft->getSpriteFrame());
			sprite->setAnchorPoint(_spriteHalfHeartLeft->getAnchorPoint());
			sprite->setPosition(_spriteHalfHeartLeft->getPosition());
			sprite->runAction(Sequence::create(
				Spawn::create(
					MoveTo::create(0.5f, Point(sprite->getPositionX(), sprite->getPositionY() - 100)),
					FadeOut::create(0.5f),
					NULL),
				CallFuncN::create(CC_CALLBACK_1(PlayerLayer::heartFadeOutFinished, this)),
				NULL));
			this->addChild(sprite, ZORDER_PLAYERLAYER_HEARTPROGRESS);
			_spriteHalfHeartLeft->setVisible(false);
			addNumber += 0.5;
		}
		// n - m
		while (addNumber <= -1 && _vectorSpriteHeart.size() > 0)
		{
			Sprite* obj = *_vectorSpriteHeart.rbegin();
			obj->runAction(Sequence::create(
				Spawn::create(
					MoveTo::create(0.5f, Point(obj->getPositionX(), obj->getPositionY() - 100)),
					FadeOut::create(0.5f),
					NULL),
				CallFuncN::create(CC_CALLBACK_1(PlayerLayer::heartFadeOutFinished, this)),
				NULL));
			_vectorSpriteHeart.popBack();
			addNumber += 1;
		}
		if (addNumber < 0)
		{
			// n - 0.5
			if (_vectorSpriteHeart.size() > 0)
			{
				(*_vectorSpriteHeart.rbegin())->removeFromParent();
				_vectorSpriteHeart.popBack();
			}
			Sprite* sprite = Sprite::createWithSpriteFrame(_spriteHalfHeartRight->getSpriteFrame());
			sprite->setAnchorPoint(_spriteHalfHeartRight->getAnchorPoint());
			sprite->setPosition(10 + iterger * 60 + 21, posY);
			sprite->runAction(Sequence::create(
				Spawn::create(
					MoveTo::create(0.5f, Point(sprite->getPositionX(), sprite->getPositionY() - 100)),
					FadeOut::create(0.5f),
					NULL),
				CallFuncN::create(CC_CALLBACK_1(PlayerLayer::heartFadeOutFinished, this)),
				NULL));
			this->addChild(sprite, ZORDER_PLAYERLAYER_HEARTPROGRESS);
			_spriteHalfHeartRight->setVisible(false);

			_spriteHalfHeartLeft->setVisible(true);
			_spriteHalfHeartLeft->setPosition(10 + iterger * 60, posY);
		}
	}
}

void PlayerLayer::heartFadeOutFinished(Node* pSender)
{
	pSender->removeFromParent();
}

// player functions
void PlayerLayer::startPlayerPowerUp()
{
	_player->startPowerUp();
	if (_spriteGuideLine->isVisible() == true)
	{
		// 显示辅助虚线
		Size winSize = Director::getInstance()->getWinSize();
		_spriteGuideLine->setPosition(winSize.width / 2, 0);
	}
}

void PlayerLayer::schedulePlayerJump()
{
	_player->scheduleJump();
}

void PlayerLayer::showEvaluation(int y)
{
	if (_player->getIsIntersect())
		return;
	if (y < 10) // Perfect
	{
		_textPerfect->setScale(1);
		_textPerfect->setVisible(true);
		_textPerfect->setOpacity(255);
		_textPerfect->setPosition(Point(_player->getPositionX(), _player->getPositionY() + _player->getBoundingBox().size.height + 70));
		_textPerfect->runAction(Sequence::create(
			Spawn::create(
				ScaleTo::create(0.5f, 2.0f),
				MoveTo::create(0.5f, Point(_textPerfect->getPositionX(), _textPerfect->getPositionY() + 100)),
				NULL),
			FadeOut::create(0.5f),
			NULL));
	}
	else if (y >= 10 && y < 50) // Great
	{
		_textGreat->setScale(1);
		_textGreat->setVisible(true);
		_textGreat->setOpacity(255);
		_textGreat->setPosition(Point(_player->getPositionX(), _player->getPositionY() + _player->getBoundingBox().size.height + 70));
		_textGreat->runAction(Sequence::create(
			Spawn::create(
				ScaleTo::create(0.5f, 2.0f),
				MoveTo::create(0.5f, Point(_textPerfect->getPositionX(), _textPerfect->getPositionY() + 100)),
				NULL),
			FadeOut::create(0.5f),
			NULL));
	}
	else // Good
	{
		_textGood->setScale(1);
		_textGood->setVisible(true);
		_textGood->setOpacity(255);
		_textGood->setPosition(Point(_player->getPositionX(), _player->getPositionY() + _player->getBoundingBox().size.height + 70));
		_textGood->runAction(Sequence::create(
			Spawn::create(
				ScaleTo::create(0.5f, 2.0f),
				MoveTo::create(0.5f, Point(_textPerfect->getPositionX(), _textPerfect->getPositionY() + 100)),
				NULL),
			FadeOut::create(0.5f),
			NULL));
	}
}

// item use functions
void PlayerLayer::startShowGuideLine(float duration)
{
	Size winSize = Director::getInstance()->getWinSize();
	_spriteGuideLine->setPosition(winSize.width / 2, 0);
	_spriteGuideLine->stopAllActions();
	_spriteGuideLine->setOpacity(255);
	_spriteGuideLine->setVisible(true);

	_mapCurCountDownTime[COUNTDOWN_GUIDELINE] = duration;
	_mapMaxCountDownTime[COUNTDOWN_GUIDELINE] = duration;
	Node* node = _mapCountDown.at(COUNTDOWN_GUIDELINE);
	if (_vectorCountDown.find(node) == _vectorCountDown.end())
	{
		node->setVisible(true);
		_vectorCountDown.pushBack(node);
		this->setCountDownPosition();
	}
	
	auto scheduler = Director::getInstance()->getScheduler();
	scheduler->unschedule("guideLineCountDown", this);
	scheduler->schedule(CC_CALLBACK_1(PlayerLayer::startCountDown, this, COUNTDOWN_GUIDELINE, GAMETEXT_PLAYERLAYER_GUIDELINE), 
		this, 0.1f, int(duration * 10), 0, false, "guideLineCountDown");
}

void PlayerLayer::startPlayerEnlarge(float duration)
{
	_player->runAction(ScaleTo::create(0.5f, 2));
	_mapCurCountDownTime[COUNTDOWN_ENLARGE] = duration;
	_mapMaxCountDownTime[COUNTDOWN_ENLARGE] = duration;
	auto scheduler = Director::getInstance()->getScheduler();
	// find shrink count down and delete it
	Node* nodeShrink = _mapCountDown.at(COUNTDOWN_SHRINK);
	_mapCurCountDownTime[COUNTDOWN_SHRINK] = 0;
	_mapMaxCountDownTime[COUNTDOWN_SHRINK] = 0;
	auto iter = _vectorCountDown.find(nodeShrink);
	if (iter != _vectorCountDown.end())
	{
		scheduler->unschedule("shrinkCountDown", this);
		nodeShrink->setVisible(false);
		_vectorCountDown.erase(iter);
	}
	// if no find enlarge then add it
	Node* nodeEnlarge = _mapCountDown.at(COUNTDOWN_ENLARGE);
	if (_vectorCountDown.find(nodeEnlarge) == _vectorCountDown.end())
	{
		nodeEnlarge->setVisible(true);
		_vectorCountDown.pushBack(nodeEnlarge);
		this->setCountDownPosition();
	}

	scheduler->unschedule("enlargeCountDown", this);
	scheduler->schedule(CC_CALLBACK_1(PlayerLayer::startCountDown, this, COUNTDOWN_ENLARGE, GAMETEXT_PLAYERLAYER_ENLARGE),
		this, 0.1f, int(duration * 10), 0, false, "enlargeCountDown");
}

void PlayerLayer::startPlayerShrink(float duration)
{
	_player->runAction(ScaleTo::create(0.5f, 0.5f));
	_mapCurCountDownTime[COUNTDOWN_SHRINK] = duration;
	_mapMaxCountDownTime[COUNTDOWN_SHRINK] = duration;
	auto scheduler = Director::getInstance()->getScheduler();
	// find shrink count down and delete it
	Node* nodeEnlarge = _mapCountDown.at(COUNTDOWN_ENLARGE);
	_mapCurCountDownTime[COUNTDOWN_ENLARGE] = 0;
	_mapMaxCountDownTime[COUNTDOWN_ENLARGE] = 0;
	auto iter = _vectorCountDown.find(nodeEnlarge);
	if (iter != _vectorCountDown.end())
	{
		scheduler->unschedule("enlargeCountDown", this);
		nodeEnlarge->setVisible(false);
		_vectorCountDown.erase(iter);
	}
	// if no find enlarge then add it
	Node* nodeShrink = _mapCountDown.at(COUNTDOWN_SHRINK);
	if (_vectorCountDown.find(nodeShrink) == _vectorCountDown.end())
	{
		nodeShrink->setVisible(true);
		_vectorCountDown.pushBack(nodeShrink);
		this->setCountDownPosition();
	}

	scheduler->unschedule("shrinkCountDown", this);
	scheduler->schedule(CC_CALLBACK_1(PlayerLayer::startCountDown, this, COUNTDOWN_SHRINK, GAMETEXT_PLAYERLAYER_SHRINK),
		this, 0.1f, int(duration * 10), 0, false, "shrinkCountDown");
}

void PlayerLayer::startPlayerShield(float duration)
{
	_player->playShieldAnimation(duration);
	_mapCurCountDownTime[COUNTDOWN_SHIELD] = duration;
	_mapMaxCountDownTime[COUNTDOWN_SHIELD] = duration;
	auto scheduler = Director::getInstance()->getScheduler();
	Node* node = _mapCountDown.at(COUNTDOWN_SHIELD);
	if (_vectorCountDown.find(node) == _vectorCountDown.end())
	{
		node->setVisible(true);
		_vectorCountDown.pushBack(node);
		this->setCountDownPosition();
	}

	scheduler->unschedule("shieldCountDown", this);
	scheduler->schedule(CC_CALLBACK_1(PlayerLayer::startCountDown, this, COUNTDOWN_SHIELD, GAMETEXT_PLAYERLAYER_SHIELD),
		this, 0.1f, int(duration * 10), 0, false, "shieldCountDown");

	return;
}

void PlayerLayer::setCountDownPosition()
{
	Point start = Point(0, Director::getInstance()->getWinSize().height * 0.7);
	for (auto obj : _vectorCountDown)
	{
		if (obj->isVisible())
		{
			obj->setPosition(start);
			start.y -= 50;
		}
	}
}