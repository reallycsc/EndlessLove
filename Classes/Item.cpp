#include "Item.h"

Item::Item(void)
{
	_sprite = NULL;
	m_iItemType = 0;
	m_iMoveSpeed = 0;
}


Item::~Item(void)
{
}

bool Item::init()
{  
    bool bRet = false;  
    do   
    {  
        CC_BREAK_IF(!Node::init());  

        bRet = true;
    } while (0);
    
    return bRet;
}

Item* Item::createItem(SpriteFrame* frame, int itemType, int moveSpeed)
{
	auto item = Item::create();
	item->_sprite = Sprite::createWithSpriteFrame(frame);
	item->_sprite->setAnchorPoint(Point(0.5f,0));
	item->setAnchorPoint(Point(0.5f, 0));
	item->addChild(item->_sprite);
	item->m_iItemType = itemType;
	item->m_iMoveSpeed = moveSpeed;
	return item;
}