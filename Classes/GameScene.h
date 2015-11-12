#pragma once
#include "CommonHeader.h"

class GameScene :
	public Scene
{
public:
	GameScene(void);
	~GameScene(void);

	CREATE_FUNC(GameScene);

	virtual bool init();  
};

