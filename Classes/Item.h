#pragma once
#include "CommonHeader.h"

class Item :
	public Sprite
{
public:
	Item(void);
	~Item(void);

	static Item* createItem(SpriteFrame* frame, int itemType, int moveSpeed);
	
	virtual bool init(SpriteFrame* frame, int itemType, int moveSpeed);

public:
	CC_SYNTHESIZE(int, m_nItemType, ItemType);
	CC_SYNTHESIZE(int, m_nMoveSpeed, MoveSpeed);
};
