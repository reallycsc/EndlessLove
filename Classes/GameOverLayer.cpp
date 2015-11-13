#include "GameOverLayer.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "GameMediator.h"

GameOverLayer::GameOverLayer(void)
{
	_textHighscore = NULL;
	_textGoldNumber = NULL;
	_scrollStory = NULL;
	_textStory = NULL;
	_animate = NULL;
	m_iHighestScore = 0;
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
	_animate = CSLoader::createTimeline("GameOverLayer.csb");
	rootNode->runAction(_animate);
	this->addChild(rootNode);

	// get botton
	auto buttonRetry = dynamic_cast<Button*>(rootNode->getChildByName("Button_Retry"));
	buttonRetry->addClickEventListener(CC_CALLBACK_1(GameOverLayer::menuCallback_Retry, this));
	auto buttonMainMenu = dynamic_cast<Button*>(rootNode->getChildByName("Button_MainMenu"));
	buttonMainMenu->addClickEventListener(CC_CALLBACK_1(GameOverLayer::menuCallback_MainMenu, this));

	// get score text
	_textHighscore = dynamic_cast<Text*>(rootNode->getChildByName("Node_EnlargeAnimation")->getChildByName("Text_Highscore"));
	_textGoldNumber = dynamic_cast<Text*>(rootNode->getChildByName("Node_EnlargeAnimation")->getChildByName("Node_GoldNumber")->getChildByName("Text_GoldNumber"));

	// get story text
	_scrollStory = dynamic_cast<ScrollView*>(rootNode->getChildByName("ScrollView_EndingStory"));
	_textStory = dynamic_cast<Text*>(_scrollStory->getChildByName("Text_EndingStory"));

	// set all text
	auto mapGameText = GameMediator::getInstance()->getGameText();
	dynamic_cast<Text*>(rootNode->getChildByName("Text_GameOver"))->setString(mapGameText->at(GAMETEXT_GAMEOVERLAYER_TITLE));
	buttonRetry->setTitleText(mapGameText->at(GAMETEXT_GAMEOVERLAYER_RETRY));
	buttonMainMenu->setTitleText(mapGameText->at(GAMETEXT_GAMEOVERLAYER_MAINMENU));

	this->showScoreAndStory();

    return true;
}

void GameOverLayer::showScoreAndStory()
{
	auto gameMediator = GameMediator::getInstance();
	auto playerData = gameMediator->getPlayerData();

	// update highest score
	playerData->savePlayerData();

	//显示最高分
	auto mapGameText = gameMediator->getGameText();
	_textHighscore->setString(String::createWithFormat("%s%d", 
		mapGameText->at(GAMETEXT_MAINMENU_HIGHESTSCORE).c_str(), 
		playerData->getHighscore()
		)->getCString());
	_textGoldNumber->setString(String::createWithFormat("X %d", playerData->getGoldNumber())->getCString());

	_animate->gotoFrameAndPlay(0, false);

	map<int, vector<string>>* map = gameMediator->getGameStory();

	vector<string>* storyVector = &(map->at(gameMediator->getGameOverReason()));;

	_textStory->setString((*storyVector)[random() % storyVector->size()]);
	_scrollStory->setInnerContainerSize(Size(_scrollStory->getInnerContainerSize().width, _textStory->getContentSize().height));
	_textStory->setPosition(Point(10, _scrollStory->getInnerContainerSize().height - 10));
}

void GameOverLayer::menuCallback_Retry(Ref* pSender)
{
	TextureCache::getInstance()->removeTextureForKey("GameOverImage");
	TextureCache::getInstance()->removeUnusedTextures();
	Director::getInstance()->replaceScene(GameScene::create());
}

void GameOverLayer::menuCallback_MainMenu(Ref* pSender)
{
	TextureCache::getInstance()->removeTextureForKey("GameOverImage");
	TextureCache::getInstance()->removeUnusedTextures();
	Director::getInstance()->replaceScene(MainMenuScene::create());
}