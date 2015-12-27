#pragma once
#include "CommonHeader.h"
#include "GameMediator.h"
#include "CSCClass\CSC_IOSHelper.h"

class GameOverLayer : public Layer
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	, sdkbox::VungleListener
#endif
{
public:
	GameOverLayer(void);
	~GameOverLayer(void);

	CREATE_FUNC(GameOverLayer);
	virtual bool init() override;  

private:
	void menuCallback_Retry(Ref* pSender);
	void menuCallback_MainMenu(Ref* pSender);
	void menuCallback_Revive(Ref* pSender);
	void menuCallback_DoubleGold(Ref* pSender);

	void showScore() const;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    void onVungleCacheAvailable();
    void onVungleStarted();
    void onVungleFinished();
    void onVungleAdViewed(bool isComplete);
    void onVungleAdReward(const std::string& name);
#endif

    void realRevive();
    void realDouble();
    
private:
	GameMediator*	m_pGameMediator;
	PlayerData*		m_pPlayerData;
	map<string, string>*	m_pMapGameText;

	Layout*	m_pLayout;
	Text*	m_pTextHighscore;
	Text*	m_pTextGoldNumber;

	Button*	m_pButtonRetry; 
	Button*	m_pButtonMainMenu;
	Button*	m_pButtonRevive;
	Button*	m_pButtonDoubleCoin;
    Sprite* m_pSpriteRevivePlay;
    Sprite* m_pSpriteDoublePlay;

	ActionTimeline* m_pAnimate;

	int m_nHighscore;
};

