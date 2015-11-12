#pragma once
#include "CommonHeader.h"
#include "GameMediator.h"

class ControlLayer :
	public Layer
{
public:
	ControlLayer(void);
	~ControlLayer(void);

	CREATE_FUNC(ControlLayer);
	virtual bool init();

	void menuCallback_Pause(Ref* pSender);

	// game state contrl
	void gameStart();
	void gamePause();
	void gameResume();
	void gameOver();

private:
	GameMediator*	_gameMediator;

	Button* _buttonPause;
	Text*	_textTouchForStart;
};

