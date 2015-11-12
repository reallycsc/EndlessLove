#pragma once
#include "CommonHeader.h"
#include "GameMediator.h"
#include "Player.h"

typedef struct tagUPGRADE_ITEM
{
	Text*	itemInfo;
	Text*	number;
	Button* button;
	ImageView*	goldImg;
	Text*	goldNum;
	Text*	textMax;
}UPGRADE_ITEM;

class PlayerUpgradeLayer :
	public Layer
{
public:
	PlayerUpgradeLayer(void);
	~PlayerUpgradeLayer(void);

	CREATE_FUNC(PlayerUpgradeLayer);

	virtual bool init();

	void update(float dt);

	void menuCallback_MainMenu(Ref* pSender);
	void menuCallback_Upgrade(Ref* pSender, int id);
	void menuCallback_Upgrade_JumpType(Ref* pSender);

private:
	inline void loadUpgradeItem(int id, Node* node)
	{
		UPGRADE_ITEM item;
		item.itemInfo = dynamic_cast<Text*>(node->getChildByName("Text_Item"));
		item.number = dynamic_cast<Text*>(node->getChildByName("Text_Number"));
		item.button = dynamic_cast<Button*>(node->getChildByName("Button_Item"));
		item.button->addClickEventListener(CC_CALLBACK_1(PlayerUpgradeLayer::menuCallback_Upgrade, this, id));
		item.goldImg = dynamic_cast<ImageView*>(node->getChildByName("Image_GoldCoin"));
		item.goldNum = dynamic_cast<Text*>(node->getChildByName("Text_GoldNumber"));
		item.textMax = dynamic_cast<Text*>(node->getChildByName("Text_Max"));
		item.textMax->setVisible(false);
		m_mUpgradeItems.insert(pair<int, UPGRADE_ITEM>(id, item));
	}
	void setItemContent(int id, int textid, const char* format1, const char* format2);
	void setAllItemContents();

	void changeItemContentNumbers(int id, const char* format1, const char* format2);
	void changeAllItemContentsNumbers();

private:
	Player*	m_pPlayer;
	Text*	m_pGoldNumberAll;
	Sprite*	m_pSpriteGuideLine;

	map<int, UPGRADE_ITEM>	m_mUpgradeItems;
};

