#pragma once
#include "CommonHeader.h"
#include "Player.h"
#include "GameMediator.h"

enum {
	TYPE_HEARTLEFT = 0,
	TYPE_HEART,
	TYPE_HEARTRIGHT,
};

const int ZORDER_PLAYERLAYER_PLAYER = 0;
const int ZORDER_PLAYERLAYER_MAINLAYER = 1;
const int ZORDER_PLAYERLAYER_FLOWINGGOLD = 2;
const int ZORDER_PLAYERLAYER_HEARTGREY = 3;
const int ZORDER_PLAYERLAYER_HEART = 4;
const int ZORDER_PLAYERLAYER_HEARTHALF = 5;
const int ZORDER_PLAYERLAYER_HEARTPROGRESS = 6;

class PlayerLayer :
	public Layer
{
public:
	PlayerLayer(void);
	~PlayerLayer(void);

	CREATE_FUNC(PlayerLayer);
	virtual bool init();

	virtual bool onTouchBegan(Touch* touch, Event* event);
	virtual void onTouchMoved(Touch* touch, Event* event);
	virtual void onTouchEnded(Touch* touch, Event* event);

	void update(float dt);

	void updateScoreText();
	void updateGoldNumberText();
	void addHeartNumber(float number);
	void showEvaluation(int y);

	void startShowGuideLine(float duration);
	void startPlayerEnlarge(float duration);
	void startPlayerShrink(float duration);
	void startPlayerShield(float duration);

private:
	void startCountDown(float dt, int countDownType, const char* textType);

	void guideLineFadeOutFinished(Node* pSender);
	void setCountDownPosition();

	void heartFadeOutFinished(Node* pSender);
	void goldMoveFinished(Node* pSender);

	void updateHeartNumber(float addNumber);

public:
	CC_SYNTHESIZE(Player*, m_pPlayer, Player);

private:
	GameMediator*	m_pGameMediator;
	map<string, string>*	m_pMapGameText;
	PlayerData*	m_pPlayerData;

	Text*	m_pTextScore;
	Node*	m_pNodeGoldNum;
	Text*	m_pTextGoldNum;
	Sprite*	m_pSpriteGold;

	Sprite* m_pSpriteHeart;
	Sprite*	m_pSpriteHalfHeartLeft;
	Sprite*	m_pSpriteHalfHeartRight;
	Vector<Sprite*>	m_vSpriteHearts;

	Sprite* m_pSpriteGuideLine;

	Map<int, Node*> m_mCountDown;
	Vector<Node*>	m_vCountDown;
	map<int, float> m_mCurCountDownTime;
	map<int, float> m_mMaxCountDownTime;

	Node*	m_pNodePlayerHeart;
	Text*	m_pTextHeartNumber;
	Text*	m_pTextGood;
	Text*	m_pTextGreat;
	Text*	m_pTextPerfect;

	float m_fCurHeartNumber;
};

