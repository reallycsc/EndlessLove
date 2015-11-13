#pragma once
#include "CommonHeader.h"

class PauseScene :
	public Scene
{
public:
	PauseScene(void);
	~PauseScene(void);

	static PauseScene* createScene(RenderTexture* sqr);

	virtual bool init(RenderTexture* sqr);

};

