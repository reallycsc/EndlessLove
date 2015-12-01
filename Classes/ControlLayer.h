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

private:
	void menuCallback_Pause(Ref* pSender);
};

