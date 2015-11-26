#pragma once
#include "CommonHeader.h"
#include "GameMediator.h"

class MainMenuLayer :
	public Layer
{
public:
	MainMenuLayer(void);
	~MainMenuLayer(void);

	CREATE_FUNC(MainMenuLayer);

	virtual bool init();  

private:
	void menuCallback_Start(Ref* pSender);
	void menuCallback_Exit(Ref* pSender);
	void menuCallback_Upgrade(Ref* pSender);
    void menuCallback_Leaderboard(Ref* pSender);
    void menuCallback_Achievement(Ref* pSender);
	void menuCallback_PurchaseNoAd(Ref* pSender);

    void realBuy(Ref* pSender);
	void waitingTimeOut(float dt);

	void menuCallback_Reload(Ref* pSender);
    void menuCallback_Purchase(Ref* pSender);
    void menuCallback_Reset(Ref* pSender);
    
private:
    GameMediator*   m_pGameMediator;
	map<int, string>*	m_pmGameText;

    PlayerData* m_pPlayerData;
    Text*   m_pTextHighscore;
};

