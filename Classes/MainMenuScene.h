#pragma once
#include "CommonHeader.h"

class MainMenuScene :
	public Scene
{
public:
	MainMenuScene(void);
	~MainMenuScene(void);

	CREATE_FUNC(MainMenuScene);

	virtual bool init();  
};

