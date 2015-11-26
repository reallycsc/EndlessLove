#pragma once
#include "CommonHeader.h"

class PauseScene :
	public Scene
{
public:
	PauseScene(void);
	~PauseScene(void);

	CREATE_FUNC(PauseScene);

	virtual bool init();

};

