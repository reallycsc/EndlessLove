#pragma once
#include "CommonHeader.h"

class PauseLayer :
	public Layer
{
public:
	PauseLayer(void);
	~PauseLayer(void);

	CREATE_FUNC(PauseLayer);
	virtual bool init();

private:
	void menuCallback_Resume(Ref* pSender);
	void menuCallback_Retry(Ref* pSender);
	void menuCallback_MainMenu(Ref* pSender);

private:
	Layout*	m_pLayout;
};

