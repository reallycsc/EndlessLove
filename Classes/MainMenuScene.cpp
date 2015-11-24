#include "MainMenuScene.h"
#include "BackLayer.h"
#include "MainMenuLayer.h"

MainMenuScene::MainMenuScene(void)
{
}


MainMenuScene::~MainMenuScene(void)
{
}

bool MainMenuScene::init()  
{  
    bool bRet = false;  
    do   
    {  
        CC_BREAK_IF(!Scene::init());

		Size winSize = Director::getInstance()->getWinSize();
		// add backlayer
		BackLayer* backLayer = BackLayer::create();
		CC_BREAK_IF(!backLayer);
		this->addChild(backLayer);

		// add mainmenuLayer
		auto mainMenuLayer = MainMenuLayer::create();
		CC_BREAK_IF(!mainMenuLayer);
		this->addChild(mainMenuLayer);

		backLayer->moveRandomBackSprite();

        bRet = true;
    } while (0);
  
    return bRet;
}  
