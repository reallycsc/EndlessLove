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

	void menuCallback_Retry(Ref* pSender);
	void menuCallback_MainMenu(Ref* pSender);

	void showScoreAndStory();

private:
	GameMediator*	m_pGameMediator;
	map<int, string>*	m_pMapGameText;

	Text*	m_pTextHighscore;
	Text*	m_pTextGoldNumber;
	ScrollView* m_pScrollStory;
	Text*	m_pTextStory;

	ActionTimeline* m_pAnimate;

	int m_nHighscore;
};

