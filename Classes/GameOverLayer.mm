#include "GameOverLayer.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "CSCClass/TextNumChange.h"
#include "NormalNoticeLayer.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#import "IOSHelper/GameKitHelper.h"
#endif

GameOverLayer::GameOverLayer(void)
{
	m_pGameMediator = GameMediator::getInstance();
	m_pMapGameText = m_pGameMediator->getGameText();

	m_pLayout = NULL;
	m_pTextHighscore = NULL;
	m_pTextGoldNumber = NULL;
	m_pScrollStory = NULL;
	m_pTextStory = NULL;
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
}

bool GameOverLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    cocos2d::Size winSize = Director::getInstance()->getWinSize();

    sdkbox::PluginVungle::setListener(this);
    
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
    
	// if revive number get to max, disable the button
	if (m_pGameMediator->getReviveNumber() > 0)
	{
		m_pButtonRevive->setVisible(false);
		m_pButtonDoubleCoin->setPositionX(m_pLayout->getContentSize().width / 2);
	}
    // if purchased noAd, noAd icon
    if(!m_pGameMediator->getIsAd())
    {
        m_pSpriteRevivePlay->setVisible(false);
        m_pSpriteDoublePlay->setVisible(false);
    }
    else if (!sdkbox::PluginVungle::isCacheAvailable())
    {
        // if vungle not ready
        GameMediator::spriteToGray(m_pSpriteRevivePlay, 0);
        GameMediator::spriteToGray(m_pSpriteDoublePlay, 0);
    }

	// get score text
	m_pTextHighscore = dynamic_cast<Text*>(m_pLayout->getChildByName("Node_EnlargeAnimation")->getChildByName("Text_Highscore"));
	m_pTextGoldNumber = dynamic_cast<Text*>(m_pLayout->getChildByName("Node_EnlargeAnimation")->getChildByName("Node_GoldNumber")->getChildByName("Text_GoldNumber"));

	// get story text
	//m_pScrollStory = dynamic_cast<ScrollView*>(m_pLayout->getChildByName("ScrollView_EndingStory"));
	//m_pTextStory = dynamic_cast<Text*>(m_pScrollStory->getChildByName("Text_EndingStory"));

	// set all text
	dynamic_cast<Text*>(m_pLayout->getChildByName("Text_GameOver"))->setString(m_pMapGameText->at(GAMETEXT_GAMEOVERLAYER_TITLE));
	m_pButtonRetry->setTitleText(m_pMapGameText->at(GAMETEXT_GAMEOVERLAYER_RETRY));
	m_pButtonMainMenu->setTitleText(m_pMapGameText->at(GAMETEXT_GAMEOVERLAYER_MAINMENU));
	m_pButtonRevive->setTitleText(m_pMapGameText->at(GAMETEXT_GAMEOVERLAYER_REVIVE));

	// run animation
    m_pLayout->setPosition(cocos2d::Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height));
    m_pLayout->runAction(MoveTo::create(0.2f, cocos2d::Point(winSize.width / 2, winSize.height / 2)));

	this->showScoreAndStory();

    return true;
}

void GameOverLayer::showScoreAndStory()
{
	auto playerData = m_pGameMediator->getPlayerData();

	// update highscore
    playerData->finishGameAddScore();
    
	m_pTextHighscore->setString(StringUtils::format("%s%lld",
		m_pMapGameText->at(GAMETEXT_MAINMENU_HIGHESTSCORE).c_str(),
		playerData->getHighscore()
		));
	m_pTextGoldNumber->setString(StringUtils::format("%d", playerData->getGoldNumber()));

	m_pAnimate->gotoFrameAndPlay(0, false);

	// show story
	//map<int, vector<string>>* map = m_pGameMediator->getGameStory();

	//vector<string>* storyVector = &(map->at(m_pGameMediator->getGameOverReason()));;

    //m_pTextStory->setString((*storyVector)[cocos2d::random() % storyVector->size()]);
	//m_pScrollStory->setInnerContainerSize(Size(m_pScrollStory->getInnerContainerSize().width, m_pTextStory->getContentSize().height));
	//m_pTextStory->setPosition(cocos2d::Point(10, m_pScrollStory->getInnerContainerSize().height - 10));
}

void GameOverLayer::onVungleCacheAvailable()
{
    if (this)
    {
        CCLOG("Video loaded");
        GameMediator::spriteToGray(m_pSpriteRevivePlay, 1);
        GameMediator::spriteToGray(m_pSpriteDoublePlay, 1);
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
		Director::getInstance()->getTextureCache()->removeUnusedTextures();
        Director::getInstance()->popScene();
		Director::getInstance()->replaceScene(GameScene::create());
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
		Director::getInstance()->getTextureCache()->removeUnusedTextures();
        Director::getInstance()->popScene();
        Director::getInstance()->replaceScene(TransitionSlideInL::create(0.5f, MainMenuScene::create()));
	}),
		NULL));
}

void GameOverLayer::menuCallback_Revive(Ref* pSender)
{
    if (m_pGameMediator->getIsAd()) {
        // Show some Ad
        if (sdkbox::PluginVungle::isCacheAvailable())
        {
            sdkbox::PluginVungle::show("revive");
        }
        else
        {
            // tell player video is not ready
            auto mapGameText = m_pGameMediator->getGameText();
            this->addChild(NormalNoticeLayer::create(
                                                     mapGameText->at(GAMETEXT_NORMALNOTICELAYER_NOTIFICATION),
                                                     "Vungle is not ready."),
                           ZORDER_UPGRADELAYER_NOTICELAYER);
        }
        
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
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    GameKitHelper* helper = [GameKitHelper sharedHelper];
    long long reviveNum = m_pGameMediator->getPlayerData()->getReviveNumber();
    [helper checkAndUnlockAchievement:@"com.reallycsc.endlesslove.revive1"];
    if (reviveNum > 1) {
        [helper unlockAchievementPercent:@"com.reallycsc.endlesslove.revive10" percentComplete:(reviveNum*10)];
    }
    if (reviveNum > 10) {
        [helper unlockAchievementPercent:@"com.reallycsc.endlesslove.revive50" percentComplete:(reviveNum*2)];
    }
    if (reviveNum > 50) {
        [helper unlockAchievementPercent:@"com.reallycsc.endlesslove.revive100" percentComplete:(reviveNum)];
    }
#endif
    // close the ui & resume
	m_pLayout->runAction(Sequence::create(
                                          MoveTo::create(0.2f, cocos2d::Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
                                          CallFuncN::create([=](Ref* pSender)->void
	{
        Director::getInstance()->getTextureCache()->removeTextureForKey("GameOverImage");
        Director::getInstance()->getTextureCache()->removeUnusedTextures();
        Director::getInstance()->popScene();
	}),
		NULL));
}

void GameOverLayer::menuCallback_DoubleGold(Ref* pSender)
{
    if (m_pGameMediator->getIsAd()) {
        // Show some Ad
        if (sdkbox::PluginVungle::isCacheAvailable())
        {
            sdkbox::PluginVungle::show("double");
        }
        else
        {
            // tell player video is not ready
            auto mapGameText = m_pGameMediator->getGameText();
            this->addChild(NormalNoticeLayer::create(
                                                     mapGameText->at(GAMETEXT_NORMALNOTICELAYER_NOTIFICATION),
                                                     "Vungle is not ready."),
                           ZORDER_UPGRADELAYER_NOTICELAYER);
        }
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
	m_pTextGoldNumber->runAction(TextNumChange::create(duration, m_nFromGoldNumber, m_nToGoldNumber));
	playerData->doublePlayerGoldNumber();

	// disable all buttons
	m_pButtonRetry->setEnabled(false);
	m_pButtonMainMenu->setEnabled(false);
	m_pButtonRevive->setEnabled(false);
	m_pButtonDoubleCoin->setEnabled(false);

    // update GameCenter Achievement
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    GameKitHelper* helper = [GameKitHelper sharedHelper];
    long long doubleNum = playerData->getDoubleNumber();
    [helper checkAndUnlockAchievement:@"com.reallycsc.endlesslove.double1"];
    if (doubleNum > 1) {
        [helper unlockAchievementPercent:@"com.reallycsc.endlesslove.double10" percentComplete:(doubleNum*10)];
    }
    if (doubleNum > 10) {
        [helper unlockAchievementPercent:@"com.reallycsc.endlesslove.double50" percentComplete:(doubleNum*2)];
    }
    if (doubleNum > 50) {
        [helper unlockAchievementPercent:@"com.reallycsc.endlesslove.double100" percentComplete:(doubleNum)];
    }
#endif
    
    // update gold
    playerData->finishGameAddGoldNumber();
    
	// close the ui & goto mainmenu
    cocos2d::Size winSize = Director::getInstance()->getWinSize();
	m_pLayout->runAction(Sequence::create(
                                          DelayTime::create(duration + 0.5f),
                                          MoveTo::create(0.2f, cocos2d::Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
                                          CallFuncN::create([=](Ref* pSender)->void
	{
		Director::getInstance()->getTextureCache()->removeTextureForKey("GameOverImage");
		Director::getInstance()->getTextureCache()->removeUnusedTextures();
        Director::getInstance()->popScene();
        Director::getInstance()->replaceScene(TransitionSlideInL::create(0.5f, MainMenuScene::create()));
	}),
		NULL));
}