#include "LoadingLayer.h"
#include "MainMenuScene.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#import "IOSHelper/GameKitHelper.h"
#import "IOSHelper/IAPShare.h"
#endif

LoadingLayer::LoadingLayer(void)
{
}


LoadingLayer::~LoadingLayer(void)
{
}

bool LoadingLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    cocos2d::Size winSize = Director::getInstance()->getWinSize();
    
    GameMediator::getInstance();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    // Game Center login
    [[GameKitHelper sharedHelper] authenticateLocalUser];
    
    // init IAPHelper
    if(![IAPShare sharedHelper].iap) {
        NSSet *productIdentifiers = [NSSet setWithObjects:
                                     @"com.reallycsc.endlesslove.adremove",
                                     nil];
        [IAPShare sharedHelper].iap = [[IAPHelper alloc] initWithProductIdentifiers:productIdentifiers];
        
    }
#endif
    
	// load csb
	auto rootNode = CSLoader::createNode("LoadingScene.csb");
	
    rootNode->setOpacity(0);
    rootNode->runAction(Sequence::create(FadeIn::create(1.0f),
                                         DelayTime::create(0.5f),
                                         CallFunc::create(CC_CALLBACK_0(LoadingLayer::changeScene, this)),
                                         NULL));
    
    this->addChild(rootNode);
    
    return true;
}

void LoadingLayer::changeScene()
{
    Director::getInstance()->replaceScene(TransitionFade::create(0.5f, MainMenuScene::create()));
}