#include "PurchaseLayer.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#import "Reachability.h"
#import "ProgressHUD.h"
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
		buttonClose->setTitleText(m_pmGameText->at(GAMETEXT_COMMON_CLOSE));

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
                [ProgressHUD show: m_pmGameText->at(GAMETEXT_PROGRESSHUD_DOWNLOADINFO) Interaction:FALSE];
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
        itemDesc->setTextAreaSize(cocos2d::Size(scrollView->getInnerContainerSize().width,0));
        scrollView->setInnerContainerSize(itemDesc->getVirtualRendererSize());
        itemDesc->setPosition(cocos2d::Point(10,scrollView->getInnerContainerSize().height));

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
    [ProgressHUD show: m_pmGameText->at(GAMETEXT_PROGRESSHUD_BUYING) Interaction:FALSE];
    [helper buyProduct:product
          onCompletion:^(SKPaymentTransaction* trans) {
              [ProgressHUD dismiss];
              if(trans.error) {
                  NSLog(@"Fail %@",[trans.error localizedDescription]);
              }
              else if(trans.transactionState == SKPaymentTransactionStatePurchased) {
                  [ProgressHUD show: m_pmGameText->at(GAMETEXT_PROGRESSHUD_CHECKINGRECEPIT) Interaction:FALSE];
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
                                      [ProgressHUD showError: m_pmGameText->at(GAMETEXT_PROGRESSHUD_RECEIPTSTATUSERROR)];
                                      NSLog(@"Fail in response status is 0");
                                  }
                              }
                              else {
                                  [ProgressHUD showError: m_pmGameText->at(GAMETEXT_PROGRESSHUD_NORESPONSE)];
                              }
                          }];
              }
              else if(trans.transactionState == SKPaymentTransactionStateFailed) {
                  [ProgressHUD showError: m_pmGameText->at(GAMETEXT_PROGRESSHUD_RECEIPTCHECKERROR)];
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
                                          CallFuncN::create(CC_CALLBACK_1(PurchaseLayer::moveToFinished, this)),
                                          NULL));
}

void PurchaseLayer::moveToFinished(Ref* pSender)
{
    this->removeFromParent();
}

void PurchaseLayer::waitingTimeOut(float dt)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    [ProgressHUD showError: m_pmGameText->at(GAMETEXT_PROGRESSHUD_RESPONSETIMEOUT)];
#endif
}