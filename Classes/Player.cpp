#include "Player.h"
#include "CSCClass\CommonFunctions.h"

Player::Player(void)
{
	m_pPlayerData = GameMediator::getInstance()->getPlayerData();
	m_pSprite = NULL;
	m_pSpriteShield = NULL;
	m_pAnimate = NULL;

	m_fCurPower = 0;
	m_fCurSpeed = 0;
	m_nBottomPosY = 0;
	m_nTopPosY = 0;
	m_nFreeJumpNum = 0;

	m_bIsOnTheGround = true;
	m_bIsNeedToPowerUp = false;
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
		m_pAnimate = CSLoader::createTimeline("PlayerNode.csb");
		rootNode->runAction(m_pAnimate);
		m_pAnimate->pause();
		this->addChild(rootNode);

		// get sprite
		m_pSprite = dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_Player"));
		m_nTopPosY = winSize.height - m_pSprite->getBoundingBox().size.height;

		// get shield
		m_pSpriteShield = dynamic_cast<Sprite*>(m_pSprite->getChildByName("Sprite_Shield"));
		m_pSpriteShield->setVisible(false);

		// change player sprite grey
		this->changePlayerColorToGrey();

		// random blink
		this->runAction(Sequence::createWithTwoActions(
			DelayTime::create(random(1.0f, 5.0f)),
			CallFunc::create(CC_CALLBACK_0(Player::blink, this))
			));
		m_pAnimate->play("Shield_Fade", true);

		this->scheduleUpdate();

        bRet = true;
    } while (0);
    
    return bRet;
}

void Player::update(float dt)
{
	// change player's position & speed in the air
	if (!m_bIsOnTheGround)
	{
		Point posNow = this->getPosition();
		int posNewY = posNow.y + m_fCurSpeed * dt;
		if (posNewY <= m_nBottomPosY)
		{
			posNewY = m_nBottomPosY;
			m_bIsOnTheGround = true;
			m_nFreeJumpNum = 0;
		}
		this->setPosition(posNow.x, MIN(posNewY, m_nTopPosY));
		m_fCurSpeed -= GRAVITY*dt;
	}
	// check if need to jump
	do
	{
		if (!m_bIsNeedToJump)
			break;
		if (m_pPlayerData->getIsJumpOnTheGround() && !m_bIsOnTheGround)
			break;
		this->startJump();
	} while (false);
	// check if need to power up
	do
	{
		if (!m_bIsNeedToPowerUp)
			break;
		if (m_bIsNeedToJump) // only power up when jump is over
			break;
		if (m_pPlayerData->getIsPowerUpOnTheGround() && !m_bIsOnTheGround)
			break;
		this->startPowerUp();
	} while (false);
	// change curPower when power up
	if (m_bIsPowerUp && m_fCurPower < MAXPOWER)
	{
		m_fCurPower += MAXPOWER * dt / m_pPlayerData->getPowerTime();
		m_fCurPower = min(m_fCurPower, (float)MAXPOWER);
	}
}

void Player::blink()
{
	this->runAction(Sequence::createWithTwoActions(
		DelayTime::create(random(1.0f, 5.0f)),
		CallFunc::create(CC_CALLBACK_0(Player::blink, this))
		));
	if (m_pSprite->getScaleX() == m_pSprite->getScaleY())
		m_pAnimate->play("Player_Blink", false);
}

void Player::startPowerUp()
{
	m_bIsPowerUp = true;
	m_bIsNeedToPowerUp = false;
	m_fCurPower = 0;
	ScaleTo* scaleTo = ScaleTo::create(m_pPlayerData->getPowerTime(), 1.0f, 0.5f);
	scaleTo->setTag(ACTIONTAG_PLAYER_SCALEY);
	m_pSprite->runAction(scaleTo);
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
	if (!m_bIsOnTheGround)
		m_nFreeJumpNum++;
	if (m_nFreeJumpNum > m_pPlayerData->getFreeJumpTime())
		return;

	m_pSprite->stopActionByTag(ACTIONTAG_PLAYER_SCALEY);

	m_bIsOnTheGround = false;
	m_bIsPowerUp = false;
	m_bIsNeedToJump = false;
	// resume sprite scale Y to normal
	m_pSprite->setScaleY(1.0f);
	// speed
	m_fCurSpeed = m_pPlayerData->getStrength() * m_fCurPower/MAXPOWER;
	m_fCurPower = 0;
}

void Player::changePlayerColorToGrey()
{
	float minNumber = 0;
	float maxNumber = m_pPlayerData->getMaxHeartNumber();
	float percent = 1.0f;
	if (minNumber != maxNumber)
		percent = (m_pPlayerData->getHeartNumber() - minNumber) / (maxNumber - minNumber);
	CSC::spriteToGray(m_pSprite, percent);
}

void Player::playShieldAnimation(float duration)
{
	
	m_pSpriteShield->setVisible(true);
	this->unschedule(schedule_selector(Player::stopShieldAnimation));
	this->scheduleOnce(schedule_selector(Player::stopShieldAnimation), duration);
}

void Player::stopShieldAnimation(float dt)
{
	m_pSpriteShield->setVisible(false);
}