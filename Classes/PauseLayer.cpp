#include "PauseLayer.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "ControlLayer.h"
#include "GameMediator.h"

PauseLayer::PauseLayer(void)
{
}


PauseLayer::~PauseLayer(void)
{
}


bool PauseLayer::init()
{  
    bool bRet = false;  
    do
    {  
        CC_BREAK_IF(!Layer::init());  

		// load csb
		auto rootNode = CSLoader::createNode("PauseLayer.csb");
		this->addChild(rootNode);

		// get button
		auto buttonResume = dynamic_cast<Button*>(rootNode->getChildByName("Button_Resume"));
		buttonResume->addClickEventListener(CC_CALLBACK_1(PauseLayer::menuCallback_Resume, this));
		auto buttonRetry = dynamic_cast<Button*>(rootNode->getChildByName("Button_Retry"));
		buttonRetry->addClickEventListener(CC_CALLBACK_1(PauseLayer::menuCallback_Retry, this));
		auto buttonMainMenu = dynamic_cast<Button*>(rootNode->getChildByName("Button_MainMenu"));
		buttonMainMenu->addClickEventListener(CC_CALLBACK_1(PauseLayer::menuCallback_MainMenu, this));

		// set all text
		auto mapGameText = GameMediator::getInstance()->getGameText();
		dynamic_cast<Text*>(rootNode->getChildByName("Text_Paused"))->setString(mapGameText->at(GAMETEXT_PAUSELAYER_TITLE));
		buttonResume->setTitleText(mapGameText->at(GAMETEXT_PAUSELAYER_RESUME));
		buttonRetry->setTitleText(mapGameText->at(GAMETEXT_GAMEOVERLAYER_RETRY));
		buttonMainMenu->setTitleText(mapGameText->at(GAMETEXT_GAMEOVERLAYER_MAINMENU));

        bRet = true;
    } while (0);  
  
    return bRet;  
}

void PauseLayer::menuCallback_Resume(Ref* pSender)
{
	Director::getInstance()->popScene();
}

void PauseLayer::menuCallback_Retry(Ref* pSender)
{
	GameMediator::getInstance()->getPlayerData()->savePlayerData();
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
	Director::getInstance()->replaceScene(GameScene::create());
}

void PauseLayer::menuCallback_MainMenu(Ref* pSender)
{
	GameMediator::getInstance()->getPlayerData()->savePlayerData();
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
	Director::getInstance()->replaceScene(MainMenuScene::create());
}