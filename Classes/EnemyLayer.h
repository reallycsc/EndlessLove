#pragma once
#include "CommonHeader.h"
#include "Enemy.h"
#include "Item.h"
#include "PlayerLayer.h"
#include "Player.h"
#include "GameMediator.h"

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
	GameMediator*	_gameMediator;
	Text*	_textLevelUp;
	Sprite*	_spriteEnemyBar;

	Vector<Enemy*> _allEnemysDown;
	Vector<Enemy*> _allEnemysUp;
	Vector<Item*> _allItems;
	Map<int, Sprite*> _spriteMap;

	GameLevelData*	_levelData;

	int m_nEnemyDownMinInterval; // ������С���
	int m_nEnemyDownMaxInterval; // ���������

	int m_nAddEnemyDownDistance; // ���˼����������
	int m_nAccEnemyDownDistance;
	int m_nAddEnemyUpDistance;
	int m_nAccEnemyUpDistance;

	int m_nAddItemDistance; // ���߼����������
	int m_nAccItemDistance;
};

