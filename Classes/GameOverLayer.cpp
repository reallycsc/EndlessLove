#include "GameOverLayer.h"
#include "GameScene.h"
#include "MainMenuScene.h"

GameOverLayer::GameOverLayer(void)
{
	m_pGameMediator = GameMediator::getInstance();
	m_pMapGameText = m_pGameMediator->getGameText();

	m_pTextHighscore = NULL;
	m_pTextGoldNumber = NULL;
	m_pScrollStory = NULL;
	m_pTextStory = NULL;
	m_pAnimate = NULL;
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

	// load csb
	auto rootNode = CSLoader::createNode("GameOverLayer.csb");
	m_pAnimate = CSLoader::createTimeline("GameOverLayer.csb");
	rootNode->runAction(m_pAnimate);
	this->addChild(rootNode);

	// get botton
	auto buttonRetry = dynamic_cast<Button*>(rootNode->getChildByName("Button_Retry"));
	buttonRetry->addClickEventListener(CC_CALLBACK_1(GameOverLayer::menuCallback_Retry, this));
	auto buttonMainMenu = dynamic_cast<Button*>(rootNode->getChildByName("Button_MainMenu"));
	buttonMainMenu->addClickEventListener(CC_CALLBACK_1(GameOverLayer::menuCallback_MainMenu, this));

	// get score text
	m_pTextHighscore = dynamic_cast<Text*>(rootNode->getChildByName("Node_EnlargeAnimation")->getChildByName("Text_Highscore"));
	m_pTextGoldNumber = dynamic_cast<Text*>(rootNode->getChildByName("Node_EnlargeAnimation")->getChildByName("Node_GoldNumber")->getChildByName("Text_GoldNumber"));

	// get story text
	m_pScrollStory = dynamic_cast<ScrollView*>(rootNode->getChildByName("ScrollView_EndingStory"));
	m_pTextStory = dynamic_cast<Text*>(m_pScrollStory->getChildByName("Text_EndingStory"));

	// set all text
	dynamic_cast<Text*>(rootNode->getChildByName("Text_GameOver"))->setString(m_pMapGameText->at(GAMETEXT_GAMEOVERLAYER_TITLE));
	buttonRetry->setTitleText(m_pMapGameText->at(GAMETEXT_GAMEOVERLAYER_RETRY));
	buttonMainMenu->setTitleText(m_pMapGameText->at(GAMETEXT_GAMEOVERLAYER_MAINMENU));

	this->showScoreAndStory();

    return true;
}

void GameOverLayer::showScoreAndStory()
{
	
	auto playerData = m_pGameMediator->getPlayerData();

	// update highest score
	playerData->savePlayerData();

	//显示最高分
	m_pTextHighscore->setString(String::createWithFormat("%s%d", 
		m_pMapGameText->at(GAMETEXT_MAINMENU_HIGHESTSCORE).c_str(),
		playerData->getHighscore()
		)->getCString());
	m_pTextGoldNumber->setString(String::createWithFormat("X %d", playerData->getGoldNumber())->getCString());

	m_pAnimate->gotoFrameAndPlay(0, false);

	map<int, vector<string>>* map = m_pGameMediator->getGameStory();

	vector<string>* storyVector = &(map->at(m_pGameMediator->getGameOverReason()));;

    m_pTextStory->setString((*storyVector)[cocos2d::random() % storyVector->size()]);
	m_pScrollStory->setInnerContainerSize(Size(m_pScrollStory->getInnerContainerSize().width, m_pTextStory->getContentSize().height));
	m_pTextStory->setPosition(Point(10, m_pScrollStory->getInnerContainerSize().height - 10));
}

void GameOverLayer::menuCallback_Retry(Ref* pSender)
{
	Director::getInstance()->getTextureCache()->removeTextureForKey("GameOverImage");
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
	Director::getInstance()->replaceScene(GameScene::create());
}

void GameOverLayer::menuCallback_MainMenu(Ref* pSender)
{
	Director::getInstance()->getTextureCache()->removeTextureForKey("GameOverImage");
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
	Director::getInstance()->replaceScene(MainMenuScene::create());
}