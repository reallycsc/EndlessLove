#pragma once
#include "CommonHeader.h"

class PurchaseLayer :
	public Layer
{
public:
	PurchaseLayer(void);
	~PurchaseLayer(void);

	CREATE_FUNC(PurchaseLayer);
	virtual bool init() override;
    
private:
	void showListItems();

	void menuCallback_Close(Ref* pSender);
	void menuCallback_Buy(Ref* pSender, Button* button, const char* id);
private:
    Layout*	m_pLayout;
    ListView*   m_pListView;
};

