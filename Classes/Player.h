#pragma once
#include "CommonHeader.h"
#include "GameMediator.h"

const int MAXPOWER = 100;
const float MINSCALE = 0.5;

class Player :
	public Node
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

private:
	void blink();

public:
	CC_SYNTHESIZE(Sprite*, m_pSprite, Sprite);

	CC_SYNTHESIZE(bool, m_bIsOnTheGround, IsOnTheGround);
	CC_SYNTHESIZE(bool, m_bIsNeedToPowerUp, IsNeedToPowerUp);
	CC_SYNTHESIZE(bool, m_bIsPowerUp, IsPowerUp);
	CC_SYNTHESIZE(bool, m_bIsNeedToJump, IsNeedToJump);

	CC_SYNTHESIZE(float, m_fCurPower, CurPower);
	CC_SYNTHESIZE(float, m_fCurSpeed, CurSpeed);

	CC_SYNTHESIZE(bool, m_bIsShield, IsShield);
	CC_SYNTHESIZE(bool, m_bIsIntersect, IsIntersect);

	CC_SYNTHESIZE(int, m_nBottomPosY, BottomPosY);
	CC_SYNTHESIZE(int, m_nTopPosY, TopPosY);

private:
	PlayerData*	m_pPlayerData;

	Sprite*	m_pSpriteShield;
	ActionTimeline* m_pAnimate;

	bool m_bShieldOpacityLess;

	int m_nFreeJumpNum;
};

