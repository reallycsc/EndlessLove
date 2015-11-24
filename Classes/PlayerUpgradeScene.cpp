#include "PlayerUpgradeScene.h"
#include "PlayerUpgradeLayer.h"
#include "BackLayer.h"

PlayerUpgradeScene::PlayerUpgradeScene(void)
{
}


PlayerUpgradeScene::~PlayerUpgradeScene(void)
{
}

bool PlayerUpgradeScene::init()
{  
    bool bRet = false;  
    do   
    {  
        CC_BREAK_IF(!Scene::init());

		// add backlayer
		BackLayer* backLayer = BackLayer::create();
		CC_BREAK_IF(!backLayer);
		this->addChild(backLayer);
		backLayer->moveRandomBackSprite();

		auto layer = PlayerUpgradeLayer::create();
		CC_BREAK_IF(!layer);
		this->addChild(layer);

        bRet = true;
    } while (0);
  
    return bRet;
}  
