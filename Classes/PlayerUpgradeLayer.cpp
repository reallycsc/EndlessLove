#include "PlayerUpgradeLayer.h"
#include "MainMenuScene.h"
#include "NormalNoticeLayer.h"


PlayerUpgradeLayer::PlayerUpgradeLayer(void)
{
	m_pPlayer = NULL;
	m_pGoldNumberAll = NULL;

	m_mUpgradeItems.clear();
}

PlayerUpgradeLayer::~PlayerUpgradeLayer(void)
{
	m_mUpgradeItems.clear();
}

bool PlayerUpgradeLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	Size winSize = Director::getInstance()->getWinSize();
	PlayerData* data = GameMediator::getInstance()->getPlayerData();

	// add scene
	auto rootNode = CSLoader::createNode("PlayerUpgradeScene.csb");
	this->addChild(rootNode);

	// get button
	auto buttonMainMenu = dynamic_cast<Button*>(rootNode->getChildByName("Button_MainMenu"));
	buttonMainMenu->addClickEventListener(CC_CALLBACK_1(PlayerUpgradeLayer::menuCallback_MainMenu, this));

	// get gold number
	m_pGoldNumberAll = dynamic_cast<Text*>(rootNode->getChildByName("Node_GoldNumber")->getChildByName("Text_GoldNumber"));
	m_pGoldNumberAll->setString(StringUtils::format("%d", data->getGoldNumberAll()));

	// get guideline
	m_pSpriteGuideLine = dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_GuideLine"));

	// get upgrade items
	ScrollView* scrollItems = dynamic_cast<ScrollView*>(rootNode->getChildByName("ScrollView_UpgradeItems"));
	this->loadUpgradeItem(ID_JUMP_TYPE, dynamic_cast<Node*>(scrollItems->getChildByName("Node_JumpType")));
	m_mUpgradeItems.at(ID_JUMP_TYPE).button->addClickEventListener(CC_CALLBACK_1(PlayerUpgradeLayer::menuCallback_Upgrade_JumpType, this));
	this->loadUpgradeItem(ID_MAXHEART_NUMBER, dynamic_cast<Node*>(scrollItems->getChildByName("Node_MaxHeartNum")));
	this->loadUpgradeItem(ID_STRENGTH, dynamic_cast<Node*>(scrollItems->getChildByName("Node_Strength")));
	this->loadUpgradeItem(ID_POWER_TIME, dynamic_cast<Node*>(scrollItems->getChildByName("Node_PowerTime")));
	this->loadUpgradeItem(ID_GUIDELINE_TIME, dynamic_cast<Node*>(scrollItems->getChildByName("Node_GuidelineTime")));
	this->loadUpgradeItem(ID_ENLARGE_TIME, dynamic_cast<Node*>(scrollItems->getChildByName("Node_EnlargeTime")));
	this->loadUpgradeItem(ID_SHRINK_TIME, dynamic_cast<Node*>(scrollItems->getChildByName("Node_ShrinkTime")));
	this->loadUpgradeItem(ID_SHIELD_TIME, dynamic_cast<Node*>(scrollItems->getChildByName("Node_ShieldTime")));

	// set text
	auto mapGameText = GameMediator::getInstance()->getGameText();
	buttonMainMenu->setTitleText(mapGameText->at(GAMETEXT_GAMEOVERLAYER_MAINMENU));
	dynamic_cast<Text*>(rootNode->getChildByName("Text_Title"))->setString(mapGameText->at(GAMETEXT_MAINMENU_PLAYERUPGRADE));

	// get player data
	data->initPlayerData();

	// set ui content
	this->setAllItemContents();

	// Add Player
	data->setHeartNumber(data->getMaxHeartNumber());
	m_pPlayer = Player::create();
	m_pPlayer->setPosition((winSize.width - scrollItems->getContentSize().width) / 2, 0);
	//m_pPlayer->setGroundLevel(50);
	this->addChild(m_pPlayer);

	this->scheduleUpdate();

	GameMediator::getInstance()->setGameState(STATE_GAME_RUN);

    return true;
}

void PlayerUpgradeLayer::setItemContent(int id, int textid, const char* format1, const char* format2)
{
	PlayerData* data = GameMediator::getInstance()->getPlayerData();
	auto mapGameText = GameMediator::getInstance()->getGameText();
	unsigned int level = data->getLevelFor(id);
	auto pvLevelInfos = data->getLevelInfoVectorFor(id);
	auto tLevelConfig = pvLevelInfos->at(level - 1);
	float number = tLevelConfig.number;
	auto item = m_mUpgradeItems.at(id);
	if (level < pvLevelInfos->size())
	{
		float numberNext = pvLevelInfos->at(level).number;
		item.itemInfo->setString(mapGameText->at(textid));
		item.number->setString(StringUtils::format(format1, number, numberNext));
		item.button->setTitleText(mapGameText->at(GAMETEXT_PLAYERUPGRADE_UPGRADE));
		item.goldNum->setString(StringUtils::format("%d", tLevelConfig.needGold));
		item.button->setVisible(true);
		item.goldNum->setVisible(true);
		item.goldImg->setVisible(true);
		item.textMax->setVisible(false);
	}
	else
	{
		item.itemInfo->setString(mapGameText->at(textid));
		item.number->setString(StringUtils::format(format2, number));
		item.button->setVisible(false);
		item.goldNum->setVisible(false);
		item.goldImg->setVisible(false);
		item.textMax->setVisible(true);
	}
}

void PlayerUpgradeLayer::setAllItemContents()
{
	//setItemContent(ID_JUMP_TYPE, GAMETEXT_PLAYERUPGRADE_JUMPTYPE, "%s");
	setItemContent(ID_MAXHEART_NUMBER, GAMETEXT_PLAYERUPGRADE_MAXHEARTNUMBER, "%.1f -> %.1f", "%.1f");
	setItemContent(ID_STRENGTH, GAMETEXT_PLAYERUPGRADE_STRENGTH, "%.0f -> %.0f", "%.0f");
	setItemContent(ID_POWER_TIME, GAMETEXT_PLAYERUPGRADE_POWERTIME, "%.2f -> %.2f","%.2f");
	setItemContent(ID_GUIDELINE_TIME, GAMETEXT_PLAYERUPGRADE_GUIDELINETIME, "%.1f -> %.1f", "%.1f");
	setItemContent(ID_ENLARGE_TIME, GAMETEXT_PLAYERUPGRADE_ENLARGETIME, "%.1f -> %.1f", "%.1f");
	setItemContent(ID_SHRINK_TIME, GAMETEXT_PLAYERUPGRADE_SHRINKTIME, "%.1f -> %.1f", "%.1f");
	setItemContent(ID_SHIELD_TIME, GAMETEXT_PLAYERUPGRADE_SHIELDTIME, "%.1f -> %.1f", "%.1f");

	// set guideline position
	auto speed = GameMediator::getInstance()->getPlayerData()->getStrength();
	int positionY = (speed * speed) / (2 * GRAVITY);
	m_pSpriteGuideLine->setPositionY(positionY);
}

void PlayerUpgradeLayer::changeItemContentNumbers(int id, const char* format1, const char* format2)
{
	PlayerData* data = GameMediator::getInstance()->getPlayerData();
	unsigned int level = data->getLevelFor(id);
	auto pvLevelInfos = data->getLevelInfoVectorFor(id);
	auto tLevelConfig = pvLevelInfos->at(level - 1);
	float number = tLevelConfig.number;
	auto item = m_mUpgradeItems.at(id);
	if (level < pvLevelInfos->size())
	{
		float numberNext = pvLevelInfos->at(level).number;
		item.number->setString(StringUtils::format(format1, number, numberNext));
		item.goldNum->setString(StringUtils::format("%d", tLevelConfig.needGold));
		item.button->setVisible(true);
		item.goldNum->setVisible(true);
		item.goldImg->setVisible(true);
		item.textMax->setVisible(false);
	}
	else
	{
		item.number->setString(StringUtils::format(format2, number));
		item.button->setVisible(false);
		item.goldNum->setVisible(false);
		item.goldImg->setVisible(false);
		item.textMax->setVisible(true);
	}
}

void PlayerUpgradeLayer::changeAllItemContentsNumbers()
{
	//changeItemContentNumbers(ID_JUMP_TYPE, "%s");
	changeItemContentNumbers(ID_MAXHEART_NUMBER, "%.1f -> %.1f", "%.1f");
	changeItemContentNumbers(ID_STRENGTH, "%.0f -> %.0f", "%.0f");
	changeItemContentNumbers(ID_POWER_TIME, "%.2f -> %.2f", "%.2f");
	changeItemContentNumbers(ID_GUIDELINE_TIME, "%.1f -> %.1f", "%.1f");
	changeItemContentNumbers(ID_ENLARGE_TIME, "%.1f -> %.1f", "%.1f");
	changeItemContentNumbers(ID_SHRINK_TIME, "%.1f -> %.1f", "%.1f");
	changeItemContentNumbers(ID_SHIELD_TIME, "%.1f -> %.1f", "%.1f");

	// change guideline position
	auto speed = GameMediator::getInstance()->getPlayerData()->getStrength();
	int positionY = (speed * speed) / (2 * GRAVITY);
	m_pSpriteGuideLine->setPositionY(positionY);
}

void PlayerUpgradeLayer::update(float dt)
{
	// on ground start power up
	if (m_pPlayer->getIsOnTheGround() && !m_pPlayer->getIsPowerUp())
	{
		m_pPlayer->startPowerUp();
	}
	// start jump
	if (m_pPlayer->getCurPower() == MAXPOWER)
	{
		m_pPlayer->scheduleJump();
	}
}

void PlayerUpgradeLayer::menuCallback_MainMenu(Ref* pSender)
{
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
	Director::getInstance()->replaceScene(MainMenuScene::create());
}

void PlayerUpgradeLayer::menuCallback_Upgrade_JumpType(Ref* pSender)
{

}

void PlayerUpgradeLayer::menuCallback_Upgrade(Ref* pSender, int id)
{	
	PlayerData* data = GameMediator::getInstance()->getPlayerData();
	auto mapGameText = GameMediator::getInstance()->getGameText();
	auto levelConfigVector = data->getLevelInfoVectorFor(id);
	int level = data->getLevelFor(id);
	// reduce gold
	if (data->subGoldNumber(levelConfigVector->at(level - 1).needGold))
	{
		level++;
		data->setLevelFor(id, level);
		data->initPlayerData();
		this->changeAllItemContentsNumbers();
		m_pGoldNumberAll->setString(StringUtils::format("%d", data->getGoldNumberAll()));
		//data->savePlayerData();
	}
	else
	{
		// tell play gold is not enough
		NormalNoticeLayer* layer = NormalNoticeLayer::create(
			mapGameText->at(GAMETEXT_NORMALNOTICELAYER_NOTIFICATION),
			mapGameText->at(GAMETEXT_NORMALNOTICELAYER_NOTENOUGHGOLD)
			);
		this->addChild(layer, ZORDER_NOTICE_LAYER);
	}
}