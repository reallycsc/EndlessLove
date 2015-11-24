#pragma once
#include "CommonHeader.h"
#include "GameMediator.h"

class GameOverLayer :
	public Layer
{
public:
	GameOverLayer(void);
	~GameOverLayer(void);

	CREATE_FUNC(GameOverLayer);
	virtual bool init();  

private:
	void menuCallback_Retry(Ref* pSender);
	void menuCallback_MainMenu(Ref* pSender);
	void menuCallback_Revive(Ref* pSender);
	void menuCallback_DoubleGold(Ref* pSender);

	void showScoreAndStory();

private:
	GameMediator*	m_pGameMediator;
	map<int, string>*	m_pMapGameText;

	Layout*	m_pLayout;
	Text*	m_pTextHighscore;
	Text*	m_pTextGoldNumber;
	ScrollView* m_pScrollStory;
	Text*	m_pTextStory;

	Button*	m_pButtonRetry; 
	Button*	m_pButtonMainMenu;
	Button*	m_pButtonRevive;
	Button*	m_pButtonDoubleCoin;

	ActionTimeline* m_pAnimate;

	int m_nHighscore;
};

