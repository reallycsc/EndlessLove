#include "GameOverScene.h"
#include "GameOverLayer.h"
#include "GameMediator.h"

GameOverScene::GameOverScene(void)
{
}


GameOverScene::~GameOverScene(void)
{
}

bool GameOverScene::init()
{  
    bool bRet = false;
    do   
    {  
        CC_BREAK_IF(!Scene::init());

		// show game over screenshot
		Size winSize = Director::getInstance()->getWinSize();
		Sprite* sprite = Sprite::createWithTexture(Director::getInstance()->getTextureCache()->getTextureForKey("GameOverImage"));
		sprite->setPosition(winSize.width / 2, winSize.height / 2);
		GameMediator::spriteToGray(sprite, 0); // change image to gray
		this->addChild(sprite);

		auto gameOverLayer = GameOverLayer::create();
		CC_BREAK_IF(!gameOverLayer);

		this->addChild(gameOverLayer);

        bRet = true;
    } while (0);
  
    return bRet;
}  
