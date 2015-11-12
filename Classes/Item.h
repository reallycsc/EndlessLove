#pragma once
#include "CommonHeader.h"

class Item :
	public Node
{
public:
	Item(void);
	~Item(void);

	CREATE_FUNC(Item);

	virtual bool init();

	static Item* createItem(SpriteFrame* frame, int itemType, int moveSpeed);

public:
	CC_SYNTHESIZE(Sprite*,_sprite,Sprite);
	CC_SYNTHESIZE(int, m_iItemType, ItemType);
	CC_SYNTHESIZE(int, m_iMoveSpeed, MoveSpeed);
};
