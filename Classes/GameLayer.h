#pragma once
#include "CommonHeader.h"
#include "ControlLayer.h"
#include "PlayerLayer.h"
#include "EnemyLayer.h"
#include "GameMediator.h"
#include "CCShake.h"

class GameLayer :
	public Layer
{
public:
	GameLayer(void);
	~GameLayer(void);

	virtual bool init();

	CREATE_FUNC(GameLayer);

	virtual bool onTouchBegan(Touch* touch, Event* event); 
	virtual void onTouchMoved(Touch* touch, Event* event); 
	virtual void onTouchEnded(Touch* touch, Event* event); 

	void update(float dt);
private:
	inline void checkItemIntersect(Player* player);

private:
	GameMediator*	_gameMediator;
	PlayerData*		_playerData;
	ControlLayer*	_controlLayer;
	EnemyLayer*		_enemyLayer;
	PlayerLayer*	_playerLayer;
};

