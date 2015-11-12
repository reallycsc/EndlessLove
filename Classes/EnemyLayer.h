#pragma once
#include "CommonHeader.h"
#include "Enemy.h"
#include "Item.h"
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

	bool playerEnemyIntersect(Player* player);
	int playerItemIntersect(Player* player);
	bool isJumpOver(Player* player);

	void increaseGameLevel();
private:
	void addEnemyDown(bool isWithUp);
	void addEnemyUp(int speed);
	void addItem();
	int moveAllEnemys(Vector<Enemy*>* pAllEnemys, float dt);
	int moveAllItems(float dt);

public:
	CC_SYNTHESIZE(bool, m_bIsPlayerJump, IsPlayerJump);
private:
	GameMediator*	_gameMediator;
	Text*	_textLevelUp;
	Sprite*	_spriteEnemyBar;

	Vector<Enemy*> _allEnemysDown;
	Vector<Enemy*> _allEnemysUp;
	Vector<Item*> _allItems;
	Map<int, Sprite*> _spriteMap;

	GameLevelData*	_levelData;

	int mAddEnemyDownDistance; // µ–»Àº‰∏Ùæ‡¿ÎœÒÀÿ
	int mAccEnemyDownDistance;
	int mAddEnemyUpDistance;
	int mAccEnemyUpDistance;

	int mAddItemDistance; // µ¿æﬂº‰∏Ùæ‡¿ÎœÒÀÿ
	int mAccItemDistance;
};

