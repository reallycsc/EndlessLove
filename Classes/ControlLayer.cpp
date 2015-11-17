#include "ControlLayer.h"
#include "PauseScene.h"
#include "GameOverScene.h"

ControlLayer::ControlLayer(void)
{
	m_pGameMediator = GameMediator::getInstance();
	m_pButtonPause = NULL;
	m_pTextTouchForStart = NULL;
}


ControlLayer::~ControlLayer(void)
{
}


bool ControlLayer::init()
{  
    bool bRet = false;  
    do
    {  
        CC_BREAK_IF(!Layer::init());  
		
        Size winSize = Director::getInstance()->getWinSize();
	
		// load csb
		auto rootNode = CSLoader::createNode("ControlLayer.csb");
		this->addChild(rootNode);

		// get button
		m_pButtonPause = dynamic_cast<Button*>(rootNode->getChildByName("Button_Pause"));
		m_pButtonPause->addClickEventListener(CC_CALLBACK_1(ControlLayer::menuCallback_Pause, this));
		m_pButtonPause->setEnabled(false);

		// get text
		m_pTextTouchForStart = dynamic_cast<Text*>(rootNode->getChildByName("Text_TouchForStart"));

		// set all text
		auto mapGameText = m_pGameMediator->getGameText();
		m_pTextTouchForStart->setString(mapGameText->at(GAMETEXT_CONTROLLAYER_TOUCHFORSTART));
		m_pButtonPause->setTitleText(mapGameText->at(GAMETEXT_CONTROLLAYER_PAUSEGAME));

        bRet = true;
    } while (0);  
  
    return bRet;  
}  

void ControlLayer::gameStart()
{
	m_pButtonPause->setEnabled(true);
	m_pTextTouchForStart->setVisible(false);

	m_pGameMediator->setGameState(STATE_GAME_RUN);
}

void ControlLayer::gameOver()
{
	Size winSize = Director::getInstance()->getWinSize();
	RenderTexture* renderTexture = RenderTexture::create(winSize.width, winSize.height);
	//����Game��������ӽڵ���Ϣ������renderTexture�С�
	//�������ƽ�ͼ��
	renderTexture->begin();
	Director::getInstance()->getRunningScene()->visit();
	renderTexture->end();

	Director::getInstance()->getRenderer()->render();//��3.0�˴�����д�����������newImage����ͼƬ��Ϊ��ɫ,��������һ֡��ȡ  
	Director::getInstance()->getTextureCache()->addImage(renderTexture->newImage(), "GameOverImage");

	Director::getInstance()->replaceScene(GameOverScene::create());
}

void ControlLayer::menuCallback_Pause(Ref* pSender)
{
	Size winSize = Director::getInstance()->getWinSize();
	RenderTexture* renderTexture = RenderTexture::create(winSize.width, winSize.height);
	//����Game��������ӽڵ���Ϣ������renderTexture�С�
	//�������ƽ�ͼ��
	renderTexture->begin();
	Director::getInstance()->getRunningScene()->visit();
	renderTexture->end();
	//����Ϸ������ͣ��ѹ�볡����ջ�����л���GamePause����
	Director::getInstance()->pushScene(PauseScene::createScene(renderTexture));
}