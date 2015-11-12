#pragma once
#include "CommonHeader.h"
#include "GameMediator.h"

class MainMenuLayer :
	public Layer
{
public:
	MainMenuLayer(void);
	~MainMenuLayer(void);

	CREATE_FUNC(MainMenuLayer);

	virtual bool init();  

	void menuCallback_Start(Ref* pSender);
	void menuCallback_Exit(Ref* pSender);
	void menuCallback_Upgrade(Ref* pSender);

	void menuCallback_Reload(Ref* pSender);
};

