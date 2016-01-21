#include "NormalNoticeLayer.h"
#include "GameMediator.h"
#include "CSCClass/CommonFunctions.h"

NormalNoticeLayer::NormalNoticeLayer(void)
{
	m_pLayout = NULL;
}


NormalNoticeLayer::~NormalNoticeLayer(void)
{
}

NormalNoticeLayer* NormalNoticeLayer::create(const string &title, const string &info)
{
	NormalNoticeLayer* pRet = new(std::nothrow) NormalNoticeLayer();
	if (pRet && pRet->init(title, info))
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

bool NormalNoticeLayer::init(const string &title, const string &info)
{
    if ( !Layer::init() )
    {
        return false;
    }

	Size winSize = Director::getInstance()->getWinSize();

	// load csb
	auto rootNode = CSLoader::createNode("NormalNoticeLayer.csb");
	this->addChild(rootNode);

	// get botton
	m_pLayout = dynamic_cast<Layout*>(rootNode->getChildByName("Panel_Background"));
	auto buttonOK = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_OK"));
	buttonOK->addClickEventListener(CC_CALLBACK_1(NormalNoticeLayer::menuCallback_OK, this));

	// get text
	auto textTitle = dynamic_cast<Text*>(m_pLayout->getChildByName("Text_Title"));
	auto scrollView = dynamic_cast<ScrollView*>(m_pLayout->getChildByName("ScrollView_info"));
	auto textInfo = dynamic_cast<Text*>(scrollView->getChildByName("Text_info"));

	// set all text
	textTitle->setString(title);
	textInfo->setString(info);
	CSCClass::setScrollViewTextAutoWrap(scrollView, textInfo);
	buttonOK->setTitleText(GameMediator::getInstance()->getGameText()->at("ID_NOTICE_OK"));

	// run animation
	m_pLayout->setPosition(Point(winSize.width/2, winSize.height+ m_pLayout->getContentSize().height));
	m_pLayout->runAction(MoveTo::create(0.2f, Point(winSize.width/2, winSize.height/2)));

	// swallow all touches
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = [](Touch *, Event *){return true;};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

void NormalNoticeLayer::menuCallback_OK(Ref* pSender)
{
	Size winSize = Director::getInstance()->getWinSize();
	m_pLayout->runAction(Sequence::create(
		MoveTo::create(0.2f, Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
		CallFuncN::create(CC_CALLBACK_1(NormalNoticeLayer::moveToFinished, this)),
		NULL));
}

void NormalNoticeLayer::moveToFinished(Ref* pSender)
{
	this->removeFromParent();
}