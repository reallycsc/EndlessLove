#pragma once
#include "CommonHeader.h"
#include "GameMediator.h"

const int ZORDER_MAINMENULAYER_MAINLAYER = 0;
const int ZORDER_MAINMENULAYER_PLAYER = 1;
const int ZORDER_MAINMENULAYER_PURCHASELAYER = 2;
const int ZORDER_MAINMENULAYER_SETTINGLAYER = 2;

class MainMenuLayer :
	public Layer
{
public:
	MainMenuLayer(void);
	~MainMenuLayer(void);

	CREATE_FUNC(MainMenuLayer);

	virtual bool init() override;  

private:
	virtual bool onTouchBegan(Touch* touch, Event* event) override;
	virtual void onTouchMoved(Touch *touch, Event *event) override;
	virtual void onTouchEnded(Touch* touch, Event* event) override;

	void menuCallback_Upgrade(Ref* pSender);
	void menuCallback_Setting(Ref* pSender);
	void menuCallback_SignIn(Ref* pSender);
	void menuCallback_Leaderboard(Ref* pSender);
	void menuCallback_Achievement(Ref* pSender);
	void menuCallback_PurchaseNoAd(Ref* pSender);

	void menuCallback_Reload(Ref* pSender);
	void menuCallback_Purchase(Ref* pSender);
	void menuCallback_Reset(Ref* pSender);

	void playerBlink();
    
private:
    GameMediator*   m_pGameMediator;
	map<string, string>*	m_pmGameText;

    PlayerData* m_pPlayerData;

	ActionTimeline* m_pAnimate;
	ActionTimeline* m_pPlayerAnimate;
    Text*   m_pTextHighscore;
};