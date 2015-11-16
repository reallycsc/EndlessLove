#pragma once
#include "CommonHeader.h"

class Enemy :
	public Sprite
{
public:
	Enemy(void);
	~Enemy(void);

	static Enemy* createEnemy(SpriteFrame* frame, int moveSpeed);
	virtual bool init(SpriteFrame* frame, int moveSpeed);

public:
	CC_SYNTHESIZE(int, m_iMoveSpeed, MoveSpeed);
	CC_SYNTHESIZE(bool, m_bIsOver, IsOver);
	CC_SYNTHESIZE(bool, m_bIsIntersect, IsIntersect);
	CC_SYNTHESIZE(bool, m_bIsEvluate, IsEvluate);
};
