#pragma once
#include "CommonHeader.h"
#include "BackLayer.h"
#include "ControlLayer.h"
#include "PlayerLayer.h"
#include "EnemyLayer.h"
#include "GameMediator.h"
#include "CCShake.h"

const int ZORDER_GAMELAYER_BACKLAYER = 1;
const int ZORDER_GAMELAYER_ENEMYLAYER = 2;
const int ZORDER_GAMELAYER_PLAYERLAYER = 3;
const int ZORDER_GAMELAYER_CONTROLLAYER = 4;

class GameLayer :
	public Layer
{
public:
	GameLayer(void);
	~GameLayer(void);

	virtual bool init();

	CREATE_FUNC(GameLayer);

	void update(float dt);

	virtual void onEnter() override;
private:
	void actionCallback_GameStart();

	void gameOver();

	void checkItemIntersect(Player* player);

private:
	GameMediator*	m_pGameMediator;
	PlayerData*		m_pPlayerData;

	BackLayer*		m_pBackLayer;
	ControlLayer*	m_pControlLayer;
	EnemyLayer*		m_pEnemyLayer;
	PlayerLayer*	m_pPlayerLayer;

	int m_nAllLevelScore;
};

