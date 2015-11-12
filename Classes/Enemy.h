#pragma once
#include "CommonHeader.h"

class Enemy :
	public Node
{
public:
	Enemy(void);
	~Enemy(void);

	CREATE_FUNC(Enemy);

	virtual bool init();

	static Enemy* createEnemy(SpriteFrame* frame, int moveSpeed);

public:
	CC_SYNTHESIZE(Sprite*,_sprite,Sprite);
	CC_SYNTHESIZE(int, m_iMoveSpeed, MoveSpeed);
	CC_SYNTHESIZE(bool, m_bIsOver, IsOver);
	CC_SYNTHESIZE(bool, m_bIsIntersect, IsIntersect);
};
