#include "GameOverLayer.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "CSCClass\TextNumChange.h"

GameOverLayer::GameOverLayer(void)
{
	m_pGameMediator = GameMediator::getInstance();
	m_pMapGameText = m_pGameMediator->getGameText();

	m_pLayout = NULL;
	m_pTextHighscore = NULL;
	m_pTextGoldNumber = NULL;
	m_pScrollStory = NULL;
	m_pTextStory = NULL;
	m_pAnimate = NULL;
	m_pButtonRetry = NULL;
	m_pButtonMainMenu = NULL;
	m_pButtonRevive = NULL;
	m_pButtonDoubleCoin = NULL;

	m_nHighscore = 0;
}


GameOverLayer::~GameOverLayer(void)
{
}

bool GameOverLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	Size winSize = Director::getInstance()->getWinSize();

	// load csb
	auto rootNode = CSLoader::createNode("GameOverLayer.csb");
	m_pAnimate = CSLoader::createTimeline("GameOverLayer.csb");
	rootNode->runAction(m_pAnimate);
	this->addChild(rootNode);

	m_pLayout = dynamic_cast<Layout*>(rootNode->getChildByName("Panel_GameOver"));
	// get botton
	m_pButtonRetry = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_Retry"));
	m_pButtonRetry->addClickEventListener(CC_CALLBACK_1(GameOverLayer::menuCallback_Retry, this));
	m_pButtonMainMenu = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_MainMenu"));
	m_pButtonMainMenu->addClickEventListener(CC_CALLBACK_1(GameOverLayer::menuCallback_MainMenu, this));
	m_pButtonRevive = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_Revive"));
	m_pButtonRevive->addClickEventListener(CC_CALLBACK_1(GameOverLayer::menuCallback_Revive, this));
	m_pButtonDoubleCoin = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_DoubleCoin"));
	m_pButtonDoubleCoin->addClickEventListener(CC_CALLBACK_1(GameOverLayer::menuCallback_DoubleGold, this));
	// if revive number get to max, disable the button
	if (m_pGameMediator->getReviveNumber() > 0)
	{
		m_pButtonRevive->setVisible(false);
		m_pButtonDoubleCoin->setPositionX(m_pLayout->getContentSize().width / 2);
	}

	// get score text
	m_pTextHighscore = dynamic_cast<Text*>(m_pLayout->getChildByName("Node_EnlargeAnimation")->getChildByName("Text_Highscore"));
	m_pTextGoldNumber = dynamic_cast<Text*>(m_pLayout->getChildByName("Node_EnlargeAnimation")->getChildByName("Node_GoldNumber")->getChildByName("Text_GoldNumber"));

	// get story text
	//m_pScrollStory = dynamic_cast<ScrollView*>(m_pLayout->getChildByName("ScrollView_EndingStory"));
	//m_pTextStory = dynamic_cast<Text*>(m_pScrollStory->getChildByName("Text_EndingStory"));

	// set all text
	dynamic_cast<Text*>(m_pLayout->getChildByName("Text_GameOver"))->setString(m_pMapGameText->at(GAMETEXT_GAMEOVERLAYER_TITLE));
	m_pButtonRetry->setTitleText(m_pMapGameText->at(GAMETEXT_GAMEOVERLAYER_RETRY));
	m_pButtonMainMenu->setTitleText(m_pMapGameText->at(GAMETEXT_GAMEOVERLAYER_MAINMENU));
	m_pButtonRevive->setTitleText(m_pMapGameText->at(GAMETEXT_GAMEOVERLAYER_REVIVE));

	// run animation
	m_pLayout->setPosition(Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height));
	m_pLayout->runAction(MoveTo::create(0.2f, Point(winSize.width / 2, winSize.height / 2)));

	this->showScoreAndStory();

    return true;
}

void GameOverLayer::showScoreAndStory()
{
	auto playerData = m_pGameMediator->getPlayerData();

	// update highest score
	playerData->savePlayerData();

	m_pTextHighscore->setString(StringUtils::format("%s%lld",
		m_pMapGameText->at(GAMETEXT_MAINMENU_HIGHESTSCORE).c_str(),
		playerData->getHighscore()
		));
	m_pTextGoldNumber->setString(StringUtils::format("%d", playerData->getGoldNumber()));

	m_pAnimate->gotoFrameAndPlay(0, false);

	// show story
	//map<int, vector<string>>* map = m_pGameMediator->getGameStory();

	//vector<string>* storyVector = &(map->at(m_pGameMediator->getGameOverReason()));;

    //m_pTextStory->setString((*storyVector)[cocos2d::random() % storyVector->size()]);
	//m_pScrollStory->setInnerContainerSize(Size(m_pScrollStory->getInnerContainerSize().width, m_pTextStory->getContentSize().height));
	//m_pTextStory->setPosition(Point(10, m_pScrollStory->getInnerContainerSize().height - 10));
}

void GameOverLayer::menuCallback_Retry(Ref* pSender)
{
	Size winSize = Director::getInstance()->getWinSize();
	m_pLayout->runAction(Sequence::create(
		MoveTo::create(0.2f, Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
		CallFuncN::create([=](Ref* pSender)->void
	{
		Director::getInstance()->getTextureCache()->removeTextureForKey("GameOverImage");
		Director::getInstance()->getTextureCache()->removeUnusedTextures();
		Director::getInstance()->replaceScene(GameScene::create());
	}),
		NULL));
}

void GameOverLayer::menuCallback_MainMenu(Ref* pSender)
{
	Size winSize = Director::getInstance()->getWinSize();
	m_pLayout->runAction(Sequence::create(
		MoveTo::create(0.2f, Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
		CallFuncN::create([=](Ref* pSender)->void
	{
		Director::getInstance()->getTextureCache()->removeTextureForKey("GameOverImage");
		Director::getInstance()->getTextureCache()->removeUnusedTextures();
		Director::getInstance()->replaceScene(MainMenuScene::create());
	}),
		NULL));
}

void GameOverLayer::menuCallback_Revive(Ref* pSender)
{
	Size winSize = Director::getInstance()->getWinSize();
	m_pLayout->runAction(Sequence::create(
		MoveTo::create(0.2f, Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
		CallFuncN::create([=](Ref* pSender)->void
	{
		// Show some Ad

		// then revive
		m_pGameMediator->getPlayerData()->initPlayerHeartNumber();
		m_pGameMediator->increaseReviveNumber();
		Director::getInstance()->getTextureCache()->removeTextureForKey("GameOverImage");
		Director::getInstance()->getTextureCache()->removeUnusedTextures();
		Director::getInstance()->popScene();
	}),
		NULL));
}

void GameOverLayer::menuCallback_DoubleGold(Ref* pSender)
{
	// Show some Ad

	// then double the gold
	auto playerData = m_pGameMediator->getPlayerData();
	int m_nFromGoldNumber = playerData->getGoldNumber();
	int m_nToGoldNumber = m_nFromGoldNumber * 2;
	float duration = 0.5f;
	m_pTextGoldNumber->runAction(TextNumChange::create(duration, m_nFromGoldNumber, m_nToGoldNumber));
	playerData->doublePlayerGoldNumber();

	// disable all buttons
	m_pButtonRetry->setEnabled(false);
	m_pButtonMainMenu->setEnabled(false);
	m_pButtonRevive->setEnabled(false);
	m_pButtonDoubleCoin->setEnabled(false);

	// close the ui & goto mainmenu
	Size winSize = Director::getInstance()->getWinSize();
	m_pLayout->runAction(Sequence::create(
		DelayTime::create(duration + 0.5f),
		MoveTo::create(0.2f, Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
		CallFuncN::create([=](Ref* pSender)->void
	{
		Director::getInstance()->getTextureCache()->removeTextureForKey("GameOverImage");
		Director::getInstance()->getTextureCache()->removeUnusedTextures();
		Director::getInstance()->replaceScene(MainMenuScene::create());
	}),
		NULL));
}
