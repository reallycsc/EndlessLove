#include "PurchaseLayer.h"
#include "CSCClass/CommonFunctions.h"
#include "GameMediator.h"
#include "CSCClass/CSC_IOSHelper.h"

PurchaseLayer::PurchaseLayer(void)
{
	m_pLayout = NULL;
	m_pListView = NULL;
}


PurchaseLayer::~PurchaseLayer(void)
{
}


bool PurchaseLayer::init()
{  
    bool bRet = false;  
    do
    {  
        CC_BREAK_IF(!Layer::init());  

        Size winSize = Director::getInstance()->getWinSize();

		// load csb
		auto rootNode = CSLoader::createNode("PurchaseLayer.csb");
		this->addChild(rootNode);

        m_pLayout = dynamic_cast<Layout*>(rootNode->getChildByName("Panel_Purchase"));
        m_pListView = dynamic_cast<ListView*>(m_pLayout->getChildByName("ListView_Products"));
        
        // get botton
        auto buttonClose = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_Close"));
        buttonClose->addClickEventListener(CC_CALLBACK_1(PurchaseLayer::menuCallback_Close, this));
        
		// set all text
		buttonClose->setTitleText(GameMediator::getInstance()->getGameText()->at("ID_COMMON_CLOSE"));

        // run animation
        m_pLayout->setPosition(Point(winSize.width/2, winSize.height+ m_pLayout->getContentSize().height));
        m_pLayout->runAction(MoveTo::create(0.2f, Point(winSize.width/2, winSize.height/2)));
        
        // swallow all touches
        auto touchListener = EventListenerTouchOneByOne::create();
        touchListener->setSwallowTouches(true);
        touchListener->onTouchBegan = [=](Touch *, Event *){return true;};
        _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
        
		// request IAP
#if IAPTEST_FLAG == 1
		CSCClass::CSC_IOSHelper::getInstance()->IAP_requestAllPurchasedProductsWithCallback(true, CC_CALLBACK_0(PurchaseLayer::showListItems, this));
#else
	    CSCClass::CSC_IOSHelper::getInstance()->IAP_requestAllPurchasedProductsWithCallback(false, CC_CALLBACK_0(PurchaseLayer::showListItems, this));
#endif
		
        bRet = true;
    } while (0);  
  
    return bRet;  
}

void PurchaseLayer::showListItems()
{
    for (int i = 0; i < CSCClass::CSC_IOSHelper::IAP_getProductsCount(); i++) {
        Node* itemNode = CSLoader::getInstance()->createNodeWithFlatBuffersFile("PurchaseItemNode.csb");
        Layout* layout = dynamic_cast<Layout*>(itemNode->getChildByName("Panel_PurchaseItem"));
        Text* itemName = dynamic_cast<Text*>(layout->getChildByName("Text_ItemName"));
        ScrollView* scrollView = dynamic_cast<ScrollView*>(layout->getChildByName("ScrollView_Desc"));
        Text* itemDesc = dynamic_cast<Text*>(scrollView->getChildByName("Text_Desc"));
        Button* button = dynamic_cast<Button*>(layout->getChildByName("Button_Buy"));
		const char* productID = CSCClass::CSC_IOSHelper::IAP_getProductID(i);
        button->addClickEventListener(CC_CALLBACK_1(PurchaseLayer::menuCallback_Buy, this, button, productID));
        
        itemName->setString(CSCClass::CSC_IOSHelper::IAP_getProductTitle(i));
        itemDesc->setString(CSCClass::CSC_IOSHelper::IAP_getProductDescription(i));
		CSCClass::setScrollViewTextAutoWrap(scrollView, itemDesc);

        button->setTitleText(CSCClass::CSC_IOSHelper::IAP_getProductPrice(i));
        
        layout->removeFromParentAndCleanup(false);
        m_pListView->pushBackCustomItem(layout);
        
        if (CSCClass::CSC_IOSHelper::IAP_isPurchased(productID)) {
			button->setEnabled(false);
        }
    }
}

void PurchaseLayer::menuCallback_Buy(Ref* pSender, Button* button, const char* id)
{
#if IAPTEST_FLAG == 1
	CSCClass::CSC_IOSHelper::getInstance()->IAP_purchaseProduct(true, id);
#else
	CSCClass::CSC_IOSHelper::getInstance()->IAP_purchaseProduct(false, id);
#endif
}

void PurchaseLayer::menuCallback_Close(Ref* pSender)
{
    cocos2d::Size winSize = Director::getInstance()->getWinSize();
    m_pLayout->runAction(Sequence::create(
		MoveTo::create(0.2f, cocos2d::Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
		CallFuncN::create([=](Ref* pSenderNew)->void
	{
		this->removeFromParent();
	}),
		NULL));
}