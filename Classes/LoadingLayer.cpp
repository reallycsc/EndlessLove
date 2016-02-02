#include "LoadingLayer.h"
#include "MainMenuScene.h"
#include "CSCClass/CSC_IOSHelper.h"
#include <SimpleAudioEngine.h>
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#import "PluginVungle/PluginVungle.h"
#endif

LoadingLayer::LoadingLayer(void)
{
	GameMediator::getInstance();
	CSCClass::CSC_IOSHelper::getInstance();
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
	// load music
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(BACKGROUND_MUSIC_FILE.c_str());

	CSCClass::CSC_IOSHelper::GameCenter_authenticateLocalUser();
	CSCClass::CSC_IOSHelper::GameCenter_retriveScoreFromLeaderboard("Highscore");
	CSCClass::CSC_IOSHelper::GameCenter_retriveScoreFromLeaderboard("GoldNumber");
	CSCClass::CSC_IOSHelper::GameCenter_retriveScoreFromLeaderboard("GoldNumberAll");
	CSCClass::CSC_IOSHelper::GameCenter_retriveScoreFromLeaderboard("ReviveNumber");
	CSCClass::CSC_IOSHelper::GameCenter_retriveScoreFromLeaderboard("DoubleNumber");

	vector<string> products;
	products.push_back("com.reallycsc.endlesslove.adremove");
	CSCClass::CSC_IOSHelper::IAP_initWithProductSet(&products);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
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

void LoadingLayer::onFrameEvent(Frame* frame) const
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
