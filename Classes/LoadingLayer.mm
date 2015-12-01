#include "LoadingLayer.h"
#include "MainMenuScene.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#import "IOSHelper/GameKitHelper.h"
#import "IOSHelper/IAPShare.h"
#include "PluginVungle/PluginVungle.h"
#endif

LoadingLayer::LoadingLayer(void)
{
	GameMediator::getInstance();
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

	// init Vungle
	sdkbox::PluginVungle::init();
#endif

	// load csb
	auto rootNode = CSLoader::createNode("LoadingScene.csb");
	auto animate = CSLoader::createTimeline("LoadingScene.csb");
	animate->setFrameEventCallFunc(CC_CALLBACK_1(LoadingLayer::onFrameEvent, this));
	rootNode->runAction(animate);
	animate->pause();
    this->addChild(rootNode);

	animate->play("Scene_Start", false);

    return true;
}

void LoadingLayer::onFrameEvent(Frame* frame)
{
	EventFrame* event = dynamic_cast<EventFrame*>(frame);
	if (!event)
		return;

	string str = event->getEvent();

	if (str == "sceneEnd")
	{
		Director::getInstance()->replaceScene(TransitionFade::create(0.5f, MainMenuScene::create()));
	}
}