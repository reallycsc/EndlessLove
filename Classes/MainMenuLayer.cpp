#include "MainMenuLayer.h"
#include "GameScene.h"
#include "PlayerUpgradeScene.h"
#include "PurchaseLayer.h"
#include "SettingLayer.h"
#include "Player.h"
#include "CSCClass/CSC_IOSHelper.h"
#include <SimpleAudioEngine.h>

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

    Size winSize = Director::getInstance()->getWinSize();

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
#if DEBUG_FLAG == 0
	buttonReload->setVisible(false);
	buttonPurchase->setVisible(false);
	buttonReset->setVisible(false);
#endif
    if (CSC_IOSHelper::GameCenter_isAuthenticated()) {
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

	if (!m_pGameMediator->getIsAd()) {
        buttonPurchaseNoAd->setPositionY(-200);
	}
	else {
#if IAPTEST_FLAG == 1
		CSC_IOSHelper::IAP_requestAllPurchasedProducts(true);
#else
        CSC_IOSHelper::IAP_requestAllPurchasedProducts(false);
#endif
        auto listener = EventListenerCustom::create(EVENT_RESTORED + "com.reallycsc.endlesslove.adremove", [=](EventCustom* event) {
            m_pGameMediator->setIsAd(false);
            m_pGameMediator->setIsGuidelineForever(true);
            buttonPurchaseNoAd->runAction(MoveTo::create(0.5f, Point(buttonPurchaseNoAd->getPositionX(), -200)));
        });
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
        listener = EventListenerCustom::create(EVENT_PURCHASED + "com.reallycsc.endlesslove.adremove", [=](EventCustom* event) {
            m_pGameMediator->setIsAd(false);
            m_pGameMediator->setIsGuidelineForever(true);
            buttonPurchaseNoAd->runAction(MoveTo::create(0.5f, Point(buttonPurchaseNoAd->getPositionX(), -200)));
			CSC_IOSHelper::GameCenter_checkAndUnlockAchievement("com.reallycsc.endlesslove.adremove");
        });
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
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

	// Play animation & bind frame event
	m_pAnimate->play("Cardiogram_Play", true);

	// random blink
	this->runAction(Sequence::createWithTwoActions(
		DelayTime::create(random(1.0f, 5.0f)),
		CallFunc::create(CC_CALLBACK_0(MainMenuLayer::playerBlink, this))
		));

	// Play music
	CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1.0);
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(BACKGROUND_MUSIC_FILE.c_str(), true);
    
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
    if (CSC_IOSHelper::GameCenter_isAuthenticated()) {
        Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_GAMECENTER_AUTHENTICATED);
    }
    else {
		CSC_IOSHelper::GameCenter_authenticateLocalUser();
    }
}

void MainMenuLayer::menuCallback_Leaderboard(Ref* pSender)
{
	CSC_IOSHelper::GameCenter_showLeaderboard("Highscore");
}

void MainMenuLayer::menuCallback_Achievement(Ref* pSender)
{
	CSC_IOSHelper::GameCenter_showAchievements();
}

void MainMenuLayer::menuCallback_PurchaseNoAd(Ref* pSender)
{
#if (IAPTEST_FLAG == 1)
	CSC_IOSHelper::getInstance()->IAP_purchaseProduct(true, "com.reallycsc.endlesslove.adremove");
#else
	CSC_IOSHelper::getInstance()->IAP_purchaseProduct(false, "com.reallycsc.endlesslove.adremove");
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
	CSC_IOSHelper::GameCenter_reportScoreForLeaderboard("Highscore", 0);
	CSC_IOSHelper::GameCenter_reportScoreForLeaderboard("GoldNumber", 0);
	CSC_IOSHelper::GameCenter_reportScoreForLeaderboard("GoldNumberAll", 0);
	CSC_IOSHelper::GameCenter_reportScoreForLeaderboard("ReviveNumber", 0);
	CSC_IOSHelper::GameCenter_reportScoreForLeaderboard("DoubleNumber", 0);
	CSC_IOSHelper::GameCenter_resetAchievements();
}