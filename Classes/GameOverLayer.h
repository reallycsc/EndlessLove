#pragma once
#include "CommonHeader.h"

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
	Text*	_textHighscore;
	Text*	_textGoldNumber;
	ScrollView* _scrollStory;
	Text* _textStory;

	ActionTimeline* _animate;

	int m_iHighestScore;
};

