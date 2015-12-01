#include "MainMenuLayer.h"
#include "GameScene.h"
#include "PlayerUpgradeScene.h"
#include "PurchaseLayer.h"
#include "SettingLayer.h"
#include "Player.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#import "IOSHelper/GameKitHelper.h"
#import "IOSHelper/Reachability.h"
#import "IOSHelper/ProgressHUD.h"
#endif

MainMenuLayer::MainMenuLayer(void)
{
    m_pGameMediator = GameMediator::getInstance();
	m_pmGameText = m_pGameMediator->getGameText();
    m_pPlayerData = m_pGameMediator->getPlayerData();
	m_pAnimate = NULL;
	m_pPlayerAnimate = NULL;
	m_pTextHighscore = NULL;
    m_pButtonSignIn = NULL;
    m_pButtonAchievement = NULL;
    m_pButtonLeaderboard = NULL;
}


MainMenuLayer::~MainMenuLayer(void)
{
    _eventDispatcher->removeEventListenersForTarget(this);
}

bool MainMenuLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    cocos2d::Size winSize = Director::getInstance()->getWinSize();

	// bind touch event
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(MainMenuLayer::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(MainMenuLayer::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(MainMenuLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	// add scene
	auto rootNode = CSLoader::createNode("MainMenuScene.csb");
	m_pAnimate = CSLoader::createTimeline("MainMenuScene.csb");
	rootNode->runAction(m_pAnimate);
	m_pAnimate->pause();
	this->addChild(rootNode, ZORDER_MAINMENULAYER_MAINLAYER);

	// get node
	auto nodePlayer = dynamic_cast<Node*>(rootNode->getChildByName("FileNode_Player"));
	m_pPlayerAnimate = CSLoader::createTimeline("MainMenuPlayer.csb");
	nodePlayer->runAction(m_pPlayerAnimate);
	m_pPlayerAnimate->pause();
	auto nodeUp = dynamic_cast<Node*>(rootNode->getChildByName("Node_Up"));
	auto nodeDown = dynamic_cast<Node*>(rootNode->getChildByName("Node_Down"));

	// get text
	auto textGameTitle = dynamic_cast<Text*>(nodeUp->getChildByName("Text_GameTitle"));
	auto textPlay = dynamic_cast<Text*>(rootNode->getChildByName("Text_Play"));
	auto textHighscore = dynamic_cast<Text*>(nodeUp->getChildByName("Text_Highscore"));
	auto textGoldNumber = dynamic_cast<Text*>(nodeUp->getChildByName("Node_GoldNumber")->getChildByName("Text_GoldNumber"));
	
	// get button
	auto buttonSetting = dynamic_cast<Button*>(nodeUp->getChildByName("Button_Setting"));
	buttonSetting->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Setting, this));
	m_pButtonSignIn = dynamic_cast<Button*>(nodeDown->getChildByName("Button_SignIn"));
	m_pButtonSignIn->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_SignIn, this));
	m_pButtonAchievement = dynamic_cast<Button*>(nodeDown->getChildByName("Button_Achievement"));
	m_pButtonAchievement->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Achievement, this));
	m_pButtonLeaderboard = dynamic_cast<Button*>(nodeDown->getChildByName("Button_Leaderboard"));
    m_pButtonLeaderboard->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Leaderboard, this));
	auto buttonPurchaseNoAd = dynamic_cast<Button*>(nodeDown->getChildByName("Button_Purchase_noAd"));
	buttonPurchaseNoAd->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_PurchaseNoAd, this));
	auto buttonUpgrade = dynamic_cast<Button*>(rootNode->getChildByName("Button_Upgrade"));
	buttonUpgrade->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Upgrade, this));
	auto buttonReload = dynamic_cast<Button*>(rootNode->getChildByName("Button_Reload"));
	buttonReload->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Reload, this));
    auto buttonPurchase = dynamic_cast<Button*>(rootNode->getChildByName("Button_TestPurchase"));
    buttonPurchase->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Purchase, this));
    auto buttonReset = dynamic_cast<Button*>(rootNode->getChildByName("Button_ResetGameCenter"));
    buttonReset->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Reset, this));
	// set button
	m_pButtonAchievement->setPositionY(-200);
	m_pButtonLeaderboard->setPositionY(-200);

#if DEBUGFLAG == 0
    buttonReload->setVisible(false);
    buttonPurchase->setVisible(false);
    buttonReset->setVisible(false);
#endif
	if (!m_pGameMediator->getIsAd()) {
		buttonPurchaseNoAd->setEnabled(false);
		buttonPurchaseNoAd->setVisible(false);
	}
	else {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		auto listener = EventListenerCustom::create(EVENT_GAMECENTER_AUTHENTICATED, [=](EventCustom* event) {
			// change game center buttons when authenticated
            m_pButtonAchievement->runAction(MoveTo::create(0.5f, cocos2d::Point(m_pButtonAchievement->getPositionX(), 10)));
			m_pButtonLeaderboard->runAction(MoveTo::create(0.5f, cocos2d::Point(m_pButtonLeaderboard->getPositionX(), 10)));
			m_pButtonSignIn->runAction(MoveTo::create(0.5f, cocos2d::Point(m_pButtonSignIn->getPositionX(), -200)));
			// load iap & request products
			IAPHelper* helper = [IAPShare sharedHelper].iap;
			Reachability *reach = [Reachability reachabilityForInternetConnection];
			NetworkStatus netStatus = [reach currentReachabilityStatus];
			if (netStatus == NotReachable) {
				NSLog(@"No internet connection!");
			}
			else {
				if (helper.products == nil) {
					helper.production = NO; // No for test, YES for release
					[helper requestProductsWithCompletion : ^ (SKProductsRequest* request, SKProductsResponse* response) {
						if (response > 0) {
							// check is purcahsed
							if ([helper isPurchasedProductsIdentifier : @"com.reallycsc.endlesslove.adremove"] == YES) 
							{
								m_pGameMediator->setIsAd(false);
								m_pGameMediator->setIsGuidelineForever(true);
								buttonPurchaseNoAd->setEnabled(false);
								buttonPurchaseNoAd->setVisible(false);
							}
						}
					}];
				}
				else {
					// check is purcahsed
					if ([helper isPurchasedProductsIdentifier : @"com.reallycsc.endlesslove.adremove"] == YES) 
					{
						m_pGameMediator->setIsAd(false);
						m_pGameMediator->setIsGuidelineForever(true);
						buttonPurchaseNoAd->setEnabled(false);
						buttonPurchaseNoAd->setVisible(false);
					}
				}
			}
		});
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
#endif
	}
	// set all text
	auto mapGameText = m_pGameMediator->getGameText();
	textGameTitle->setString(mapGameText->at("ID_COMMON_GAMETITLE"));
	textPlay->setString(mapGameText->at("ID_MAINMENU_PLAY"));
    textGoldNumber->setString(StringUtils::format("%lld", m_pPlayerData->getGoldNumberAll()));
	textHighscore->setString(StringUtils::format("%s%lld",
                                                    mapGameText->at("ID_COMMON_HIGHSCORE").c_str(),
                                                    m_pPlayerData->getHighscore()));

	// add event listener
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    auto listener = EventListenerCustom::create(EVENT_PLARERDATA_SCOREUPDATED+"Highscore", [=](EventCustom* event){
        textHighscore->setString(StringUtils::format("%s%lld",
			m_pGameMediator->getGameText()->at("ID_COMMON_HIGHSCORE").c_str(),
			m_pPlayerData->getHighscore()));
    });
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    listener = EventListenerCustom::create(EVENT_PLARERDATA_SCOREUPDATED+"GoldNumber", [=](EventCustom* event){
        textGoldNumber->setString(StringUtils::format("%lld", m_pPlayerData->getGoldNumberAll()));
    });
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
#endif

	// Play animation & bind frame event
	m_pAnimate->play("Cardiogram_Play", true);

	// random blink
	this->runAction(Sequence::createWithTwoActions(
		DelayTime::create(random(1.0f, 5.0f)),
		CallFunc::create(CC_CALLBACK_0(MainMenuLayer::playerBlink, this))
		));
    
    return true;
}

// Event functions
bool MainMenuLayer::onTouchBegan(Touch *touch, Event *event)
{
	return true;
}

void MainMenuLayer::onTouchMoved(Touch *touch, Event *event)
{
}

void MainMenuLayer::onTouchEnded(Touch *touch, Event *event)
{
	m_pAnimate->play("Scene_End", false);
    Director::getInstance()->replaceScene(TransitionFade::create(0.5f, GameScene::create()));
}

// Callback functions
void MainMenuLayer::menuCallback_Upgrade(Ref* pSender)
{
    Director::getInstance()->replaceScene(TransitionSlideInB::create(0.5f,PlayerUpgradeScene::create()));
}

void MainMenuLayer::menuCallback_Setting(Ref* pSender)
{
	this->addChild(SettingLayer::create(), ZORDER_MAINMENULAYER_SETTINGLAYER);
}

void MainMenuLayer::menuCallback_SignIn(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    GameKitHelper* helper = [GameKitHelper sharedHelper];
    if (helper.isAuthenticated == YES) {
        // change game center buttons when authenticated
        m_pButtonAchievement->runAction(MoveTo::create(0.5f, cocos2d::Point(m_pButtonAchievement->getPositionX(), 10)));
        m_pButtonLeaderboard->runAction(MoveTo::create(0.5f, cocos2d::Point(m_pButtonLeaderboard->getPositionX(), 10)));
        m_pButtonSignIn->runAction(MoveTo::create(0.5f, cocos2d::Point(m_pButtonSignIn->getPositionX(), -200)));
    }
    else {
        [helper authenticateLocalUser];
    }
#endif
}

void MainMenuLayer::menuCallback_Leaderboard(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    GameKitHelper* helper = [GameKitHelper sharedHelper];
    [helper showLeaderboard : @"Highscore"];
#endif
}

void MainMenuLayer::menuCallback_Achievement(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    GameKitHelper* helper = [GameKitHelper sharedHelper];
    [helper showAchievements];
#endif
}

void MainMenuLayer::menuCallback_PurchaseNoAd(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	// load iap
	IAPHelper* helper = [IAPShare sharedHelper].iap;
	Reachability *reach = [Reachability reachabilityForInternetConnection];
	NetworkStatus netStatus = [reach currentReachabilityStatus];
	if (netStatus == NotReachable) {
		NSLog(@"No internet connection!");
	}
	else {
		if (helper.products == nil) {
			helper.production = NO; // No for test, YES for release
			[helper requestProductsWithCompletion : ^ (SKProductsRequest* request, SKProductsResponse* response) {
				if (response > 0) {
					[ProgressHUD dismiss];
					this->unschedule(schedule_selector(MainMenuLayer::waitingTimeOut));
                    this->realBuy(pSender);
				}
			}];
			[ProgressHUD show : [NSString stringWithCString:m_pmGameText->at("ID_IAP_DOWNLOAD").c_str()
                                                   encoding:NSUTF8StringEncoding]
                  Interaction : FALSE];
			this->scheduleOnce(schedule_selector(MainMenuLayer::waitingTimeOut), 10.0f);
		}
		else {
			// buy product
            this->realBuy(pSender);
		}
	}
#endif
}

void MainMenuLayer::playerBlink()
{
	this->runAction(Sequence::createWithTwoActions(
		DelayTime::create(random(1.0f, 5.0f)),
		CallFunc::create(CC_CALLBACK_0(MainMenuLayer::playerBlink, this))
		));
	m_pPlayerAnimate->play("Player_Blink", false);
}

void MainMenuLayer::realBuy(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    IAPHelper* helper = [IAPShare sharedHelper].iap;
    [ProgressHUD show : [NSString stringWithCString:m_pmGameText->at("ID_IAP_BUYING").c_str()
                                           encoding:NSUTF8StringEncoding]
          Interaction : FALSE];
    [helper buyProductWithID : @"com.reallycsc.endlesslove.adremove"
                onCompletion : ^ (SKPaymentTransaction* trans) {
                    [ProgressHUD dismiss];
                    if (trans.error) {
                        NSLog(@"Fail %@",[trans.error localizedDescription]);
                    }
                    else if (trans.transactionState == SKPaymentTransactionStatePurchased) {
                        [ProgressHUD show : [NSString stringWithCString:m_pmGameText->at("ID_IAP_CHECKRECEIPT").c_str()
                                                               encoding:NSUTF8StringEncoding]
                              Interaction : FALSE];
                        [helper checkReceipt : trans.transactionReceipt
                             AndSharedSecret : @"your sharesecret"
                                 onCompletion: ^ (NSString *response, NSError *error) {
                                     [ProgressHUD dismiss];
                                     if (response) {
                                         //Convert JSON String to NSDictionary
                                         NSDictionary* rec = [IAPShare toJSON : response];
                                         if ([rec[@"status"] integerValue] == 0) {
                                             [helper provideContentWithTransaction : trans];
                                             NSLog(@"SUCCESS %@",response);
                                             NSLog(@"Pruchases %@",helper.purchasedProducts);
                                             // buy success, proceed next step
                                             m_pGameMediator->setIsAd(false);
                                             m_pGameMediator->setIsGuidelineForever(true);
                                             [[GameKitHelper sharedHelper] checkAndUnlockAchievement:@"com.reallycsc.endlesslove.adremove"];
                                             Button* button = (Button*)pSender;
                                             button->setEnabled(false);
                                             button->setVisible(false);
                                         }
                                         else {
                                             [ProgressHUD showError : [NSString stringWithCString:m_pmGameText->at("ID_IAP_RECEIPTWRONG").c_str()
                                                                                         encoding:NSUTF8StringEncoding]];
                                             NSLog(@"Fail in response status is 0");
                                         }
                                     }
                                     else {
                                         [ProgressHUD showError : [NSString stringWithCString:m_pmGameText->at("ID_IAP_NORESPONSE").c_str()
                                                                                     encoding:NSUTF8StringEncoding]];
                                     }
                                 }];
                    }
                    else if (trans.transactionState == SKPaymentTransactionStateFailed) {
                        [ProgressHUD showError : [NSString stringWithCString:m_pmGameText->at("ID_IAP_NORECEIPT").c_str()
                                                                    encoding:NSUTF8StringEncoding]];
                        NSLog(@"Fail in SKPaymentTransactionStateFailed");
                    }
                }];//end of buy product
#endif
}

void MainMenuLayer::waitingTimeOut(float dt)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    [ProgressHUD showError : [NSString stringWithCString:m_pmGameText->at("ID_IAP_TIMEOUT").c_str()
                                                encoding:NSUTF8StringEncoding]];
#endif
}

// DEBUG only
void MainMenuLayer::menuCallback_Reload(Ref* pSender)
{
	GameMediator::getInstance()->reloadAllConfigFiles();
}

void MainMenuLayer::menuCallback_Purchase(Ref* pSender)
{
    this->addChild(PurchaseLayer::create(), ZORDER_MAINMENULAYER_PURCHASELAYER);
}

void MainMenuLayer::menuCallback_Reset(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    GameKitHelper* helper = [GameKitHelper sharedHelper];
    [helper reportScore:0 forLeaderboard:@"Highscore"];
    [helper reportScore:0 forLeaderboard:@"GoldNumber"];
    [helper reportScore:0 forLeaderboard:@"GoldNumberAll"];
    [helper reportScore:0 forLeaderboard:@"ReviveNumber"];
    [helper reportScore:0 forLeaderboard:@"DoubleNumber"];
    [helper resetAchievements];
#endif
}