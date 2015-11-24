#include "BackLayer.h"
#include "GameMediator.h"

BackLayer::BackLayer(void)
{
	m_mBackSprites.clear();
	m_nCurStage = 0;
}


BackLayer::~BackLayer(void)
{
	m_mBackSprites.clear();
}

bool BackLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 3. add your codes below...

	// add scene
	// load csb
	auto rootNode = CSLoader::createNode("BackgroundLayer.csb");
	this->addChild(rootNode);

	// get sprites node
	Vector<Sprite*> tempSprites;
	auto nodeBirth = dynamic_cast<Node*>(rootNode->getChildByName("Node_Birth"));
	tempSprites.clear();
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeBirth->getChildByName("Sprite_babyBottle_1")));
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeBirth->getChildByName("Sprite_babyBottle_2")));
	m_mBackSprites.insert(pair<int, Vector<Sprite*>>(GAMESTAGE_BIRTH, tempSprites));

	auto nodeChildhood = dynamic_cast<Node*>(rootNode->getChildByName("Node_Childhood"));
	tempSprites.clear();
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeChildhood->getChildByName("Sprite_Pinao")));
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeChildhood->getChildByName("Sprite_guitar")));
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeChildhood->getChildByName("Sprite_mircophone")));
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeChildhood->getChildByName("Sprite_saxphone")));
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeChildhood->getChildByName("Sprite_violin")));
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeChildhood->getChildByName("Sprite_paint")));
	m_mBackSprites.insert(pair<int, Vector<Sprite*>>(GAMESTAGE_CHILDHOOD, tempSprites));

	auto nodeTeenage = dynamic_cast<Node*>(rootNode->getChildByName("Node_Teenage"));
	tempSprites.clear();
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeTeenage->getChildByName("Sprite_books_1")));
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeTeenage->getChildByName("Sprite_books_2")));
	m_mBackSprites.insert(pair<int, Vector<Sprite*>>(GAMESTAGE_TEENAGE, tempSprites));

	auto nodeYouth = dynamic_cast<Node*>(rootNode->getChildByName("Node_Youth"));
	tempSprites.clear();
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeYouth->getChildByName("Sprite_gift")));
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeYouth->getChildByName("Sprite_graduate")));
	m_mBackSprites.insert(pair<int, Vector<Sprite*>>(GAMESTAGE_YOUTH, tempSprites));

	auto nodeMidage = dynamic_cast<Node*>(rootNode->getChildByName("Node_Midage"));
	tempSprites.clear();
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeMidage->getChildByName("Sprite_car")));
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeMidage->getChildByName("Sprite_wallet")));
	m_mBackSprites.insert(pair<int, Vector<Sprite*>>(GAMESTAGE_MIDAGE, tempSprites));

	auto nodeElder = dynamic_cast<Node*>(rootNode->getChildByName("Node_Elder"));
	tempSprites.clear();
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeElder->getChildByName("Sprite_crutch")));
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeElder->getChildByName("Sprite_syringe")));
	tempSprites.pushBack(dynamic_cast<Sprite*>(nodeElder->getChildByName("Sprite_wheelchair")));
	m_mBackSprites.insert(pair<int, Vector<Sprite*>>(GAMESTAGE_ELDER, tempSprites));


	tempSprites.clear();

    return true;
}

void BackLayer::moveBackSprite(int stage)
{
	if (stage == m_nCurStage)
		return;
	m_nCurStage = stage;
	this->unschedule("moveBackSprite");
	int level = GameMediator::getInstance()->getGameLevel();
	float speed = GameMediator::getInstance()->getGameLevelData()->at(level).getPlayerMoveSpeed() * 0.25;
	float duration = Director::getInstance()->getWinSize().width / speed;
	this->schedule(CC_CALLBACK_1(BackLayer::flyBackSprite, this, &m_mBackSprites.at(stage), duration),
		duration, CC_REPEAT_FOREVER, 0.1f, "moveBackSprite");
}

void BackLayer::moveRandomBackSprite()
{
	this->unschedule("moveRandomBackSprite");
	int level = GameMediator::getInstance()->getGameLevel();
	float speed = GameMediator::getInstance()->getGameLevelData()->at(level).getPlayerMoveSpeed() * 0.25;
	float duration = Director::getInstance()->getWinSize().width / speed;
	this->schedule(CC_CALLBACK_1(BackLayer::flyRandomBackSprite, this, duration),
		duration, CC_REPEAT_FOREVER, 0.1f, "moveRandomBackSprite");
}

void BackLayer::flyBackSprite(float dt, Vector<Sprite*>* vSprites, float duration)
{
	// get random sprite
	Sprite* sprite = vSprites->at(random(0, (int)vSprites->size() - 1));
	
	Size winSize = Director::getInstance()->getWinSize();
	int winWidth = winSize.width;
	int winHeight = winSize.height;
	// set position and random angle
	sprite->setRotation(random(-45, 45));
	int spriteHalfHeight = sprite->getContentSize().height*0.5;
	int deltaX = max((int)(sprite->getContentSize().width*0.5), spriteHalfHeight);
	int posY = random(spriteHalfHeight, winHeight - spriteHalfHeight);
	sprite->setPosition(winWidth + deltaX, posY);
	
	float divide3 = duration / 3;
	sprite->setOpacity(0);
	sprite->runAction(Sequence::create(
		FadeTo::create(divide3, 127),
		DelayTime::create(divide3),
		FadeOut::create(divide3),
		NULL
		));
	sprite->runAction(MoveTo::create(duration, Point(-deltaX, posY)));
}

void BackLayer::flyRandomBackSprite(float dt, float duration)
{
	int min = GAMESTAGE_BIRTH;
	int max = GAMESTAGE_CHILDHOOD;
	int stage = random(min, max);
	m_nCurStage = stage;
	this->flyBackSprite(0, &m_mBackSprites.at(stage), duration);
}