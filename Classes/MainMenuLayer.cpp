#include "MainMenuLayer.h"
#include "GameScene.h"
#include "PlayerUpgradeScene.h"

MainMenuLayer::MainMenuLayer(void)
{
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

	// load player data
	PlayerData* data = GameMediator::getInstance()->getPlayerData();

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

	auto buttonReload = dynamic_cast<Button*>(rootNode->getChildByName("Button_Reload"));
	buttonReload->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Reload, this));

	// get gold number
	dynamic_cast<Text*>(rootNode->getChildByName("Node_GoldNumber")->getChildByName("Text_GoldNumber"))
    ->setString(String::createWithFormat("%d", data->getGoldNumberAll())->getCString());

	// set all text
	auto mapGameText = GameMediator::getInstance()->getGameText();
	buttonStart->setTitleText(mapGameText->at(GAMETEXT_MAINMENU_STARTGAME));
	//buttonExit->setTitleText(mapGameText->at(GAMETEXT_MAINMENU_EXITGAME));
	buttonUpgrade->setTitleText(mapGameText->at(GAMETEXT_MAINMENU_PLAYERUPGRADE));
	dynamic_cast<Text*>(rootNode->getChildByName("Text_GameTitle"))->setString(mapGameText->at(GAMETEXT_MAINMENU_TITLE));
	dynamic_cast<Text*>(rootNode->getChildByName("Text_HighestScore"))->setString(String::createWithFormat("%s%d", 
			mapGameText->at(GAMETEXT_MAINMENU_HIGHESTSCORE).c_str(), 
			data->getHighscore())->getCString());

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

// DEBUG only
void MainMenuLayer::menuCallback_Reload(Ref* pSender)
{
	GameMediator::getInstance()->reloadAllConfigFiles();
}