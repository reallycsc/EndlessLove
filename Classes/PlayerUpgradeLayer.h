#pragma once
#include "CommonHeader.h"
#include "GameMediator.h"
#include "Player.h"

typedef struct tagUPGRADE_ITEM
{
	Text*	name;
	Text*	description;
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

private:
	void loadUpgradeItem(int id);
	void setItemContent(int id, int textid, const char* format1, const char* format2, bool isSetText = true);
	void setAllItemContents(bool isSetText = true);
    void unlockAchievement(int id, int level, unsigned long maxLevel);

private:
	PlayerData*	m_pPlayerData;

	Player*	m_pPlayer;

	ListView* m_pListView;
	Text*	m_pGoldNumberAll;
	Sprite*	m_pSpriteGuideLine;

	map<int, UPGRADE_ITEM>	m_mUpgradeItems;
};

