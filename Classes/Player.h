#pragma once
#include "CommonHeader.h"
#include "GameMediator.h"

const int MAXPOWER = 100;
const float MINSCALE = 0.5;

class Player :
	public Sprite
{
public:
	Player(void);
	~Player(void);

	CREATE_FUNC(Player);
	bool init();

	void update(float dt);

	void startPowerUp();
	void scheduleJump();
	void startJump();

	void playShieldAnimation(float duration);
	void stopShieldAnimation(float dt);

	void changePlayerColorToGrey();

public:
	CC_SYNTHESIZE(Sprite*, m_pSprite, Sprite);

	CC_SYNTHESIZE(bool, m_bIsOnTheGround, IsOnTheGround);
	CC_SYNTHESIZE(bool, m_bIsPowerUp, IsPowerUp);
	CC_SYNTHESIZE(bool, m_bIsNeedToJump, IsNeedToJump);

	CC_SYNTHESIZE(float, m_fCurPower, CurPower);

	CC_SYNTHESIZE(bool, m_bIsShield, IsShield);
	CC_SYNTHESIZE(bool, m_bIsIntersect, IsIntersect);

	CC_SYNTHESIZE(int, m_nGroundLevel, GroundLevel);

private:
	GameMediator*	m_pGameMediator;
	PlayerData*	_m_pPlayerData;

	Sprite*	m_pSpriteShield;

	bool m_bShieldOpacityLess;

	float m_fCurSpeed;
	float m_fPreviousScaleY;
};

