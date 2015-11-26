#include "PauseScene.h"
#include "PauseLayer.h"
#include "GameMediator.h"

PauseScene::PauseScene(void)
{
}


PauseScene::~PauseScene(void)
{
}

bool PauseScene::init()
{  
    bool bRet = false;
    do   
    {  
        CC_BREAK_IF(!Scene::init());

        // show game over screenshot
        Size winSize = Director::getInstance()->getWinSize();
        Sprite* sprite = Sprite::createWithTexture(Director::getInstance()->getTextureCache()->getTextureForKey("GameOverImage"));
        sprite->setPosition(winSize.width / 2, winSize.height / 2);
        this->addChild(sprite);

		auto pauseLayer = PauseLayer::create();
		CC_BREAK_IF(!pauseLayer);

		this->addChild(pauseLayer);

        bRet = true;
    } while (0);
  
    return bRet;
}  
