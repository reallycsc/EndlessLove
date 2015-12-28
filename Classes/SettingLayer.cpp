#include "SettingLayer.h"
#include "GameMediator.h"
#include "MainMenuScene.h"
#include "CSCClass/CSC_IOSHelper.h"
#include <SimpleAudioEngine.h>


SettingLayer::SettingLayer(void)
{
	m_pLayout = NULL;
	m_pCheckBoxCN = NULL;
	m_pCheckBoxEN = NULL;

	m_pButtonMusicOn = NULL;
	m_pButtonMusicOff = NULL;
	m_pSliderMusic = NULL;

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

		// get music setting
		auto nodeMusic = dynamic_cast<Node*>(m_pLayout->getChildByName("Node_Music"));
		m_pButtonMusicOff = dynamic_cast<Button*>(nodeMusic->getChildByName("Button_musicOff"));
		m_pButtonMusicOff->addClickEventListener(CC_CALLBACK_1(SettingLayer::menuCallback_MusicOff, this));
		m_pButtonMusicOn = dynamic_cast<Button*>(nodeMusic->getChildByName("Button_musicOn"));
		m_pButtonMusicOn->addClickEventListener(CC_CALLBACK_1(SettingLayer::menuCallback_MusicOn, this));
		m_pSliderMusic = dynamic_cast<Slider*>(nodeMusic->getChildByName("Slider_music"));
		m_pSliderMusic->addEventListener(CC_CALLBACK_2(SettingLayer::onSliderEvent, this));
		if (CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
		{
			m_pButtonMusicOn->setVisible(false);
			m_pButtonMusicOn->setEnabled(false);
		}
		else
		{
			m_pButtonMusicOff->setVisible(false);
			m_pButtonMusicOff->setEnabled(false);
			m_pSliderMusic->setEnabled(false);
		}

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

void SettingLayer::menuCallback_MusicOn(Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(BACKGROUND_MUSIC_FILE.c_str(), true);
	m_pButtonMusicOff->setEnabled(true);
	m_pButtonMusicOff->setVisible(true);
	m_pButtonMusicOn->setEnabled(false);
	m_pButtonMusicOn->setVisible(false);
	m_pSliderMusic->setEnabled(true);
}

void SettingLayer::menuCallback_MusicOff(Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	m_pButtonMusicOn->setEnabled(true);
	m_pButtonMusicOn->setVisible(true);
	m_pButtonMusicOff->setEnabled(false);
	m_pButtonMusicOff->setVisible(false);
	m_pSliderMusic->setEnabled(false);
}

void SettingLayer::onSliderEvent(Ref* pSender, Slider::EventType type)
{
	if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
	{
		// set attribute
		float percent = m_pSliderMusic->getPercent();
		float maxPercent = m_pSliderMusic->getMaxPercent();
		
		CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(percent / maxPercent);
	}
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