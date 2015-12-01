#pragma once
#include "CommonHeader.h"
#include "Enemy.h"
#include "Item.h"
#include "PlayerLayer.h"
#include "Player.h"
#include "GameMediator.h"

const int ZORDER_ENEMYLAYER_MAINLAYER = 0;
const int ZORDER_ENEMYLAYER_ENEMY = 1;
const int ZORDER_ENEMYLAYER_ITEM = 2;

class EnemyLayer :
	public Layer
{
public:
	EnemyLayer(void);
	~EnemyLayer(void);

	CREATE_FUNC(EnemyLayer);
	virtual bool init();

	void update(float dt);

	void addEnemyDown(bool isWithUp);
	void addEnemyUp(int speed);
	void addItem();
	int moveAllEnemys(Vector<Enemy*>* pAllEnemys, float dt);
	int moveAllItems(float dt);

	bool playerEnemyIntersect(Player* player);
	int playerItemIntersect(Player* player);
	bool isJumpOver(PlayerLayer* playerLayer, Player* player);

	void increaseGameLevel();
private:
	GameMediator*	m_pGameMediator;
	PlayerData*	m_pPlayerData;
	Text*	m_pTextLevelUp;
	Sprite*	m_pSpriteEnemyBar;

	Vector<Enemy*> m_vAllEnemysDown;
	Vector<Enemy*> m_vAllEnemysUp;
	Vector<Item*> m_vAllItems;
	Map<int, Sprite*> m_mSpriteMap;

	GameLevelData*	m_pLevelData;

	int m_nEnemyDownMinInterval; // 敌人最小间隔
	int m_nEnemyDownMaxInterval; // 敌人最大间隔

	int m_nAddEnemyDownDistance; // 敌人间隔距离像素
	int m_nAccEnemyDownDistance;
	int m_nAddEnemyUpDistance;
	int m_nAccEnemyUpDistance;

	int m_nAddItemDistance; // 道具间隔距离像素
	int m_nAccItemDistance;
};

