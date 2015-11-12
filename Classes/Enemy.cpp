#include "Enemy.h"

Enemy::Enemy(void)
{
	_sprite = NULL;
	m_iMoveSpeed = 0;
	m_bIsOver = false;
	m_bIsIntersect = false;
	m_bIsEvluate = false;
}


Enemy::~Enemy(void)
{
}

bool Enemy::init()
{  
    bool bRet = false;  
    do   
    {  
        CC_BREAK_IF(!Node::init());  

        bRet = true;
    } while (0);
    
    return bRet;
}

Enemy* Enemy::createEnemy(SpriteFrame* frame, int moveSpeed)
{
	auto enemy = Enemy::create();
	// test
	//auto sprite = Sprite::createWithSpriteFrame(frame);
	//sprite->setAnchorPoint(Point(0.5f, 0));
	//enemy->addChild(sprite);

	enemy->_sprite = Sprite::createWithSpriteFrame(frame);
	enemy->_sprite->setAnchorPoint(Point(0.5f,0));
	enemy->setAnchorPoint(Point(0.5f, 0));
	enemy->addChild(enemy->_sprite);
	enemy->m_iMoveSpeed = moveSpeed;
	return enemy;
}