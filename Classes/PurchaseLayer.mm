#include "PurchaseLayer.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#import "IOSHelper/Reachability.h"
#import "IOSHelper/ProgressHUD.h"
#endif

PurchaseLayer::PurchaseLayer(void)
{
	m_pmGameText = GameMediator::getInstance()->getGameText();
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

        cocos2d::Size winSize = Director::getInstance()->getWinSize();

		// load csb
		auto rootNode = CSLoader::createNode("PurchaseLayer.csb");
		this->addChild(rootNode);

        
        m_pLayout = dynamic_cast<Layout*>(rootNode->getChildByName("Panel_Purchase"));
        m_pListView = dynamic_cast<ListView*>(m_pLayout->getChildByName("ListView_Products"));
        
        // get botton
        auto buttonClose = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_Close"));
        buttonClose->addClickEventListener(CC_CALLBACK_1(PurchaseLayer::menuCallback_Close, this));
        
		// set all text
		buttonClose->setTitleText(m_pmGameText->at("ID_COMMON_CLOSE"));

        // run animation
        m_pLayout->setPosition(cocos2d::Point(winSize.width/2, winSize.height+ m_pLayout->getContentSize().height));
        m_pLayout->runAction(MoveTo::create(0.2f, cocos2d::Point(winSize.width/2, winSize.height/2)));
        
        // swallow all touches
        auto touchListener = EventListenerTouchOneByOne::create();
        touchListener->setSwallowTouches(true);
        touchListener->onTouchBegan = [](Touch *, Event *){return true;};
        _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        // load iap
        IAPHelper* helper = [IAPShare sharedHelper].iap;
        Reachability *reach = [Reachability reachabilityForInternetConnection];
        NetworkStatus netStatus = [reach currentReachabilityStatus];
        if (netStatus == NotReachable) {
            NSLog(@"No internet connection!");
        } else {
            if (helper.products == nil) {
                helper.production = NO; // No for test, YES for release
                [helper requestProductsWithCompletion:^(SKProductsRequest* request,SKProductsResponse* response) {
                    if(response > 0 ) {
                        [ProgressHUD dismiss];
                        this->unschedule(schedule_selector(PurchaseLayer::waitingTimeOut));
                        this->showListItems();
                    }
                }];
                [ProgressHUD show: [NSString stringWithCString:m_pmGameText->at("ID_IAP_DOWNLOAD").c_str()
                                                      encoding:NSUTF8StringEncoding]
                      Interaction:FALSE];
                this->scheduleOnce(schedule_selector(PurchaseLayer::waitingTimeOut), 10.0f);
            }
            else {
                this->showListItems();
            }
        }
#endif
        
        bRet = true;
    } while (0);  
  
    return bRet;  
}

void PurchaseLayer::showListItems()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    IAPHelper* helper = [IAPShare sharedHelper].iap;
    
    for (int i = 0; i < [helper.products count]; i++) {
        SKProduct *product = [helper.products objectAtIndex:i];
        
        Node* itemNode = CSLoader::getInstance()->createNodeWithFlatBuffersFile("PurchaseItemNode.csb");
        Layout* layout = dynamic_cast<Layout*>(itemNode->getChildByName("Panel_PurchaseItem"));
        Text* itemName = dynamic_cast<Text*>(layout->getChildByName("Text_ItemName"));
        ScrollView* scrollView = dynamic_cast<ScrollView*>(layout->getChildByName("ScrollView_Desc"));
        Text* itemDesc = dynamic_cast<Text*>(scrollView->getChildByName("Text_Desc"));
        Button* button = dynamic_cast<Button*>(layout->getChildByName("Button_Buy"));
        button->addClickEventListener(CC_CALLBACK_1(PurchaseLayer::menuCallback_Buy, this, button, product));
        
        itemName->setString([product.localizedTitle UTF8String]);
        itemDesc->setString([product.localizedDescription UTF8String]);
		GameMediator::setLineWrap(scrollView, itemDesc);

        NSNumberFormatter *numberFormatter = [[NSNumberFormatter alloc] init];
        [numberFormatter setFormatterBehavior:NSNumberFormatterBehavior10_4];
        [numberFormatter setNumberStyle:NSNumberFormatterCurrencyStyle];
        [numberFormatter setLocale:product.priceLocale];
        button->setTitleText([[numberFormatter stringFromNumber:product.price] UTF8String]);
        
        layout->removeFromParentAndCleanup(false);
        m_pListView->pushBackCustomItem(layout);
        
        if ([helper.purchasedProducts containsObject:product.productIdentifier]) {
            //button->setEnabled(false);
        }
    }
#endif
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
void PurchaseLayer::menuCallback_Buy(Ref* pSender, Button* button, SKProduct* product)
{
    IAPHelper* helper = [IAPShare sharedHelper].iap;
    [ProgressHUD show: [NSString stringWithCString:m_pmGameText->at("ID_IAP_BUYING").c_str()
                                          encoding:NSUTF8StringEncoding]
          Interaction:FALSE];
    [helper buyProduct:product
          onCompletion:^(SKPaymentTransaction* trans) {
              [ProgressHUD dismiss];
              if(trans.error) {
                  NSLog(@"Fail %@",[trans.error localizedDescription]);
              }
              else if(trans.transactionState == SKPaymentTransactionStatePurchased) {
                  [ProgressHUD show: [NSString stringWithCString:m_pmGameText->at("ID_IAP_CHECKRECEIPT").c_str()
                                                        encoding:NSUTF8StringEncoding]
                        Interaction:FALSE];
                  [helper checkReceipt:trans.transactionReceipt
                       AndSharedSecret:@"your sharesecret"
                          onCompletion:^(NSString *response, NSError *error) {
                              [ProgressHUD dismiss];
                              if (response) {
                                  //Convert JSON String to NSDictionary
                                  NSDictionary* rec = [IAPShare toJSON:response];
                                  if([rec[@"status"] integerValue]==0) {
                                      [helper provideContentWithTransaction:trans];
                                      NSLog(@"SUCCESS %@",response);
                                      NSLog(@"Pruchases %@",helper.purchasedProducts);
                                  }
                                  else {
                                      [ProgressHUD showError:[NSString stringWithCString:m_pmGameText->at("ID_IAP_RECEIPTWRONG").c_str()
                                                                                encoding:NSUTF8StringEncoding]];
                                      NSLog(@"Fail in response status is 0");
                                  }
                              }
                              else {
                                  [ProgressHUD showError:[NSString stringWithCString:m_pmGameText->at("ID_IAP_NORESPONSE").c_str()
                                                                            encoding:NSUTF8StringEncoding]];
                              }
                          }];
              }
              else if(trans.transactionState == SKPaymentTransactionStateFailed) {
                  [ProgressHUD showError:[NSString stringWithCString:m_pmGameText->at("ID_IAP_NORECEIPT").c_str()
                                                            encoding:NSUTF8StringEncoding]];
                  NSLog(@"Fail in SKPaymentTransactionStateFailed");
              }
          }];//end of buy product
}
#endif

void PurchaseLayer::menuCallback_Close(Ref* pSender)
{
    cocos2d::Size winSize = Director::getInstance()->getWinSize();
    m_pLayout->runAction(Sequence::create(
		MoveTo::create(0.2f, cocos2d::Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
		CallFuncN::create([=](Ref* pSender)->void
	{
		this->removeFromParent();
	}),
		NULL));
}

void PurchaseLayer::waitingTimeOut(float dt)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    [ProgressHUD showError:[NSString stringWithCString:m_pmGameText->at("ID_IAP_TIMEOUT").c_str()
                                              encoding:NSUTF8StringEncoding]];
#endif
}