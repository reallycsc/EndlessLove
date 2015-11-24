#include "GameScene.h"
#include "GameLayer.h"

GameScene::GameScene(void)
{
}


GameScene::~GameScene(void)
{
}

bool GameScene::init()  
{  
    bool bRet = false;  
    do   
    {  
        CC_BREAK_IF(!Scene::init());

		GameLayer* gameLayer = GameLayer::create();
		this->addChild(gameLayer);

        bRet = true;
    } while (0);
  
    return bRet;
}