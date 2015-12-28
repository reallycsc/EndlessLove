#pragma once
#include "CommonHeader.h"

class SettingLayer :
	public Layer
{
public:
	SettingLayer(void);
	~SettingLayer(void);

	CREATE_FUNC(SettingLayer);
	virtual bool init() override;

private:
	void menuCallback_Apply(Ref* pSender);
	void menuCallback_Cancel(Ref* pSender);
	void menuCallback_Restore(Ref* pSender);

	void menuCallback_MusicOn(Ref* pSender);
	void menuCallback_MusicOff(Ref* pSender);
	void onSliderEvent(Ref* pSender, Slider::EventType type);

	void selectedStateEvent_CN(Ref *pSender, CheckBox::EventType type);
	void selectedStateEvent_EN(Ref *pSender, CheckBox::EventType type);
    
private:
	Layout*	m_pLayout;
	CheckBox*	m_pCheckBoxCN;
	CheckBox*	m_pCheckBoxEN;

	Button*		m_pButtonMusicOn;
	Button*		m_pButtonMusicOff;
	Slider*		m_pSliderMusic;

	LanguageType	m_languageType;
	LanguageType	m_languageTypeOriginal;
};

