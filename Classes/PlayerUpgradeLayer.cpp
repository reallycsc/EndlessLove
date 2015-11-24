#include "PlayerUpgradeLayer.h"
#include "MainMenuScene.h"
#include "NormalNoticeLayer.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#import "GameKitHelper.h"
#endif

PlayerUpgradeLayer::PlayerUpgradeLayer(void)
{
	m_pPlayerData = GameMediator::getInstance()->getPlayerData();

	m_pPlayer = NULL;

	m_pListView = NULL;
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
    cocos2d::Size winSize = Director::getInstance()->getWinSize();

	// add scene
	auto rootNode = CSLoader::createNode("PlayerUpgradeScene.csb");
	this->addChild(rootNode, ZORDER_UPGRADELAYER_MAINLAYER);

	// get button
	auto buttonMainMenu = dynamic_cast<Button*>(rootNode->getChildByName("Button_MainMenu"));
	buttonMainMenu->addClickEventListener(CC_CALLBACK_1(PlayerUpgradeLayer::menuCallback_MainMenu, this));

	// get gold number
	m_pGoldNumberAll = dynamic_cast<Text*>(rootNode->getChildByName("Node_GoldNumber")->getChildByName("Text_GoldNumber"));
	m_pGoldNumberAll->setString(StringUtils::format("%d", m_pPlayerData->getGoldNumberAll()));

	// get guideline
	m_pSpriteGuideLine = dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_GuideLine"));

	// get upgrade items
	m_pListView = dynamic_cast<ListView*>(rootNode->getChildByName("ListView_UpgradeItems"));
	this->loadUpgradeItem(ID_JUMP_TYPE);
	this->loadUpgradeItem(ID_MAXHEART_NUMBER);
	this->loadUpgradeItem(ID_STRENGTH);
	this->loadUpgradeItem(ID_POWER_TIME);
	this->loadUpgradeItem(ID_GUIDELINE_TIME);
	this->loadUpgradeItem(ID_ENLARGE_TIME);
	this->loadUpgradeItem(ID_SHRINK_TIME);
	this->loadUpgradeItem(ID_SHIELD_TIME);

	// set text
	auto mapGameText = GameMediator::getInstance()->getGameText();
	buttonMainMenu->setTitleText(mapGameText->at(GAMETEXT_PLAYERUPGRADE_MAINMENU));
	dynamic_cast<Text*>(rootNode->getChildByName("Text_Title"))->setString(mapGameText->at(GAMETEXT_MAINMENU_PLAYERUPGRADE));

	// get player data
	m_pPlayerData->initPlayerData();

	// set ui content
	this->setAllItemContents(true);

	// Add Player
	m_pPlayerData->setHeartNumber(m_pPlayerData->getMaxHeartNumber());
	m_pPlayer = Player::create();
	m_pPlayer->setPosition((winSize.width - m_pListView->getContentSize().width) / 2, 0);
	//m_pPlayer->setGroundLevel(50);
	this->addChild(m_pPlayer);

	this->scheduleUpdate();

	GameMediator::getInstance()->setGameState(STATE_GAME_RUN);

    return true;
}

void PlayerUpgradeLayer::loadUpgradeItem(int id)
{
	auto itemNode = CSLoader::getInstance()->createNodeWithFlatBuffersFile("PlayerUpgradeItemNode.csb");
	Layout* layout = dynamic_cast<Layout*>(itemNode->getChildByName("Panel_UpgradeItem"));

	UPGRADE_ITEM item;
	item.name = dynamic_cast<Text*>(layout->getChildByName("Text_Name"));

	Layout* layoutDesc = dynamic_cast<Layout*>(layout->getChildByName("Panel_Desc"));
	item.description = dynamic_cast<Text*>(layoutDesc->getChildByName("Text_Desc"));
	item.description->setTextAreaSize(Size(layoutDesc->getContentSize().width, 0));
	layoutDesc->setContentSize(item.description->getVirtualRendererSize());
	item.description->setPosition(Point(0, layoutDesc->getContentSize().height));

	item.button = dynamic_cast<Button*>(layout->getChildByName("Button_Item"));
	item.button->addClickEventListener(CC_CALLBACK_1(PlayerUpgradeLayer::menuCallback_Upgrade, this, id));
	item.goldImg = dynamic_cast<ImageView*>(item.button->getChildByName("Image_GoldCoin"));
	item.goldNum = dynamic_cast<Text*>(item.button->getChildByName("Text_GoldNumber"));
	item.textMax = dynamic_cast<Text*>(layout->getChildByName("Text_Max"));
	item.textMax->setVisible(false);
	m_mUpgradeItems.insert(pair<int, UPGRADE_ITEM>(id, item));

	layout->removeFromParentAndCleanup(false);
	m_pListView->pushBackCustomItem(layout);
}

void PlayerUpgradeLayer::setItemContent(int id, int textid, const char* format1, const char* format2, bool isSetText)
{
	auto mapGameText = GameMediator::getInstance()->getGameText();
	unsigned int level = m_pPlayerData->getLevelFor(id);
	if (id == ID_JUMP_TYPE)
	{
		auto pvLevelInfos = m_pPlayerData->getJumpTypeLevelInfoVector();
		auto tLevelConfig = pvLevelInfos->at(level - 1);
		auto item = m_mUpgradeItems.at(id);
		if (isSetText) item.name->setString(mapGameText->at(textid));
		if (level < pvLevelInfos->size())
		{
			item.description->setString(pvLevelInfos->at(level - 1).description);
			item.goldNum->setString(StringUtils::format("%d", tLevelConfig.needGold));
			item.button->setVisible(true);
			item.goldNum->setVisible(true);
			item.goldImg->setVisible(true);
			item.textMax->setVisible(false);
		}
		else
		{
			item.description->setString(pvLevelInfos->at(level - 1).description);
			item.button->setVisible(false);
			item.goldNum->setVisible(false);
			item.goldImg->setVisible(false);
			item.textMax->setVisible(true);
		}
	}
	else
	{
		auto pvLevelInfos = m_pPlayerData->getLevelInfoVectorFor(id);
		auto tLevelConfig = pvLevelInfos->at(level - 1);
		auto item = m_mUpgradeItems.at(id);
		if (isSetText) item.name->setString(mapGameText->at(textid));
		if (level < pvLevelInfos->size())
		{
			item.description->setString(StringUtils::format(format1, tLevelConfig.number, pvLevelInfos->at(level).number));
			item.goldNum->setString(StringUtils::format("%d", tLevelConfig.needGold));
			item.button->setVisible(true);
			item.goldNum->setVisible(true);
			item.goldImg->setVisible(true);
			item.textMax->setVisible(false);
		}
		else
		{
			item.description->setString(StringUtils::format(format2, tLevelConfig.number));
			item.button->setVisible(false);
			item.goldNum->setVisible(false);
			item.goldImg->setVisible(false);
			item.textMax->setVisible(true);
		}
	}
}

void PlayerUpgradeLayer::setAllItemContents(bool isSetText)
{
	setItemContent(ID_JUMP_TYPE, GAMETEXT_PLAYERUPGRADE_JUMPTYPE, "%s", "%s", isSetText);
	setItemContent(ID_MAXHEART_NUMBER, GAMETEXT_PLAYERUPGRADE_MAXHEARTNUMBER, "%.1f -> %.1f", "%.1f", isSetText);
	setItemContent(ID_STRENGTH, GAMETEXT_PLAYERUPGRADE_STRENGTH, "%.0f -> %.0f", "%.0f", isSetText);
	setItemContent(ID_POWER_TIME, GAMETEXT_PLAYERUPGRADE_POWERTIME, "%.2f -> %.2f","%.2f", isSetText);
	setItemContent(ID_GUIDELINE_TIME, GAMETEXT_PLAYERUPGRADE_GUIDELINETIME, "%.1f -> %.1f", "%.1f", isSetText);
	setItemContent(ID_ENLARGE_TIME, GAMETEXT_PLAYERUPGRADE_ENLARGETIME, "%.1f -> %.1f", "%.1f", isSetText);
	setItemContent(ID_SHRINK_TIME, GAMETEXT_PLAYERUPGRADE_SHRINKTIME, "%.1f -> %.1f", "%.1f", isSetText);
	setItemContent(ID_SHIELD_TIME, GAMETEXT_PLAYERUPGRADE_SHIELDTIME, "%.1f -> %.1f", "%.1f", isSetText);

	// set guideline position
	auto maxSpeed = m_pPlayerData->getStrength();
	int positionY = (maxSpeed * maxSpeed) / (2 * GRAVITY);
	m_pSpriteGuideLine->setPositionY(positionY);
}

void PlayerUpgradeLayer::update(float dt)
{
	// start power up
	if (!m_pPlayer->getIsPowerUp())
	{
		bool isOnTheGround = m_pPlayer->getIsOnTheGround();
		if (isOnTheGround)
		{
			m_pPlayer->setIsNeedToPowerUp(true);
		}
		else // calculate the best position
		{
			float speed = m_pPlayer->getCurSpeed();
			float powerTime = m_pPlayerData->getPowerTime();
			float playerPosY = m_pPlayer->getPositionY();
			float guildLinePosY = m_pSpriteGuideLine->getPositionY();
			float downPosY = 0;
			if (speed > 0)
			{
				float upTime = speed / GRAVITY;
				float downTime = powerTime - upTime;
				downPosY = playerPosY + 0.5 * GRAVITY * (upTime * upTime - downTime * downTime);
			}
			else
			{
				downPosY = playerPosY - 0.5 * GRAVITY * powerTime * powerTime;
			}

			if (downPosY <= guildLinePosY)
			{
				m_pPlayer->setIsNeedToPowerUp(true);
			}
		}
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

inline void checkAndUnlockAchievement()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    GameKitHelper* helper = [GameKitHelper sharedHelper];
    if (![helper isAchievementUnlocked:@"Achievements_first_upgrade"])
    {
        [helper reportAchievement:@"Achievements_first_upgrade" percentComplete:100];
    }
#endif
}

void PlayerUpgradeLayer::menuCallback_Upgrade(Ref* pSender, int id)
{	
	auto mapGameText = GameMediator::getInstance()->getGameText();

	int needGold = 0;
	int level = 0;
	if (id == ID_JUMP_TYPE)
	{
		auto levelConfigVector = m_pPlayerData->getJumpTypeLevelInfoVector();
		level = m_pPlayerData->getLevelFor(id);
		needGold = levelConfigVector->at(level - 1).needGold;
	}
	else
	{
		auto levelConfigVector = m_pPlayerData->getLevelInfoVectorFor(id);
		level = m_pPlayerData->getLevelFor(id);
		needGold = levelConfigVector->at(level - 1).needGold;
	}
	// reduce gold
	if (m_pPlayerData->subGoldNumber(needGold))
	{
		level++;
		m_pPlayerData->setLevelFor(id, level);
		m_pPlayerData->initPlayerData();
		this->setAllItemContents(false);
		m_pGoldNumberAll->setString(StringUtils::format("%d", m_pPlayerData->getGoldNumberAll()));
		m_pPlayerData->savePlayerData();
		// Game center achievement
		checkAndUnlockAchievement();
	}
	else
	{
		// tell play gold is not enough
		this->addChild(NormalNoticeLayer::create(
			mapGameText->at(GAMETEXT_NORMALNOTICELAYER_NOTIFICATION),
			mapGameText->at(GAMETEXT_NORMALNOTICELAYER_NOTENOUGHGOLD)),
			ZORDER_UPGRADELAYER_NOTICELAYER);
	}
}