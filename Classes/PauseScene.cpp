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

		//增加部分：使用Game界面中截图的sqr纹理图片创建Sprite
		//并将Sprite添加到GamePause场景层中
		Size winSize = Director::getInstance()->getWinSize();
		Sprite* _spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());
		CC_BREAK_IF(!_spr);
		_spr->setPosition(winSize.width / 2, winSize.height / 2); //中心位置。
		_spr->setFlipY(true);            //翻转，因为UI坐标和OpenGL坐标不同
		//GameMediator::getInstance()->spriteToGray(_spr, 0); //图片颜色变灰色
		this->addChild(_spr, ZORDER_PAUSESCENE_SCREENSHOT);

		auto pauseLayer = PauseLayer::create();
		CC_BREAK_IF(!pauseLayer);

		this->addChild(pauseLayer, ZORDER_PAUSESCENE_PAUSELAYER);

        bRet = true;
    } while (0);
  
    return bRet;
}  
