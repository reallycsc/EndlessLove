#pragma once
#include "CommonHeader.h"
#include "Player.h"
#include "GameMediator.h"

enum {
	TYPE_HEARTLEFT = 0,
	TYPE_HEART,
	TYPE_HEARTRIGHT,
};

class PlayerLayer :
	public Layer
{
public:
	PlayerLayer(void);
	~PlayerLayer(void);

	CREATE_FUNC(PlayerLayer);
	virtual bool init();

	void update(float dt);
	void startCountDown(float dt, int countDownType, int textType);

	void updateScoreText();
	void updateGoldNumberText();
	void updateHeartNumber(float addNumber);

	void startPlayerPowerUp();
	void schedulePlayerJump();

	void startShowGuideLine(float duration);
	void startPlayerEnlarge(float duration);
	void startPlayerShrink(float duration);
	void startPlayerShield(float duration);

private:
	void guideLineFadeOutFinished(Node* pSender);
	void setCountDownPosition();

	void heartFadeOutFinished(Node* pSender);
	inline void createProgressAction(Sprite* obj, float duration, int type);
	void progressToFinished(Node* pSender, Sprite* obj, int type);

public:
	CC_SYNTHESIZE(Player*, _player, Player);

private:

	GameMediator*	_gameMediator;
	PlayerData*	_playerData;

	Text*	_textScore;
	Text*	_textGoldNum;
	Text*	_textHeartNum;
	Vector<Sprite*>	_vectorSpriteHeart;
	Sprite* _spriteHeart;
	Sprite*	_spriteHalfHeartLeft;
	Sprite*	_spriteHalfHeartRight;

	Sprite* _spriteGuideLine;
	Map<int, Node*> _mapCountDown;
	Vector<Node*>	_vectorCountDown;

	map<int, float> _mapCurCountDownTime;
	map<int, float> _mapMaxCountDownTime;
};

