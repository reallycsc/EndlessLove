#pragma once
#include "CommonHeader.h"

class NormalNoticeLayer :
	public Layer
{
public:
	NormalNoticeLayer(void);
	~NormalNoticeLayer(void);

	static NormalNoticeLayer* create(const string &title, const string &info);
	virtual bool init(const string &title, const string &info);

private:
	void menuCallback_OK(Ref* pSender);
	void moveToFinished(Ref* pSender);

private:
	Layout*	m_pLayout;
};

