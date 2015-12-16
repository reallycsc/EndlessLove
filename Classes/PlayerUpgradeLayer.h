#pragma once
#include "CommonHeader.h"
#include "GameMediator.h"
#include "Player.h"

const int ZORDER_UPGRADELAYER_MAINLAYER = 0;
const int ZORDER_UPGRADELAYER_NOTICELAYER = 1;

typedef struct tagUPGRADE_ITEM
{
	Text*	name;
	ScrollView* scrollView;
	Text*	description;
	Button* button;
	Sprite*	goldImg;
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

	virtual bool init() override;

	void update(float dt) override;

	void menuCallback_MainMenu(Ref* pSender);
	void menuCallback_Upgrade(Ref* pSender, int id);

private:
	void loadUpgradeItem(int id);
	void setItemContent(int id, const char* textid, const char* format1, const char* format2, bool isSetText = true);
	void setAllItemContents(bool isSetText = true);
	static void unlockAchievement(int id, int level, unsigned long maxLevel);

private:
	PlayerData*	m_pPlayerData;

	Player*	m_pPlayer;

	ListView* m_pListView;
	Text*	m_pGoldNumberAll;
	Sprite*	m_pSpriteGuideLine;

	map<int, UPGRADE_ITEM>	m_mUpgradeItems;
};

