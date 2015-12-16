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
	virtual bool init() override;

	void update(float dt) override;

	void addEnemyDown(bool isWithUp);
	void addEnemyUp(int speed);
	void addItem();
	int moveAllEnemys(Vector<Enemy*>* pAllEnemys, float dt) const;
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

	int m_nEnemyDownMinInterval;
	int m_nEnemyDownMaxInterval;

	int m_nAddEnemyDownDistance; // with pixel
	int m_nAccEnemyDownDistance;
	int m_nAddEnemyUpDistance;
	int m_nAccEnemyUpDistance;

	int m_nAddItemDistance; // with pixel
	int m_nAccItemDistance;
};

