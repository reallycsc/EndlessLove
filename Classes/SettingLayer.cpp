#include "SettingLayer.h"
#include "GameMediator.h"
#include "MainMenuScene.h"
#include "CSCClass/CSC_IOSHelper.h"


SettingLayer::SettingLayer(void)
{
	m_pLayout = NULL;
	m_pCheckBoxCN = NULL;
	m_pCheckBoxEN = NULL;

	m_languageType = LanguageType::ENGLISH;
	m_languageTypeOriginal = LanguageType::ENGLISH;
}


SettingLayer::~SettingLayer(void)
{
}


bool SettingLayer::init()
{  
    bool bRet = false;  
    do
    {  
        CC_BREAK_IF(!Layer::init());  

        Size winSize = Director::getInstance()->getWinSize();

		// load csb
		auto rootNode = CSLoader::createNode("SettingLayer.csb");
		this->addChild(rootNode);

		// get button
		m_pLayout = dynamic_cast<Layout*>(rootNode->getChildByName("Panel_Setting"));
		auto buttonApply = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_Apply"));
		buttonApply->addClickEventListener(CC_CALLBACK_1(SettingLayer::menuCallback_Apply, this));
		auto buttonCancel = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_Cancel"));
		buttonCancel->addClickEventListener(CC_CALLBACK_1(SettingLayer::menuCallback_Cancel, this));
        auto buttonRestore = dynamic_cast<Button*>(m_pLayout->getChildByName("Button_RestorePurcahse"));
        buttonRestore->addClickEventListener(CC_CALLBACK_1(SettingLayer::menuCallback_Restore, this));

		// get checkbox
		m_pCheckBoxCN = dynamic_cast<CheckBox*>(m_pLayout->getChildByName("Node_Chinese")->getChildByName("CheckBox"));
		m_pCheckBoxCN->addEventListener(CC_CALLBACK_2(SettingLayer::selectedStateEvent_CN, this));
		m_pCheckBoxEN = dynamic_cast<CheckBox*>(m_pLayout->getChildByName("Node_English")->getChildByName("CheckBox"));
		m_pCheckBoxEN->addEventListener(CC_CALLBACK_2(SettingLayer::selectedStateEvent_EN, this));

		m_languageTypeOriginal = m_languageType = GameMediator::getInstance()->getLanguageType();
		switch (m_languageType)
		{
		case LanguageType::CHINESE:
			m_pCheckBoxCN->setSelected(true);
			m_pCheckBoxEN->setSelected(false);
			break;
		case LanguageType::ENGLISH:
			m_pCheckBoxCN->setSelected(false);
			m_pCheckBoxEN->setSelected(true);
			break;
		default:
			m_pCheckBoxCN->setSelected(false);
			m_pCheckBoxEN->setSelected(true);
			break;
		}

		// set all text
		auto mapGameText = GameMediator::getInstance()->getGameText();
		dynamic_cast<Text*>(m_pLayout->getChildByName("Text_Setting"))->setString(mapGameText->at("ID_SETTING_TITLE"));
		buttonApply->setTitleText(mapGameText->at("ID_SETTING_APPLY"));
		buttonCancel->setTitleText(mapGameText->at("ID_SETTING_CANCEL"));
        buttonRestore->setTitleText(mapGameText->at("ID_SETTING_RESTORE"));

		// swallow all touches
		auto touchListener = EventListenerTouchOneByOne::create();
		touchListener->setSwallowTouches(true);
		touchListener->onTouchBegan = [](Touch *, Event *) {return true; };
		_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

		// run animation
        m_pLayout->setPosition(Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height));
		m_pLayout->runAction(MoveTo::create(0.2f, Point(winSize.width / 2, winSize.height / 2)));

        bRet = true;
    } while (0);  
  
    return bRet;  
}

void SettingLayer::menuCallback_Apply(Ref* pSender)
{
	
	Size winSize = Director::getInstance()->getWinSize();
	m_pLayout->runAction(Sequence::create(
		MoveTo::create(0.2f, Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
		CallFuncN::create([=](Ref* pSenderNew)->void
	{
		if (m_languageTypeOriginal != m_languageType)
		{
			GameMediator::getInstance()->changeLanguageTo(m_languageType);
			Director::getInstance()->replaceScene(MainMenuScene::create());
		}
		else
		{
			this->removeFromParent();
		}
	}),
		NULL));
}

void SettingLayer::menuCallback_Cancel(Ref* pSender)
{
    Size winSize = Director::getInstance()->getWinSize();
	m_pLayout->runAction(Sequence::create(
                                          MoveTo::create(0.2f, Point(winSize.width / 2, winSize.height + m_pLayout->getContentSize().height)),
		CallFuncN::create([=](Ref* pSenderNew)->void
	{
		this->removeFromParent();
	}),
		NULL));
}

void SettingLayer::menuCallback_Restore(Ref* pSender)
{
    CSC_IOSHelper::getInstance()->IAP_restorePurchase();
}

void SettingLayer::selectedStateEvent_CN(Ref *pSender, CheckBox::EventType type)
{
	m_pCheckBoxCN->setSelected(true);
	m_pCheckBoxEN->setSelected(false);
	m_languageType = LanguageType::CHINESE;
}

void SettingLayer::selectedStateEvent_EN(Ref *pSender, CheckBox::EventType type)
{
	m_pCheckBoxEN->setSelected(true);
	m_pCheckBoxCN->setSelected(false);
	m_languageType = LanguageType::ENGLISH;
}