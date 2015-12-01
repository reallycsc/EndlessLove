#include "ControlLayer.h"
#include "PauseScene.h"

ControlLayer::ControlLayer(void)
{
}


ControlLayer::~ControlLayer(void)
{
}


bool ControlLayer::init()
{  
    bool bRet = false;  
    do
    {  
        CC_BREAK_IF(!Layer::init());  
		
        Size winSize = Director::getInstance()->getWinSize();
	
		// load csb
		auto rootNode = CSLoader::createNode("ControlLayer.csb");
		auto animate = CSLoader::createTimeline("ControlLayer.csb");
		rootNode->runAction(animate);
		animate->pause();
		this->addChild(rootNode);

		// get button
		auto buttonPause = dynamic_cast<Button*>(rootNode->getChildByName("Button_Pause"));
		buttonPause->addClickEventListener(CC_CALLBACK_1(ControlLayer::menuCallback_Pause, this));

		animate->play("Scene_Start", false);

        bRet = true;
    } while (0);  
  
    return bRet;  
}

void ControlLayer::menuCallback_Pause(Ref* pSender)
{
	Size visibleSize = Director::getInstance()->getWinSize();
	RenderTexture* renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height, Texture2D::PixelFormat::RGBA8888, GL_DEPTH24_STENCIL8);
	// Go through all child of Game class and draw in renderTexture
	// It's like screenshot
	renderTexture->begin();
	Director::getInstance()->getRunningScene()->visit();
	renderTexture->end();

	Director::getInstance()->getRenderer()->render();// Must add this for version 3.0 or image goes black  
	Director::getInstance()->getTextureCache()->addImage(renderTexture->newImage(), "GamePauseImage");

	// pause the game, push to scene stack and change to new scene
	// Don't forget to pop it
	Director::getInstance()->pushScene(PauseScene::create());
}