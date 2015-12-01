#pragma once
#include "CommonHeader.h"

class SettingLayer :
	public Layer
{
public:
	SettingLayer(void);
	~SettingLayer(void);

	CREATE_FUNC(SettingLayer);
	virtual bool init();

private:
	void menuCallback_Apply(Ref* pSender);
	void menuCallback_Cancel(Ref* pSender);

	void selectedStateEvent_CN(Ref *pSender, CheckBox::EventType type);
	void selectedStateEvent_EN(Ref *pSender, CheckBox::EventType type);

private:
	Layout*	m_pLayout;
	CheckBox*	m_pCheckBoxCN;
	CheckBox*	m_pCheckBoxEN;

	LanguageType	m_languageType;
	LanguageType	m_languageTypeOriginal;
};

