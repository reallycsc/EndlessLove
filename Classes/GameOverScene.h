#pragma once
#include "CommonHeader.h"

class GameOverScene :
	public Scene
{
public:
	GameOverScene(void);
	~GameOverScene(void);

	CREATE_FUNC(GameOverScene);

	virtual bool init();

};

