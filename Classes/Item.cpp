#include "Item.h"

Item::Item(void)
{
	m_iItemType = 0;
	m_iMoveSpeed = 0;
}


Item::~Item(void)
{
}

Item* Item::createItem(SpriteFrame* frame, int itemType, int moveSpeed)
{
	Item* pRet = new(std::nothrow) Item();
	if (pRet && pRet->init(frame, itemType, moveSpeed))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool Item::init(SpriteFrame* frame, int itemType, int moveSpeed)
{  
    bool bRet = false;  
    do   
    {  
        CC_BREAK_IF(!Sprite::init());  

		this->setSpriteFrame(frame);
		this->setAnchorPoint(Point(0.5f, 0));
		m_iItemType = itemType;
		m_iMoveSpeed = moveSpeed;

        bRet = true;
    } while (0);
    
    return bRet;
}