#include "MainMenuLayer.h"
#include "GameScene.h"
#include "PlayerUpgradeScene.h"
#include "PurchaseLayer.h"
#include "SettingLayer.h"
#include "Player.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#import "IOSHelper/IAPShare.h"
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
	auto buttonSignIn = dynamic_cast<Button*>(nodeDown->getChildByName("Button_SignIn"));
	buttonSignIn->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_SignIn, this));
	auto buttonAchievement = dynamic_cast<Button*>(nodeDown->getChildByName("Button_Achievement"));
	buttonAchievement->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Achievement, this));
	auto buttonLeaderboard = dynamic_cast<Button*>(nodeDown->getChildByName("Button_Leaderboard"));
    buttonLeaderboard->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Leaderboard, this));
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
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    GameKitHelper* helper = [GameKitHelper sharedHelper];
    if (helper.isAuthenticated == YES) {
        buttonAchievement->setPositionY(10);
        buttonLeaderboard->setPositionY(10);
        buttonSignIn->setPositionY(-200);
    }
    else {
        buttonAchievement->setPositionY(-200);
        buttonLeaderboard->setPositionY(-200);
        buttonSignIn->setPositionY(10);
        auto listener = EventListenerCustom::create(EVENT_GAMECENTER_AUTHENTICATED, [=](EventCustom* event) {
            // change game center buttons when authenticated
            buttonAchievement->runAction(MoveTo::create(0.5f, cocos2d::Point(buttonAchievement->getPositionX(), 10)));
            buttonLeaderboard->runAction(MoveTo::create(0.5f, cocos2d::Point(buttonLeaderboard->getPositionX(), 10)));
            buttonSignIn->runAction(MoveTo::create(0.5f, cocos2d::Point(buttonSignIn->getPositionX(), -200)));
        });
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    }
#endif

#if DEBUG_FLAG == 0
    buttonReload->setVisible(false);
    buttonPurchase->setVisible(false);
    buttonReset->setVisible(false);
#endif
	if (!m_pGameMediator->getIsAd()) {
        buttonPurchaseNoAd->setPositionY(-200);
	}
	else {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        // load iap & request products
        if ([[Reachability reachabilityForInternetConnection] currentReachabilityStatus] == NotReachable) {
            [ProgressHUD showError : @"No internet connection!"];
            NSLog(@"No internet connection!");
        }
        else {
#if IAPTEST_FLAG == 1
            [[IAPShare sharedHelper] requestProductWithID:@"com.reallycsc.endlesslove.adremove" isProduction: NO];
#else
            [[IAPShare sharedHelper] requestProductWithID:@"com.reallycsc.endlesslove.adremove" isProduction:YES];
#endif
        }
        
        auto listener = EventListenerCustom::create(EVENT_RESTORED_REMOVEAD + "com.reallycsc.endlesslove.adremove", [=](EventCustom* event) {
            m_pGameMediator->setIsAd(false);
            m_pGameMediator->setIsGuidelineForever(true);
            buttonPurchaseNoAd->runAction(MoveTo::create(0.5f, cocos2d::Point(buttonPurchaseNoAd->getPositionX(), -200)));
        });
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
        listener = EventListenerCustom::create(EVENT_PURCHASED_REMOVEAD + "com.reallycsc.endlesslove.adremove", [=](EventCustom* event) {
            m_pGameMediator->setIsAd(false);
            m_pGameMediator->setIsGuidelineForever(true);
            buttonPurchaseNoAd->runAction(MoveTo::create(0.5f, cocos2d::Point(buttonPurchaseNoAd->getPositionX(), -200)));
            [[GameKitHelper sharedHelper] checkAndUnlockAchievement:@"com.reallycsc.endlesslove.adremove"];
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
        Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_GAMECENTER_AUTHENTICATED);
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
	if ([[Reachability reachabilityForInternetConnection] currentReachabilityStatus] == NotReachable) {
        [ProgressHUD showError : @"No internet connection!"];
		NSLog(@"No internet connection!");
	}
	else {
        IAPHelper* helper = [IAPShare sharedHelper].iap;
		if (helper.products == nil) {
#if (IAPTEST_FLAG == 1)
            helper.production = NO; // No for test, YES for release
#else
            helper.production = YES; // No for test, YES for release
#endif
			[helper requestProductsWithCompletion : ^ (SKProductsRequest* request, SKProductsResponse* response) {
				if (response > 0) {
                    // buy product
					[ProgressHUD dismiss];
					this->unschedule(schedule_selector(MainMenuLayer::waitingTimeOut));
                    [[IAPShare sharedHelper] buyProductWithID:@"com.reallycsc.endlesslove.adremove"];
				}
			}];
			[ProgressHUD show : [NSString stringWithCString:m_pmGameText->at("ID_IAP_DOWNLOAD").c_str()
                                                   encoding:NSUTF8StringEncoding]
                  Interaction : FALSE];
			this->scheduleOnce(schedule_selector(MainMenuLayer::waitingTimeOut), 10.0f);
		}
		else {
			// buy product
            [[IAPShare sharedHelper] buyProductWithID:@"com.reallycsc.endlesslove.adremove"];
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