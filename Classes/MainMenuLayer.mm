#include "MainMenuLayer.h"
#include "GameScene.h"
#include "PlayerUpgradeScene.h"
#include "PurchaseLayer.h"

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

	// add scene
	auto rootNode = CSLoader::createNode("MainMenuScene.csb");
	this->addChild(rootNode, ZORDER_MAINMENULAYER_MAINLAYER);

	// get button
	auto buttonStart = dynamic_cast<Button*>(rootNode->getChildByName("Button_StartGame"));
	buttonStart->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Start, this));
	//auto buttonExit = dynamic_cast<Button*>(rootNode->getChildByName("Button_ExitGame"));
	//buttonExit->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Exit, this));
	auto buttonUpgrade = dynamic_cast<Button*>(rootNode->getChildByName("Button_Upgrade"));
	buttonUpgrade->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Upgrade, this));
    auto buttonLeaderboard = dynamic_cast<Button*>(rootNode->getChildByName("Button_Leaderboard"));
    buttonLeaderboard->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Leaderboard, this));
    auto buttonAchievement = dynamic_cast<Button*>(rootNode->getChildByName("Button_Achievement"));
    buttonAchievement->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Achievement, this));
	auto buttonPurchaseNoAd = dynamic_cast<Button*>(rootNode->getChildByName("Button_Purchase_noAd"));
	buttonPurchaseNoAd->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_PurchaseNoAd, this));

	auto buttonReload = dynamic_cast<Button*>(rootNode->getChildByName("Button_Reload"));
	buttonReload->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Reload, this));
    auto buttonPurchase = dynamic_cast<Button*>(rootNode->getChildByName("Button_TestPurchase"));
    buttonPurchase->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Purchase, this));
    auto buttonReset = dynamic_cast<Button*>(rootNode->getChildByName("Button_ResetGameCenter"));
    buttonReset->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Reset, this));
#if DEBUGFLAG == 0
    buttonReload->setVisible(false);
    buttonPurchase->setVisible(false);
    buttonReset->setVisible(false);
#endif
	// get text
    auto textGoldNumber = dynamic_cast<Text*>(rootNode->getChildByName("Node_GoldNumber")->getChildByName("Text_GoldNumber"));
    auto textHighscore = dynamic_cast<Text*>(rootNode->getChildByName("Text_HighestScore"));

	// set all text
	auto mapGameText = m_pGameMediator->getGameText();
	buttonStart->setTitleText(mapGameText->at(GAMETEXT_MAINMENU_STARTGAME));
	//buttonExit->setTitleText(mapGameText->at(GAMETEXT_MAINMENU_EXITGAME));
	buttonUpgrade->setTitleText(mapGameText->at(GAMETEXT_MAINMENU_PLAYERUPGRADE));
	buttonLeaderboard->setTitleText(mapGameText->at(GAMETEXT_MAINMENU_LEADERBOARD));
	buttonAchievement->setTitleText(mapGameText->at(GAMETEXT_MAINMENU_ACHIEVEMENT));
	dynamic_cast<Text*>(rootNode->getChildByName("Text_GameTitle"))->setString(mapGameText->at(GAMETEXT_MAINMENU_TITLE));
    textGoldNumber->setString(StringUtils::format("%lld", m_pPlayerData->getGoldNumberAll()));
	textHighscore->setString(StringUtils::format("%s%lld",
                                                    mapGameText->at(GAMETEXT_MAINMENU_HIGHESTSCORE).c_str(),
                                                    m_pPlayerData->getHighscore()));

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    // add custom event lisenter
    auto listener = EventListenerCustom::create(EVENT_PLARERDATA_SCOREUPDATED+"Highscore", [=](EventCustom* event){
        textHighscore->setString(StringUtils::format("%s%lld",
                                                        m_pGameMediator->getGameText()->at(GAMETEXT_MAINMENU_HIGHESTSCORE).c_str(),
                                                        m_pPlayerData->getHighscore()));
    });
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    listener = EventListenerCustom::create(EVENT_PLARERDATA_SCOREUPDATED+"GoldNumber", [=](EventCustom* event){
        textGoldNumber->setString(StringUtils::format("%lld", m_pPlayerData->getGoldNumberAll()));
    });
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
#endif
    
    if (!m_pGameMediator->getIsAd()) {
        buttonPurchaseNoAd->setEnabled(false);
        buttonPurchaseNoAd->setVisible(false);
    }
    else {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        listener = EventListenerCustom::create(EVENT_GAMECENTER_AUTHENTICATED, [=](EventCustom* event){
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
                            //this->unschedule(schedule_selector(MainMenuLayer::waitingTimeOut));
                            // check is purcahsed
                            if ([helper isPurchasedProductsIdentifier : @"com.reallycsc.endlesslove.adremove"] == YES) {
                                m_pGameMediator->setIsAd(false);
                                m_pGameMediator->setIsGuidelineForever(true);
                                buttonPurchaseNoAd->setEnabled(false);
                                buttonPurchaseNoAd->setVisible(false);
                            }
                        }
                    }];
                    //this->scheduleOnce(schedule_selector(MainMenuLayer::waitingTimeOut), 10.0f);
                }
                else {
                    // check is purcahsed
                    if ([helper isPurchasedProductsIdentifier : @"com.reallycsc.endlesslove.adremove"] == YES) {
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
    
    return true;
}

void MainMenuLayer::menuCallback_Start(Ref* pSender)
{
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
    Director::getInstance()->replaceScene(TransitionSlideInR::create(0.5f, GameScene::create()));
}

void MainMenuLayer::menuCallback_Exit(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif
	Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void MainMenuLayer::menuCallback_Upgrade(Ref* pSender)
{
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
    Director::getInstance()->replaceScene(TransitionSlideInL::create(0.5f,PlayerUpgradeScene::create()));
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
			[ProgressHUD show : [NSString stringWithCString:m_pmGameText->at(GAMETEXT_PROGRESSHUD_DOWNLOADINFO).c_str()
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

void MainMenuLayer::realBuy(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    IAPHelper* helper = [IAPShare sharedHelper].iap;
    [ProgressHUD show : [NSString stringWithCString:m_pmGameText->at(GAMETEXT_PROGRESSHUD_BUYING).c_str()
                                           encoding:NSUTF8StringEncoding]
          Interaction : FALSE];
    [helper buyProductWithID : @"com.reallycsc.endlesslove.adremove"
                onCompletion : ^ (SKPaymentTransaction* trans) {
                    [ProgressHUD dismiss];
                    if (trans.error) {
                        NSLog(@"Fail %@",[trans.error localizedDescription]);
                    }
                    else if (trans.transactionState == SKPaymentTransactionStatePurchased) {
                        [ProgressHUD show : [NSString stringWithCString:m_pmGameText->at(GAMETEXT_PROGRESSHUD_CHECKINGRECEPIT).c_str()
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
                                             [ProgressHUD showError : [NSString stringWithCString:m_pmGameText->at(GAMETEXT_PROGRESSHUD_RECEIPTSTATUSERROR).c_str()
                                                                                         encoding:NSUTF8StringEncoding]];
                                             NSLog(@"Fail in response status is 0");
                                         }
                                     }
                                     else {
                                         [ProgressHUD showError : [NSString stringWithCString:m_pmGameText->at(GAMETEXT_PROGRESSHUD_NORESPONSE).c_str()
                                                                                     encoding:NSUTF8StringEncoding]];
                                     }
                                 }];
                    }
                    else if (trans.transactionState == SKPaymentTransactionStateFailed) {
                        [ProgressHUD showError : [NSString stringWithCString:m_pmGameText->at(GAMETEXT_PROGRESSHUD_RECEIPTCHECKERROR).c_str()
                                                                    encoding:NSUTF8StringEncoding]];
                        NSLog(@"Fail in SKPaymentTransactionStateFailed");
                    }
                }];//end of buy product
#endif
}

void MainMenuLayer::waitingTimeOut(float dt)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    [ProgressHUD showError : [NSString stringWithCString:m_pmGameText->at(GAMETEXT_PROGRESSHUD_RESPONSETIMEOUT).c_str()
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
    PurchaseLayer* layer = PurchaseLayer::create();
    this->addChild(layer, ZORDER_MAINMENULAYER_PURCHASELAYER);
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