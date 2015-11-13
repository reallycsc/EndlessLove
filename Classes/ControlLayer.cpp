#include "ControlLayer.h"
#include "PauseScene.h"
#include "GameOverScene.h"

ControlLayer::ControlLayer(void)
{
	_gameMediator = GameMediator::getInstance();
	_buttonPause = NULL;
	_textTouchForStart = NULL;
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
		this->addChild(rootNode);

		// get button
		_buttonPause = dynamic_cast<Button*>(rootNode->getChildByName("Button_Pause"));
		_buttonPause->addClickEventListener(CC_CALLBACK_1(ControlLayer::menuCallback_Pause, this));
		_buttonPause->setEnabled(false);

		// get text
		_textTouchForStart = dynamic_cast<Text*>(rootNode->getChildByName("Text_TouchForStart"));

		// set all text
		auto mapGameText = _gameMediator->getGameText();
		_textTouchForStart->setString(mapGameText->at(GAMETEXT_CONTROLLAYER_TOUCHFORSTART));
		_buttonPause->setTitleText(mapGameText->at(GAMETEXT_CONTROLLAYER_PAUSEGAME));

        bRet = true;
    } while (0);  
  
    return bRet;  
}  

void ControlLayer::gameStart()
{
	_buttonPause->setEnabled(true);
	_textTouchForStart->setVisible(false);

	_gameMediator->setGameState(STATE_GAME_RUN);
}

void ControlLayer::gameOver()
{
	Size winSize = Director::getInstance()->getWinSize();
	RenderTexture* renderTexture = RenderTexture::create(winSize.width, winSize.height);
	//遍历Game类的所有子节点信息，画入renderTexture中。
	//这里类似截图。
	renderTexture->begin();
	Director::getInstance()->getRunningScene()->visit();
	renderTexture->end();

	Director::getInstance()->getRenderer()->render();//在3.0此处必须写上这个，否则newImage整张图片都为黑色,或者在下一帧获取  
	TextureCache::getInstance()->addImage(renderTexture->newImage(), "GameOverImage");

	Director::getInstance()->replaceScene(GameOverScene::create());
}

void ControlLayer::menuCallback_Pause(Ref* pSender)
{
	Size winSize = Director::getInstance()->getWinSize();
	RenderTexture* renderTexture = RenderTexture::create(winSize.width, winSize.height);
	//遍历Game类的所有子节点信息，画入renderTexture中。
	//这里类似截图。
	renderTexture->begin();
	Director::getInstance()->getRunningScene()->visit();
	renderTexture->end();
	//将游戏界面暂停，压入场景堆栈。并切换到GamePause界面
	CCDirector::sharedDirector()->pushScene(PauseScene::createScene(renderTexture));
}