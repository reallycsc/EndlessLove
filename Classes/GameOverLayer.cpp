#include "GameOverLayer.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "CSCClass/CommonFunctions.h"
#include "CSCClass/CSCAction/TextNumChange.h"
#include "NormalNoticeLayer.h"

GameOverLayer::GameOverLayer(void)
{
	m_pGameMediator = GameMediator::getInstance();
	m_pPlayerData = m_pGameMediator->getPlayerData();
	m_pMapGameText = m_pGameMediator->getGameText();

	m_pLayout = NULL;
	m_pTextHighscore = NULL;
	m_pTextGoldNumber = NULL;
	m_pAnimate = NULL;
	m_pButtonRetry = NULL;
	m_pButtonMainMenu = NULL;
	m_pButtonRevive = NULL;
	m_pButtonDoubleCoin = NULL;
    m_pSpriteRevivePlay = NULL;
    m_pSpriteDoublePlay = NULL;

	m_nHighscore = 0;
}


GameOverLayer::~GameOverLayer(void)
{
    m_pLayout = NULL;
    m_pTextHighscore = NULL;
    m_pTextGoldNumber = NULL;
    m_pAnimate = NULL;
    m_pButtonRetry = NULL;
    m_pButtonMainMenu = NULL;
    m_pButtonRevive = NULL;
    m_pButtonDoubleCoin = NULL;
    m_pSpriteRevivePlay = NULL;
    m_pSpriteDoublePlay = NULL;
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    sdkbox::PluginVungle::removeListener();
#endif
}

bool GameOverLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    cocos2d::Size winSize = Director::getInstance()->getWinSize();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    sdkbox::PluginVungle::init();
    sdkbox::PluginVungle::setListener(this);
#endif

	// load csb
	auto rootNode = CSLoader::createNode("GameOverLayer.csb");
	m_pAnimate = CSLoader::createTimeline("GameOverLayer.csb");
	rootNode->runAction(m_pAnimate);
	this->addChild(rootNode);

	m_pLayout = dynamic_cast<Layout*>(rootNode->getChildByName("Panel_GameOver"));
	// get botton
	m_pButtonRetry = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_Retry"));
	m_pButtonRetry->addClickEventListener(CC_CALLBACK_1(GameOverLayer::menuCallback_Retry, this));
	m_pButtonMainMenu = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_MainMenu"));
	m_pButtonMainMenu->addClickEventListener(CC_CALLBACK_1(GameOverLayer::menuCallback_MainMenu, this));
	m_pButtonRevive = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_Revive"));
    m_pSpriteRevivePlay = dynamic_cast<Sprite*>(m_pButtonRevive->getChildByName("Sprite_playAd"));
	m_pButtonRevive->addClickEventListener(CC_CALLBACK_1(GameOverLayer::menuCallback_Revive, this));
	m_pButtonDoubleCoin = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_DoubleCoin"));
    m_pSpriteDoublePlay = dynamic_cast<Sprite*>(m_pButtonDoubleCoin->getChildByName("Sprite_playAd"));
	m_pButtonDoubleCoin->addClickEventListener(CC_CALLBACK_1(GameOverLayer::menuCallback_DoubleGold, this));
    
	// if revive number get to max, disable the revive button
	if (m_pGameMediator->getReviveNumber() > 0)
	{
		m_pButtonRevive->setVisible(false);
		m_pButtonDoubleCoin->setPositionX(m_pLayout->getContentSize().width / 2);
	}
	// if gold == 0, disable the double button
	if (m_pPlayerData->getGoldNumber() == 0)
	{
		m_pButtonDoubleCoin->setVisible(false);
		m_pButtonRevive->setPositionX(m_pLayout->getContentSize().width / 2);
	}
    // if purchased noAd, noAd icon
    if(!m_pGameMediator->getIsAd())
    {
        m_pSpriteRevivePlay->setVisible(false);
        m_pSpriteDoublePlay->setVisible(false);
    }
	else
	{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		if (!sdkbox::PluginVungle::isCacheAvailable())
		{
			// if vungle not ready
            m_pSpriteRevivePlay->setColor(Color3B(77, 77, 77));
            m_pSpriteDoublePlay->setColor(Color3B(77, 77, 77));
		}
#endif
	}

	// get score text
	m_pTextHighscore = dynamic_cast<Text*>(m_pLayout->getChildByName("Node_EnlargeAnimation")->getChildByName("Text_Highscore"));
	m_pTextGoldNumber = dynamic_cast<Text*>(m_pLayout->getChildByName("Node_EnlargeAnimation")->getChildByName("Node_GoldNumber")->getChildByName("Text_GoldNumber"));

	// set all text
	dynamic_cast<Text*>(m_pLayout->getChildByName("Text_GameOver"))->setString(m_pMapGameText->at("ID_GAMEOVER_TITLE"));
	m_pButtonRetry->setTitleText(m_pMapGameText->at("ID_GAME_RETRY"));
	m_pButtonMainMenu->setTitleText(m_pMapGameText->at("ID_GAME_MAINMENU"));
	m_pButtonRevive->setTitleText(m_pMapGameText->at("ID_GAMEOVER_REVIVE"));

	// run animation
    m_pLayout->setPosition(cocos2d::Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height));
    m_pLayout->runAction(MoveTo::create(0.2f, cocos2d::Point(winSize.width / 2, winSize.height / 2)));

	this->showScore();

    return true;
}

void GameOverLayer::showScore() const
{
	auto playerData = m_pGameMediator->getPlayerData();

	// update highscore
    playerData->finishGameAddScore();
    
	m_pTextHighscore->setString(StringUtils::format("%s%lld",
		m_pMapGameText->at("ID_COMMON_HIGHSCORE").c_str(),
		playerData->getHighscore()
		));
	m_pTextGoldNumber->setString(StringUtils::format("%d", playerData->getGoldNumber()));

	m_pAnimate->gotoFrameAndPlay(0, false);
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
void GameOverLayer::onVungleCacheAvailable()
{
    if (m_pSpriteRevivePlay && m_pSpriteDoublePlay)
    {
        CCLOG("Video loaded");
        m_pSpriteRevivePlay->setColor(Color3B(255, 255, 255));
        m_pSpriteDoublePlay->setColor(Color3B(255, 255, 255));
    }
}

void GameOverLayer::onVungleStarted()
{
    CCLOG("Video started");
}

void GameOverLayer::onVungleFinished()
{
    CCLOG("Video finished");
}

void GameOverLayer::onVungleAdViewed(bool isComplete)
{
    CCLOG("Video viewed");
    if (isComplete) {
        CCLOG("Complete");
    }
    else {
        CCLOG("Not Complete");
    }
}

void GameOverLayer::onVungleAdReward(const std::string& name)
{
    if (name.compare("revive") == 0) {
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([=](){
            CCLOG("%s", name.c_str());
            this->realRevive();
        });
    }
    else if (name.compare("double") == 0) {
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([=](){
            CCLOG("%s", name.c_str());
            this->realDouble();
        });
    }
}
#endif

void GameOverLayer::menuCallback_Retry(Ref* pSender)
{
    // update gold
    m_pGameMediator->getPlayerData()->finishGameAddGoldNumber();
    
    cocos2d::Size winSize = Director::getInstance()->getWinSize();
	m_pLayout->runAction(Sequence::create(
                                          MoveTo::create(0.2f, cocos2d::Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
                                          CallFuncN::create([=](Ref* pSender)->void
    {
        Director::getInstance()->getTextureCache()->removeTextureForKey("GameOverImage");
        Director::getInstance()->popScene();
		Director::getInstance()->replaceScene(TransitionFade::create(0.5f, GameScene::create()));
	}),
		NULL));
}

void GameOverLayer::menuCallback_MainMenu(Ref* pSender)
{
    // update gold
    m_pGameMediator->getPlayerData()->finishGameAddGoldNumber();
    
    cocos2d::Size winSize = Director::getInstance()->getWinSize();
	m_pLayout->runAction(Sequence::create(
                                          MoveTo::create(0.2f, cocos2d::Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
                                          CallFuncN::create([=](Ref* pSender)->void
	{
		Director::getInstance()->getTextureCache()->removeTextureForKey("GameOverImage");
        Director::getInstance()->popScene();
        Director::getInstance()->replaceScene(TransitionFade::create(0.5f, MainMenuScene::create()));
	}),
		NULL));
}

void GameOverLayer::menuCallback_Revive(Ref* pSender)
{
    if (m_pGameMediator->getIsAd()) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        // Show some Ad
        if (sdkbox::PluginVungle::isCacheAvailable())
        {
            sdkbox::PluginVungle::show("revive");
        }
        else
        {
            // tell player video is not ready
            this->addChild(NormalNoticeLayer::create(
                                                     m_pMapGameText->at("ID_NOTICE_TITLE"),
                                                     m_pMapGameText->at("ID_NOTICE_NOVUNGLE")));
        }
#else
		this->realRevive();
#endif
    }
    else {
        this->realRevive();
    }
}

void GameOverLayer::realRevive()
{
    cocos2d::Size winSize = Director::getInstance()->getWinSize();
    m_pGameMediator->getPlayerData()->initPlayerHeartNumber();
    m_pGameMediator->increaseReviveNumber();
	// update GameCenter Achievement
	long long reviveNum = m_pGameMediator->getPlayerData()->getReviveNumber();
	CSC_IOSHelper::GameCenter_checkAndUnlockAchievement("com.reallycsc.endlesslove.revive1");
    if (reviveNum > 1)
		CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.revive10", reviveNum * 10);
    if (reviveNum > 10)
		CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.revive50", reviveNum * 2);
    if (reviveNum > 50)
		CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.revive100", reviveNum);
    // close the ui & resume
	m_pLayout->runAction(Sequence::create(
		MoveTo::create(0.2f, cocos2d::Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
		CallFuncN::create([=](Ref* pSender)->void
	{
        Director::getInstance()->getTextureCache()->removeTextureForKey("GameOverImage");
        Director::getInstance()->popScene();
	}),
		NULL));
}

void GameOverLayer::menuCallback_DoubleGold(Ref* pSender)
{
    if (m_pGameMediator->getIsAd()) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        // Show some Ad
        if (sdkbox::PluginVungle::isCacheAvailable())
        {
            sdkbox::PluginVungle::show("double");
        }
        else
        {
            // tell player video is not ready
            this->addChild(NormalNoticeLayer::create(
                                                     m_pMapGameText->at("ID_NOTICE_TITLE"),
                                                     m_pMapGameText->at("ID_NOTICE_NOVUNGLE")));
        }
#else
		this->realDouble();
#endif
    }
    else {
        this->realDouble();
    }
}

void GameOverLayer::realDouble()
{
	// then double the gold
	auto playerData = m_pGameMediator->getPlayerData();
	int m_nFromGoldNumber = playerData->getGoldNumber();
	int m_nToGoldNumber = m_nFromGoldNumber * 2;
	float duration = 0.5f;
	m_pTextGoldNumber->runAction(Sequence::create(
		TextNumChange::create(duration, m_nFromGoldNumber, m_nToGoldNumber),
		DelayTime::create(0.5f),
		CallFuncN::create(CC_CALLBACK_1(GameOverLayer::menuCallback_MainMenu, this)),
		NULL));
	playerData->doublePlayerGoldNumber();

	// disable all buttons
	m_pButtonRetry->setEnabled(false);
	m_pButtonMainMenu->setEnabled(false);
	m_pButtonRevive->setEnabled(false);
	m_pButtonDoubleCoin->setEnabled(false);

    // update GameCenter Achievement
    long long doubleNum = playerData->getDoubleNumber();
	CSC_IOSHelper::GameCenter_checkAndUnlockAchievement("com.reallycsc.endlesslove.double1");
    if (doubleNum > 1)
		CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.double10", doubleNum * 10);
    if (doubleNum > 10)
		CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.double50", doubleNum * 2);
    if (doubleNum > 50)
		CSC_IOSHelper::GameCenter_unlockAchievementPercent("com.reallycsc.endlesslove.double100", doubleNum);
}