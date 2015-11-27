#include "LoadingScene.h"
#include "LoadingLayer.h"
#include "GameMediator.h"

LoadingScene::LoadingScene(void)
{
}


LoadingScene::~LoadingScene(void)
{
}

bool LoadingScene::init()
{  
    bool bRet = false;
    do   
    {  
        CC_BREAK_IF(!Scene::init());

		auto loadingLayer = LoadingLayer::create();
		CC_BREAK_IF(!loadingLayer);

		this->addChild(loadingLayer);

        bRet = true;
    } while (0);
  
    return bRet;
}  
