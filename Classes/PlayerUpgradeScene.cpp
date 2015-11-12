#include "PlayerUpgradeScene.h"
#include "PlayerUpgradeLayer.h"

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

		auto layer = PlayerUpgradeLayer::create();
		CC_BREAK_IF(!layer);

		this->addChild(layer);

        bRet = true;
    } while (0);
  
    return bRet;
}  
