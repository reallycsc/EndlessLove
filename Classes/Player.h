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

	float addHeartNumber(float number);

	void playShieldAnimation(float duration);
	void stopShieldAnimation(float dt);

	void showEvaluation(int y);

public:
	CC_SYNTHESIZE(Sprite*, _spritePlayer, Sprite);

	CC_SYNTHESIZE(bool, m_bIsOnTheGround, IsOnTheGround);
	CC_SYNTHESIZE(bool, m_bIsPowerUp, IsPowerUp);
	CC_SYNTHESIZE(bool, m_bIsNeedToJump, IsNeedToJump);

	CC_SYNTHESIZE(float, m_fCurPower, CurPower);

	CC_SYNTHESIZE(bool, m_bIsShield, IsShield);
	CC_SYNTHESIZE(bool, m_bIsIntersect, IsIntersect);

	CC_SYNTHESIZE(int, m_iGroundLevel, GroundLevel);

private:
	GameMediator*	_gameMediator;

	LoadingBar*	_loadingBarPlayerPower;
	Node*	_nodeHeart;
	Text*	_textHeartNumber;
	Sprite*	_spriteShield;
	Text*	_textGood;
	Text*	_textGreat;
	Text*	_textPerfect;

	bool m_bShieldOpacityLess;

	float m_fCurSpeed;
	float m_fPreviousScaleY;

	inline void changePlayerColorToGrey();
};

