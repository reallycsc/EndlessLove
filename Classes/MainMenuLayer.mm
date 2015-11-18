#include "MainMenuLayer.h"
#include "GameScene.h"
#include "PlayerUpgradeScene.h"
#include "GameKitHelper.h"


MainMenuLayer::MainMenuLayer(void)
{
    m_pGameMediator = GameMediator::getInstance();
    m_pPlayerData = m_pGameMediator->getPlayerData();
    m_pTextHighscore = NULL;
}


MainMenuLayer::~MainMenuLayer(void)
{
}

bool MainMenuLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	// add scene
	auto rootNode = CSLoader::createNode("MainMenuScene.csb");
	this->addChild(rootNode);

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

	auto buttonReload = dynamic_cast<Button*>(rootNode->getChildByName("Button_Reload"));
	buttonReload->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Reload, this));
#ifndef DEBUG
    buttonReload->setVisible(false);
#endif
    
	// get gold number
	dynamic_cast<Text*>(rootNode->getChildByName("Node_GoldNumber")->getChildByName("Text_GoldNumber"))
    ->setString(StringUtils::format("%d", m_pPlayerData->getGoldNumberAll()));
    
    // get text
    m_pTextHighscore = dynamic_cast<Text*>(rootNode->getChildByName("Text_HighestScore"));

	// set all text
	auto mapGameText = m_pGameMediator->getGameText();
	buttonStart->setTitleText(mapGameText->at(GAMETEXT_MAINMENU_STARTGAME));
	//buttonExit->setTitleText(mapGameText->at(GAMETEXT_MAINMENU_EXITGAME));
	buttonUpgrade->setTitleText(mapGameText->at(GAMETEXT_MAINMENU_PLAYERUPGRADE));
	dynamic_cast<Text*>(rootNode->getChildByName("Text_GameTitle"))->setString(mapGameText->at(GAMETEXT_MAINMENU_TITLE));
	m_pTextHighscore->setString(StringUtils::format("%s%lld",
                                                    mapGameText->at(GAMETEXT_MAINMENU_HIGHESTSCORE).c_str(),
                                                    m_pPlayerData->getHighscore()));

    // add custom event lisenter
    auto listener = EventListenerCustom::create(EVENT_PLARERDATA_SCOREUPDATED, [=](EventCustom* event){
        m_pTextHighscore->setString(StringUtils::format("%s%lld",
                                                        m_pGameMediator->getGameText()->at(GAMETEXT_MAINMENU_HIGHESTSCORE).c_str(),
                                                        m_pPlayerData->getHighscore()));
    });
    _eventDispatcher->addEventListenerWithFixedPriority(listener, 1);

    return true;
}

void MainMenuLayer::menuCallback_Start(Ref* pSender)
{
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
	Director::getInstance()->replaceScene(GameScene::create()); 
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
	Director::getInstance()->replaceScene(PlayerUpgradeScene::create());
}

void MainMenuLayer::menuCallback_Leaderboard(Ref* pSender)
{
    GameKitHelper* helper = [GameKitHelper sharedHelper];
    [helper showLeaderboard : @"Highscore"];
}

void MainMenuLayer::menuCallback_Achievement(Ref* pSender)
{
    GameKitHelper* helper = [GameKitHelper sharedHelper];
    [helper showAchievements];
}

// DEBUG only
void MainMenuLayer::menuCallback_Reload(Ref* pSender)
{
	GameMediator::getInstance()->reloadAllConfigFiles();
}