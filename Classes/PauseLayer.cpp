#include "PauseLayer.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "ControlLayer.h"
#include "GameMediator.h"

PauseLayer::PauseLayer(void)
{
	m_pLayout = NULL;
}


PauseLayer::~PauseLayer(void)
{
}


bool PauseLayer::init()
{  
    bool bRet = false;  
    do
    {  
        CC_BREAK_IF(!Layer::init());  

		Size winSize = Director::getInstance()->getWinSize();

		// load csb
		auto rootNode = CSLoader::createNode("PauseLayer.csb");
		this->addChild(rootNode);

		// get button
		m_pLayout = dynamic_cast<Layout*>(rootNode->getChildByName("Panel_GamePaused"));
		auto buttonResume = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_Resume"));
		buttonResume->addClickEventListener(CC_CALLBACK_1(PauseLayer::menuCallback_Resume, this));
		auto buttonRetry = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_Retry"));
		buttonRetry->addClickEventListener(CC_CALLBACK_1(PauseLayer::menuCallback_Retry, this));
		auto buttonMainMenu = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_MainMenu"));
		buttonMainMenu->addClickEventListener(CC_CALLBACK_1(PauseLayer::menuCallback_MainMenu, this));

		// set all text
		auto mapGameText = GameMediator::getInstance()->getGameText();
		dynamic_cast<Text*>(m_pLayout->getChildByName("Text_Paused"))->setString(mapGameText->at(GAMETEXT_PAUSELAYER_TITLE));
		buttonResume->setTitleText(mapGameText->at(GAMETEXT_PAUSELAYER_RESUME));
		buttonRetry->setTitleText(mapGameText->at(GAMETEXT_GAMEOVERLAYER_RETRY));
		buttonMainMenu->setTitleText(mapGameText->at(GAMETEXT_GAMEOVERLAYER_MAINMENU));

		// run animation
		m_pLayout->setPosition(Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height));
		m_pLayout->runAction(MoveTo::create(0.2f, Point(winSize.width / 2, winSize.height / 2)));

        bRet = true;
    } while (0);  
  
    return bRet;  
}

void PauseLayer::menuCallback_Resume(Ref* pSender)
{
	Size winSize = Director::getInstance()->getWinSize();
	m_pLayout->runAction(Sequence::create(
		MoveTo::create(0.2f, Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
		CallFuncN::create([=](Ref* pSender)->void
	{
        Director::getInstance()->getTextureCache()->removeTextureForKey("GameOverImage");
        Director::getInstance()->getTextureCache()->removeUnusedTextures();
		Director::getInstance()->popScene(); 
	}),
		NULL));
}

void PauseLayer::menuCallback_Retry(Ref* pSender)
{
	Size winSize = Director::getInstance()->getWinSize();
    PlayerData* data = GameMediator::getInstance()->getPlayerData();
    data->finishGameAddGoldNumber();
    data->finishGameAddScore();
    
	m_pLayout->runAction(Sequence::create(
		MoveTo::create(0.2f, Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
		CallFuncN::create([=](Ref* pSender)->void
	{
        Director::getInstance()->getTextureCache()->removeTextureForKey("GameOverImage");
		Director::getInstance()->getTextureCache()->removeUnusedTextures();
		Director::getInstance()->popScene();
		Director::getInstance()->replaceScene(GameScene::create());
	}),
		NULL));
}

void PauseLayer::menuCallback_MainMenu(Ref* pSender)
{
	Size winSize = Director::getInstance()->getWinSize();
    // update gold
    PlayerData* data = GameMediator::getInstance()->getPlayerData();
    data->finishGameAddGoldNumber();
    data->finishGameAddScore();

	m_pLayout->runAction(Sequence::create(
		MoveTo::create(0.2f, Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
		CallFuncN::create([=](Ref* pSender)->void
	{
        Director::getInstance()->getTextureCache()->removeTextureForKey("GameOverImage");
		Director::getInstance()->getTextureCache()->removeUnusedTextures();
		Director::getInstance()->popScene();
        Director::getInstance()->replaceScene(TransitionSlideInL::create(0.5f, MainMenuScene::create()));
	}),
		NULL));
}