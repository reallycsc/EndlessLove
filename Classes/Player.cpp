#include "Player.h"

Player::Player(void)
{
	_gameMediator = GameMediator::getInstance();
	_spritePlayer = NULL;
	_loadingBarPlayerPower = NULL;
	_nodeHeart = NULL;
	_textHeartNumber = NULL;
	_spriteShield = NULL;
	_textGood = NULL;
	_textGreat = NULL;
	_textPerfect = NULL;

	m_fCurPower = 0;
	m_fCurSpeed = 0;
	m_fPreviousScaleY = 1.0f;
	m_iGroundLevel = 0;

	m_bIsOnTheGround = true;
	m_bIsPowerUp = false;
	m_bIsNeedToJump = false;
	m_bIsShield = false;
	m_bShieldOpacityLess = true;
	m_bIsIntersect = false;
}

Player::~Player(void)
{
}

bool Player::init()
{  
    bool bRet = false;  
    do   
    {  
        CC_BREAK_IF(!Node::init());  
		Size winSize = Director::getInstance()->getWinSize();

		// load csb
		auto rootNode = CSLoader::createNode("PlayerNode.csb");
		this->addChild(rootNode);
		// get sprite
		_spritePlayer = dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Player"));
		_nodeHeart = dynamic_cast<Node*>(rootNode->getChildByName("Node_Heart"));
		_nodeHeart->setVisible(false);
		_textHeartNumber = dynamic_cast<Text*>(_nodeHeart->getChildByName("Text_HeartNumber"));
		_textGood = dynamic_cast<Text*>(rootNode->getChildByName("Text_Good"));
		_textGood->setVisible(false);
		_textGreat = dynamic_cast<Text*>(rootNode->getChildByName("Text_Great"));
		_textGreat->setVisible(false);
		_textPerfect = dynamic_cast<Text*>(rootNode->getChildByName("Text_Perfect"));
		_textPerfect->setVisible(false);

		// get loadingbar
		_loadingBarPlayerPower = dynamic_cast<LoadingBar*>(rootNode->getChildByName("LoadingBar_PlayerPower"));
		_loadingBarPlayerPower->setPercent(0.0f);
		_loadingBarPlayerPower->setVisible(false);

		// get shield
		_spriteShield = dynamic_cast<Sprite*>(_spritePlayer->getChildByName("Sprite_Shield"));
		_spriteShield->setVisible(false);

		// set text
		auto mapGameText = GameMediator::getInstance()->getGameText();
		_textGood->setString(mapGameText->at(GAMETEXT_PLAYER_GOOD));
		_textGreat->setString(mapGameText->at(GAMETEXT_PLAYER_GREAT));
		_textPerfect->setString(mapGameText->at(GAMETEXT_PLAYER_PERFECT));

		// change player sprite grey
		this->changePlayerColorToGrey();


		this->scheduleUpdate();

        bRet = true;
    } while (0);
    
    return bRet;
}

void Player::update(float dt)
{
	if (_gameMediator->getGameState() == STATE_GAME_RUN)
	{
		if (!m_bIsOnTheGround) // in the air
		{
			// change position
			Point posNow = this->getPosition();
			Point posNew = Point(posNow.x, posNow.y + m_fCurSpeed * dt);
			this->setPosition(posNew);
			m_fCurSpeed -= GRAVITY*dt;
			if (posNew.y <= m_iGroundLevel)
			{
				this->setPosition(posNew.x, m_iGroundLevel);
				m_bIsOnTheGround = true;
			}
		}
		else // on the ground
		{
			if (m_bIsNeedToJump)
			{
				this->startJump();
			}
		}
		// check if need power up
		if (m_bIsPowerUp && m_fCurPower < MAXPOWER)
		{
			m_fCurPower += MAXPOWER * dt / _gameMediator->getPlayerData()->getPowerTime();
			if (m_fCurPower > MAXPOWER)
			{
				m_fCurPower = MAXPOWER;
			}
			_loadingBarPlayerPower->setPercent(m_fCurPower * 100 / MAXPOWER);
			float curScaleY = 1.0 - (1.0 - MINSCALE)*m_fCurPower / MAXPOWER;
			_spritePlayer->setScaleY(curScaleY * _spritePlayer->getScaleY() / m_fPreviousScaleY);
			m_fPreviousScaleY = curScaleY;
		}
		// check if need to play shield animation
		if (_spriteShield->isVisible())
		{
			// max = 255, min = 255 * 0.75 = 191
			auto old = _spriteShield->getOpacity();
			if (m_bShieldOpacityLess)
				old--;
			else
				old++;
			if (old >= 255)
			{
				m_bShieldOpacityLess = true;
				old = 255;
			}
			if (old <= 191)
			{
				m_bShieldOpacityLess = false;
				old = 191;
			}
			_spriteShield->setOpacity(old);
		}
	}
}

void Player::startPowerUp()
{
	if (!m_bIsNeedToJump)
	{
		m_bIsPowerUp = true;
		m_fCurPower = 0;
		// ÏÔÊ¾ÐîÁ¦Ìõ
		_loadingBarPlayerPower->setPercent(0.0f);
		_loadingBarPlayerPower->setVisible(true);
	}
}

void Player::scheduleJump()
{
	if (m_bIsPowerUp)
	{
		m_bIsPowerUp = false;
		m_bIsNeedToJump = true;
	}
}

void Player::startJump()
{
	_loadingBarPlayerPower->setVisible(false);
	_loadingBarPlayerPower->setPercent(0);
	m_bIsOnTheGround = false;
	m_bIsPowerUp = false;
	m_bIsNeedToJump = false;
	// sprite scale Y
	_spritePlayer->setScaleY(_spritePlayer->getScaleY() / m_fPreviousScaleY);
	m_fPreviousScaleY = 1.0f;
	// speed
	m_fCurSpeed = _gameMediator->getPlayerData()->getStrength() * m_fCurPower/MAXPOWER;
	m_fCurPower = 0;
}

inline void Player::changePlayerColorToGrey()
{
	PlayerData* playerData = _gameMediator->getPlayerData();
	float minNumber = 1;
	float maxNumber = playerData->getMaxHeartNumber();
	float percent = 1.0f;
	if (minNumber != maxNumber)
		percent = (playerData->getHeartNumber() - minNumber) / (maxNumber - minNumber);
	_gameMediator->spriteToGrey(_spritePlayer, percent);
}

float Player::addHeartNumber(float number) // return heart number before change
{
	// heart number increase
	float realNumber = _gameMediator->getPlayerData()->addHeartNumber(number);
	// change player to color
	if (realNumber != 0)
	{
		this->changePlayerColorToGrey();
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
	_nodeHeart->setPositionY(80);
	_nodeHeart->runAction(Sequence::create(
		MoveTo::create(0.5f, Point(0, _nodeHeart->getPositionY() + 100)),
		FadeOut::create(0.5f),
		NULL));

	return realNumber;
}

void Player::playShieldAnimation(float duration)
{
	m_bIsShield = true;
	_spriteShield->setVisible(true);
	this->unschedule(schedule_selector(Player::stopShieldAnimation));
	this->scheduleOnce(schedule_selector(Player::stopShieldAnimation), duration);
}

void Player::stopShieldAnimation(float dt)
{
	m_bIsShield = false;
	_spriteShield->setVisible(false);
}

void Player::showEvaluation(int y)
{
	if (m_bIsIntersect)
		return;
	if (y < 50) // Perfect
	{
		_textPerfect->setScale(1);
		_textPerfect->setVisible(true);
		_textPerfect->setOpacity(255);
		_textPerfect->setPositionY(120);
		_textPerfect->runAction(Sequence::create(
			Spawn::create(
				ScaleTo::create(0.5f, 2.0f),
				MoveTo::create(0.5f, Point(0, _textPerfect->getPositionY() + 100)),
				NULL),
			FadeOut::create(0.5f),
			NULL));
	}
	else if (y >= 50 && y < 100) // Great
	{
		_textGreat->setScale(1);
		_textGreat->setVisible(true);
		_textGreat->setOpacity(255);
		_textGreat->setPositionY(120);
		_textGreat->runAction(Sequence::create(
			Spawn::create(
				ScaleTo::create(0.5f, 2.0f),
				MoveTo::create(0.5f, Point(0, _textPerfect->getPositionY() + 100)),
				NULL),
			FadeOut::create(0.5f),
			NULL));
	}
	else // Good
	{
		_textGood->setScale(1);
		_textGood->setVisible(true);
		_textGood->setOpacity(255);
		_textGood->setPositionY(120);
		_textGood->runAction(Sequence::create(
			Spawn::create(
				ScaleTo::create(0.5f, 2.0f),
				MoveTo::create(0.5f, Point(0, _textPerfect->getPositionY() + 100)),
				NULL),
			FadeOut::create(0.5f),
			NULL));
	}
}