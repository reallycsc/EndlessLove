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
		Sprite* sprite = Sprite::createWithTexture(TextureCache::getInstance()->getTextureForKey("GameOverImage"));
		sprite->setPosition(winSize.width / 2, winSize.height / 2); //����λ�á�
		GameMediator::getInstance()->spriteToGray(sprite, 0); //ͼƬ��ɫ���ɫ
		this->addChild(sprite, ZORDER_GAMEOVERSCENE_SCREENSHOT);

		auto gameOverLayer = GameOverLayer::create();
		CC_BREAK_IF(!gameOverLayer);

		this->addChild(gameOverLayer, ZORDER_GAMEOVERSCENE_GAMEOVERLAYER);

        bRet = true;
    } while (0);
  
    return bRet;
}  
