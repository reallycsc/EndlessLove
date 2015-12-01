#pragma once
#include "CommonHeader.h"
#include "GameMediator.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#import "IOSHelper/IAPShare.h"
#endif


class PurchaseLayer :
	public Layer
{
public:
	PurchaseLayer(void);
	~PurchaseLayer(void);

	CREATE_FUNC(PurchaseLayer);
	virtual bool init();
    
    void showListItems();

private:
	void menuCallback_Close(Ref* pSender);
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    void menuCallback_Buy(Ref* pSender, Button* button, SKProduct* product);
#endif
    
    void waitingTimeOut(float dt);
    
private:
	map<string, string>*	m_pmGameText;
    Layout*	m_pLayout;
    ListView*   m_pListView;
};

