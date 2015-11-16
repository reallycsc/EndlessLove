#include "Enemy.h"

Enemy::Enemy(void)
{
	//_sprite = NULL;
	m_iMoveSpeed = 0;
	m_bIsOver = false;
	m_bIsIntersect = false;
	m_bIsEvluate = false;
}


Enemy::~Enemy(void)
{
}

Enemy* Enemy::createEnemy(SpriteFrame* frame, int moveSpeed)
{
	Enemy* pRet = new(std::nothrow) Enemy();
	if (pRet && pRet->init(frame, moveSpeed))
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

bool Enemy::init(SpriteFrame* frame, int moveSpeed)
{  
    bool bRet = false;  
    do   
    {  
        CC_BREAK_IF(!Sprite::init());  

		this->setSpriteFrame(frame);
		this->setAnchorPoint(Point(0.5f, 0));
		m_iMoveSpeed = moveSpeed;

        bRet = true;
    } while (0);
    
    return bRet;
}