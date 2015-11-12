#include "MainMenuScene.h"
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

		auto mainMenuLayer = MainMenuLayer::create();
		CC_BREAK_IF(!mainMenuLayer);

		this->addChild(mainMenuLayer);

        bRet = true;
    } while (0);
  
    return bRet;
}  
