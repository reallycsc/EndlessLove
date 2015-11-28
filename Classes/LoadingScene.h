#pragma once
#include "CommonHeader.h"

class LoadingScene :
	public Scene
{
public:
	LoadingScene(void);
	~LoadingScene(void);

	CREATE_FUNC(LoadingScene);

	virtual bool init();

};

