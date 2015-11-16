#include "Player.h"

Player::Player(void)
{
	_gameMediator = GameMediator::getInstance();
	m_pSprite = NULL;
	_spriteShield = NULL;

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
        CC_BREAK_IF(!Sprite::init());  
		Size winSize = Director::getInstance()->getWinSize();

		// load csb
		auto rootNode = CSLoader::createNode("PlayerNode.csb");
		this->addChild(rootNode);
		// get sprite
		m_pSprite = dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Player"));

		// get shield
		_spriteShield = dynamic_cast<Sprite*>(m_pSprite->getChildByName("Sprite_Shield"));
		_spriteShield->setVisible(false);

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
			float curScaleY = 1.0 - (1.0 - MINSCALE)*m_fCurPower / MAXPOWER;
			m_pSprite->setScaleY(curScaleY * m_pSprite->getScaleY() / m_fPreviousScaleY);
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
	m_bIsOnTheGround = false;
	m_bIsPowerUp = false;
	m_bIsNeedToJump = false;
	// sprite scale Y
	m_pSprite->setScaleY(m_pSprite->getScaleY() / m_fPreviousScaleY);
	m_fPreviousScaleY = 1.0f;
	// speed
	m_fCurSpeed = _gameMediator->getPlayerData()->getStrength() * m_fCurPower/MAXPOWER;
	m_fCurPower = 0;
}

void Player::changePlayerColorToGrey()
{
	PlayerData* playerData = _gameMediator->getPlayerData();
	float minNumber = 1;
	float maxNumber = playerData->getMaxHeartNumber();
	float percent = 1.0f;
	if (minNumber != maxNumber)
		percent = (playerData->getHeartNumber() - minNumber) / (maxNumber - minNumber);
	_gameMediator->spriteToGray(this, percent);
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