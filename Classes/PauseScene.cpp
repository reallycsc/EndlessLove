#include "PauseScene.h"
#include "PauseLayer.h"
#include "GameMediator.h"

PauseScene::PauseScene(void)
{
}


PauseScene::~PauseScene(void)
{
}

PauseScene* PauseScene::createScene(RenderTexture* sqr)
{
	PauseScene* pRet = new(std::nothrow) PauseScene();
	if (pRet && pRet->init(sqr))
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

bool PauseScene::init(RenderTexture* sqr)
{  
    bool bRet = false;
    do   
    {  
        CC_BREAK_IF(!Scene::init());

		Size winSize = Director::getInstance()->getWinSize();

		Sprite* _spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());
		CC_BREAK_IF(!_spr);
		_spr->setPosition(winSize.width / 2, winSize.height / 2); //ÖÐÐÄÎ»ÖÃ¡£
		_spr->setFlippedY(true); // Flip image because ui and OpenGL have different coordinate
		this->addChild(_spr);

		auto pauseLayer = PauseLayer::create();
		CC_BREAK_IF(!pauseLayer);

		this->addChild(pauseLayer);

        bRet = true;
    } while (0);
  
    return bRet;
}  
