#include "PlayerLayer.h"
#include "GameMediator.h"

PlayerLayer::PlayerLayer(void)
{
    m_pGameMediator = GameMediator::getInstance();
    m_pMapGameText = m_pGameMediator->getGameText();
    m_pPlayerData = m_pGameMediator->getPlayerData();
    
    m_pTextScore = NULL;
    m_pNodeGoldNum = NULL;
    m_pTextGoldNum = NULL;
    m_pSpriteGold = NULL;
    
    m_pSpriteHeart = NULL;
    m_pSpriteHalfHeartLeft = NULL;
    m_pSpriteHalfHeartRight = NULL;
    m_vSpriteHearts.clear();
    
    m_pSpriteGuideLine = NULL;
    
    m_mCountDown.clear();
    m_vCountDown.clear();
    m_mCurCountDownTime.clear();
    m_mMaxCountDownTime.clear();
    
    m_pNodePlayerHeart = NULL;
    m_pTextHeartNumber = NULL;
    m_pTextGood = NULL;
    m_pTextGreat = NULL;
    m_pTextPerfect = NULL;
    
    m_fCurHeartNumber = 0.0f;
}


PlayerLayer::~PlayerLayer(void)
{
    m_vSpriteHearts.clear();
    m_mCountDown.clear();
    m_vCountDown.clear();
    m_mCurCountDownTime.clear();
    m_mMaxCountDownTime.clear();
}

bool PlayerLayer::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!Layer::init());
        Size winSize = Director::getInstance()->getWinSize();
        
        // bind touch event
        auto touchListener = EventListenerTouchOneByOne::create();
        touchListener->onTouchBegan = CC_CALLBACK_2(PlayerLayer::onTouchBegan, this);
        touchListener->onTouchMoved = CC_CALLBACK_2(PlayerLayer::onTouchMoved, this);
        touchListener->onTouchEnded = CC_CALLBACK_2(PlayerLayer::onTouchEnded, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
        
        // Load csb
        auto rootNode = CSLoader::createNode("PlayerLayer.csb");
        auto action_timeline = CSLoader::createTimeline("PlayerLayer.csb");
        rootNode->runAction(action_timeline);
        action_timeline->pause();
        this->addChild(rootNode, ZORDER_PLAYERLAYER_MAINLAYER);
        
        // get node
        Node* nodeHeartNumber = dynamic_cast<Node*>(rootNode->getChildByName("Node_MaxHeart"));
        Node* nodeCountdown = dynamic_cast<Node*>(rootNode->getChildByName("Node_CountDown"));
        Node* nodePlayer = dynamic_cast<Node*>(rootNode->getChildByName("Node_Player"));
        
        // get heart
        auto spriteHeartGrey = dynamic_cast<Sprite*>(nodeHeartNumber->getChildByName("Sprite_HeartGrey"));
        auto spriteHalfHeartLeftGrey = dynamic_cast<Sprite*>(nodeHeartNumber->getChildByName("Sprite_HeartLeftGrey"));
        m_pSpriteHeart = dynamic_cast<Sprite*>(nodeHeartNumber->getChildByName("Sprite_Heart"));
        m_pSpriteHalfHeartLeft = dynamic_cast<Sprite*>(nodeHeartNumber->getChildByName("Sprite_HeartBrokenLeft"));
        m_pSpriteHalfHeartLeft->setGlobalZOrder(ZORDER_PLAYERLAYER_HEARTHALF);
        m_pSpriteHalfHeartRight = dynamic_cast<Sprite*>(nodeHeartNumber->getChildByName("Sprite_HeartBrokenRight"));
        m_pSpriteHalfHeartRight->setGlobalZOrder(ZORDER_PLAYERLAYER_HEARTHALF);
        
        // get countdown
        Node* nodeGuideLine = dynamic_cast<Node*>(nodeCountdown->getChildByName("Node_GuideLineCountDown"));
        Node* nodeEnlarge = dynamic_cast<Node*>(nodeCountdown->getChildByName("Node_EnlargeCountDown"));
        Node* nodeShrink = dynamic_cast<Node*>(nodeCountdown->getChildByName("Node_ShrinkCountDown"));
        Node* nodeShield = dynamic_cast<Node*>(nodeCountdown->getChildByName("Node_ShieldCountDown"));
        m_mCountDown.insert(COUNTDOWN_GUIDELINE, nodeGuideLine);
        m_mCountDown.insert(COUNTDOWN_ENLARGE, nodeEnlarge);
        m_mCountDown.insert(COUNTDOWN_SHRINK, nodeShrink);
        m_mCountDown.insert(COUNTDOWN_SHIELD, nodeShield);
        for (auto iter : m_mCountDown)
        {
            iter.second->setVisible(false);
        }
        
        // get player heart & text
        m_pNodePlayerHeart = dynamic_cast<Node*>(nodePlayer->getChildByName("Node_Heart"));
        m_pNodePlayerHeart->setVisible(false);
        m_pTextHeartNumber = dynamic_cast<Text*>(m_pNodePlayerHeart->getChildByName("Text_HeartNumber"));
        m_pTextGood = dynamic_cast<Text*>(nodePlayer->getChildByName("Text_Good"));
        m_pTextGreat = dynamic_cast<Text*>(nodePlayer->getChildByName("Text_Great"));
        m_pTextPerfect = dynamic_cast<Text*>(nodePlayer->getChildByName("Text_Perfect"));
        
        // get text
        m_pTextScore = dynamic_cast<Text*>(rootNode->getChildByName("Text_Score"));
        m_pNodeGoldNum = dynamic_cast<Node*>(rootNode->getChildByName("Node_GoldNumber"));
        m_pTextGoldNum = dynamic_cast<Text*>(m_pNodeGoldNum->getChildByName("Text_GoldNumber"));
        m_pSpriteGold = dynamic_cast<Sprite*>(m_pNodeGoldNum->getChildByName("Sprite_GoldCoin"));
        
        // add player
        m_pPlayer = Player::create();
        m_pPlayer->setPosition(winSize.width / 4, 0);
        this->addChild(m_pPlayer, ZORDER_PLAYERLAYER_PLAYER);
        
        // init heart number
        float maxHeartNumber = m_pPlayerData->getMaxHeartNumber();
        int posY = winSize.height - 10;
        int i = 0;
        while (maxHeartNumber - i >= 1)
        {
            Sprite* sprite = Sprite::createWithSpriteFrame(spriteHeartGrey->getSpriteFrame());
            sprite->setAnchorPoint(spriteHeartGrey->getAnchorPoint());
            sprite->setPosition(10 + i * 60, posY);
            nodeHeartNumber->addChild(sprite, ZORDER_PLAYERLAYER_HEARTGREY);
            i++;
        }
        if (maxHeartNumber - i > 0)
        {
            Sprite* sprite = Sprite::createWithSpriteFrame(spriteHalfHeartLeftGrey->getSpriteFrame());
            sprite->setAnchorPoint(spriteHalfHeartLeftGrey->getAnchorPoint());
            sprite->setPosition(10 + floor(maxHeartNumber) * 60, posY);
            nodeHeartNumber->addChild(sprite, ZORDER_PLAYERLAYER_HEARTGREY);
        }
        m_fCurHeartNumber = m_pPlayerData->getHeartNumber();
        i = 0;
        while (m_fCurHeartNumber - i >= 1)
        {
            Sprite* sprite = Sprite::createWithSpriteFrame(m_pSpriteHeart->getSpriteFrame());
            sprite->setAnchorPoint(m_pSpriteHeart->getAnchorPoint());
            sprite->setPosition(10 + i * 60, posY);
            m_vSpriteHearts.pushBack(sprite);
            nodeHeartNumber->addChild(sprite, ZORDER_PLAYERLAYER_HEART);
            i++;
        }
        if (m_fCurHeartNumber - i > 0)
        {
            m_pSpriteHalfHeartLeft->setVisible(true);
            m_pSpriteHalfHeartLeft->setPosition(10 + i * 60, posY);
        }
        
        // add guideline
        m_pSpriteGuideLine = dynamic_cast<Sprite*>(rootNode->getChildByName("Sprite_GuideLine"));
        if (m_pGameMediator->getIsGuidelineForever())
        {
            m_pSpriteGuideLine->setPosition(winSize.width * 0.5, 0);
        }
        else
        {
            m_pSpriteGuideLine->setVisible(false);
        }
        
        // set all text
        m_pTextGood->setString(m_pMapGameText->at("ID_GAME_GOOD"));
        m_pTextGreat->setString(m_pMapGameText->at("ID_GAME_GREAT"));
        m_pTextPerfect->setString(m_pMapGameText->at("ID_GAME_PERFECT"));
        
        m_pTextScore->setString(StringUtils::format("%d", m_pPlayerData->getScore()));
        dynamic_cast<Text*>(nodeGuideLine->getChildByName("Text_CountDown"))->setString(StringUtils::format("%s%.1f",
                                                                                                            m_pMapGameText->at("ID_GAME_GUIDELINE").c_str(),
                                                                                                            10.0));
        dynamic_cast<Text*>(nodeEnlarge->getChildByName("Text_CountDown"))->setString(StringUtils::format("%s%.1f",
                                                                                                          m_pMapGameText->at("ID_GAME_ENLARGE").c_str(),
                                                                                                          10.0));
        dynamic_cast<Text*>(nodeShrink->getChildByName("Text_CountDown"))->setString(StringUtils::format("%s%.1f",
                                                                                                         m_pMapGameText->at("ID_GAME_SHRINK").c_str(),
                                                                                                         10.0));
        dynamic_cast<Text*>(nodeShield->getChildByName("Text_CountDown"))->setString(StringUtils::format("%s%.1f",
                                                                                                         m_pMapGameText->at("ID_GAME_SHIELD").c_str(),
                                                                                                         10.0));
        
        // play animation
        action_timeline->play("Scene_Start", false);
        
        this->scheduleUpdate();
        
        bRet = true;
    } while (0);
    return bRet;
}

bool PlayerLayer::onTouchBegan(Touch *touch, Event *event)
{
    //Point point = touch->getLocation();  //获取触摸坐标
    m_pPlayer->setIsNeedToPowerUp(true);
    return true;
}

void PlayerLayer::onTouchMoved(Touch *touch, Event *event)
{
    //Point point = touch->getLocation();  //获取触摸坐标
}

void PlayerLayer::onTouchEnded(Touch *touch, Event *event)
{
    if (m_pPlayer->getIsPowerUp())
    {
        m_pPlayer->scheduleJump();
    }
    else
    {
        m_pPlayer->setIsNeedToPowerUp(false);
    }
}

// schedule functions
void PlayerLayer::update(float dt)
{
    // change guideline position Y duration player power up
    if (m_pSpriteGuideLine->isVisible() == true)
    {
        if (m_pPlayer->getIsPowerUp() == true)
        {
            auto speed = m_pPlayer->getCurPower() * m_pPlayerData->getStrength() / MAXPOWER;
            int positionY = (speed * speed) / (2 * GRAVITY);
            m_pSpriteGuideLine->setPositionY(positionY);
        }
    }
    // update heart number
    this->updateHeartNumber(m_pPlayerData->getHeartNumber() - m_fCurHeartNumber);
}

void PlayerLayer::startCountDown(float dt, int countDownType, const char* textType)
{
    if (countDownType <= COUNTDOWN_MIN || countDownType >= COUNTDOWN_MAX)
        return;
    if (m_pGameMediator->getGameState() == GAMESTATE_RUN)
    {
        float curTime = m_mCurCountDownTime.at(countDownType);
        Node* node = m_mCountDown.at(countDownType);
        curTime -= dt;
        m_mCurCountDownTime.at(countDownType) = curTime;
        if (curTime <= 0)
        {
            m_vCountDown.eraseObject(node, true);
            node->setVisible(false);
            this->setCountDownPosition();
            switch (countDownType)
            {
                case COUNTDOWN_GUIDELINE:
                    m_pSpriteGuideLine->runAction(Sequence::create(
                                                                   FadeOut::create(1.0f),
                                                                   CallFuncN::create(CC_CALLBACK_1(PlayerLayer::guideLineFadeOutFinished, this)),
                                                                   NULL));
                    break;
                case COUNTDOWN_ENLARGE:
                    m_pPlayer->runAction(ScaleTo::create(0.5f, 1));
                    break;
                case COUNTDOWN_SHRINK:
                    m_pPlayer->runAction(ScaleTo::create(0.5f, 1));
                    break;
                default:
                    break;
            }
        }
        dynamic_cast<Text*>(node->getChildByName("Text_CountDown"))->setString(StringUtils::format("%s%.1f",
                                                                                                   m_pMapGameText->at(textType).c_str(),
                                                                                                   curTime));
        dynamic_cast<LoadingBar*>(node->getChildByName("LoadingBar_CountDown"))->setPercent(100 * curTime / m_mMaxCountDownTime.at(countDownType));
    }
}

void PlayerLayer::guideLineFadeOutFinished(Node* pSender)
{
    pSender->setVisible(false);
}

// update score text function
void PlayerLayer::updateScoreText()
{
    m_pTextScore->setString(StringUtils::format("%d", m_pPlayerData->getScore()));
}

void PlayerLayer::updateGoldNumberText()
{
    // Gold animation from player to icon top-left
    Sprite* sprite = Sprite::createWithSpriteFrame(m_pSpriteGold->getSpriteFrame());
    sprite->setAnchorPoint(Point(0, 0.5f));
    Size size = m_pPlayer->getBoundingBox().size;
    sprite->setPosition(m_pPlayer->getPositionX(), m_pPlayer->getPositionY() + size.height);
    sprite->runAction(Sequence::create(
                                       EaseIn::create(MoveTo::create(0.3f, m_pNodeGoldNum->getPosition() + m_pSpriteGold->getPosition()), 2),
                                       CallFuncN::create(CC_CALLBACK_1(PlayerLayer::goldMoveFinished, this)),
                                       NULL
                                       ));
    this->addChild(sprite, ZORDER_PLAYERLAYER_FLOWINGGOLD);
}

void PlayerLayer::goldMoveFinished(Node* pSender)
{
    pSender->removeFromParent();
    m_pPlayerData->addGoldNumber(1);
    m_pTextGoldNum->setString(StringUtils::format("%d", m_pPlayerData->getGoldNumber()));
}

void PlayerLayer::addHeartNumber(float number) // return heart number before change
{
    // heart number increase
    float realNumber = m_pPlayerData->addHeartNumber(number);
    // change player to color
    if (realNumber != 0)
    {
        m_pPlayer->changePlayerColorToGrey();
    }
    // show flowing sprite
    if (int(number * 10) % 10 != 0)
    {
        if (number >= 0)
            m_pTextHeartNumber->setString(StringUtils::format("+%.1f", number));
        else
            m_pTextHeartNumber->setString(StringUtils::format("%.1f", number));
    }
    else
    {
        if (number >= 0)
            m_pTextHeartNumber->setString(StringUtils::format("+%d", int(number)));
        else
            m_pTextHeartNumber->setString(StringUtils::format("%d", int(number)));
    }
    m_pNodePlayerHeart->setVisible(true);
    m_pNodePlayerHeart->setOpacity(255);
    m_pNodePlayerHeart->setPosition(m_pPlayer->getPositionX(), m_pPlayer->getPositionY() + m_pPlayer->getBoundingBox().size.height + 20);
    m_pNodePlayerHeart->runAction(Sequence::create(
                                                   MoveTo::create(0.5f, Point(m_pNodePlayerHeart->getPositionX(), m_pNodePlayerHeart->getPositionY() + 100)),
                                                   FadeOut::create(0.5f),
                                                   NULL));
}

void PlayerLayer::updateHeartNumber(float addNumber)
{
    if (addNumber == 0)
        return;
    
    
    Size winSize = Director::getInstance()->getWinSize();
    int posY = winSize.height - 10;
    
    m_fCurHeartNumber = m_pPlayerData->getHeartNumber();
    int iterger = floor(m_fCurHeartNumber);
    float heartNumberBefore = m_fCurHeartNumber - addNumber;
    int decimalBefore = int(heartNumberBefore * 10) % 10;
    
    if (addNumber >= 0)
    {
        // n.5 + 0.5
        if (decimalBefore != 0)
        {
            Sprite* sprite = Sprite::createWithSpriteFrame(m_pSpriteHeart->getSpriteFrame());
            sprite->setAnchorPoint(m_pSpriteHeart->getAnchorPoint());
            sprite->setPosition(10 + floor(heartNumberBefore) * 60, posY);
            this->addChild(sprite, ZORDER_PLAYERLAYER_HEART);
            m_vSpriteHearts.pushBack(sprite);
            m_pSpriteHalfHeartLeft->setVisible(false);
            
            addNumber -= 0.5;
        }
        // n + m
        while (addNumber >= 1)
        {
            Sprite* sprite = Sprite::createWithSpriteFrame(m_pSpriteHeart->getSpriteFrame());
            sprite->setAnchorPoint(m_pSpriteHeart->getAnchorPoint());
            sprite->setPosition(10 + m_vSpriteHearts.size() * 60, posY);
            this->addChild(sprite, ZORDER_PLAYERLAYER_HEART);
            m_vSpriteHearts.pushBack(sprite);
            addNumber -= 1;
        }
        // n + 0.5
        if (addNumber > 0)
        {
            m_pSpriteHalfHeartLeft->setVisible(true);
            m_pSpriteHalfHeartLeft->setPosition(10 + iterger * 60, posY);
        }
    }
    else
    {
        // n.5 - 0.5
        if (decimalBefore != 0)
        {
            Sprite* sprite = Sprite::createWithSpriteFrame(m_pSpriteHalfHeartLeft->getSpriteFrame());
            sprite->setAnchorPoint(m_pSpriteHalfHeartLeft->getAnchorPoint());
            sprite->setPosition(m_pSpriteHalfHeartLeft->getPosition());
            sprite->runAction(Sequence::create(
                                               Spawn::create(
                                                             MoveTo::create(0.5f, Point(sprite->getPositionX(), sprite->getPositionY() - 100)),
                                                             FadeOut::create(0.5f),
                                                             NULL),
                                               CallFuncN::create(CC_CALLBACK_1(PlayerLayer::heartFadeOutFinished, this)),
                                               NULL));
            this->addChild(sprite, ZORDER_PLAYERLAYER_HEARTPROGRESS);
            m_pSpriteHalfHeartLeft->setVisible(false);
            addNumber += 0.5;
        }
        // n - m
        while (addNumber <= -1 && m_vSpriteHearts.size() > 0)
        {
            Sprite* obj = *m_vSpriteHearts.rbegin();
            obj->runAction(Sequence::create(
                                            Spawn::create(
                                                          MoveTo::create(0.5f, Point(obj->getPositionX(), obj->getPositionY() - 100)),
                                                          FadeOut::create(0.5f),
                                                          NULL),
                                            CallFuncN::create(CC_CALLBACK_1(PlayerLayer::heartFadeOutFinished, this)),
                                            NULL));
            m_vSpriteHearts.popBack();
            addNumber += 1;
        }
        if (addNumber < 0)
        {
            // n - 0.5
            if (m_vSpriteHearts.size() > 0)
            {
                (*m_vSpriteHearts.rbegin())->removeFromParent();
                m_vSpriteHearts.popBack();
            }
            Sprite* sprite = Sprite::createWithSpriteFrame(m_pSpriteHalfHeartRight->getSpriteFrame());
            sprite->setAnchorPoint(m_pSpriteHalfHeartRight->getAnchorPoint());
            sprite->setPosition(10 + iterger * 60 + 21, posY);
            sprite->runAction(Sequence::create(
                                               Spawn::create(
                                                             MoveTo::create(0.5f, Point(sprite->getPositionX(), sprite->getPositionY() - 100)),
                                                             FadeOut::create(0.5f),
                                                             NULL),
                                               CallFuncN::create(CC_CALLBACK_1(PlayerLayer::heartFadeOutFinished, this)),
                                               NULL));
            this->addChild(sprite, ZORDER_PLAYERLAYER_HEARTPROGRESS);
            m_pSpriteHalfHeartRight->setVisible(false);
            
            m_pSpriteHalfHeartLeft->setVisible(true);
            m_pSpriteHalfHeartLeft->setPosition(10 + iterger * 60, posY);
        }
    }
}

void PlayerLayer::heartFadeOutFinished(Node* pSender)
{
    pSender->removeFromParent();
}

// player functions
void PlayerLayer::showEvaluation(int y)
{
    if (m_pPlayer->getIsIntersect())
        return;
    if (y < 10) // Perfect
    {
        m_pTextPerfect->setOpacity(255);
        m_pTextPerfect->setPosition(Point(m_pPlayer->getPositionX(), m_pPlayer->getPositionY() + m_pPlayer->getBoundingBox().size.height + 70));
        m_pTextPerfect->runAction(Sequence::create(
                                                   Spawn::create(
                                                                 ScaleTo::create(0.5f, 2.0f),
                                                                 MoveTo::create(0.5f, Point(m_pTextPerfect->getPositionX(), m_pTextPerfect->getPositionY() + 100)),
                                                                 NULL),
                                                   FadeOut::create(0.5f),
                                                   NULL));
    }
    else if (y >= 10 && y < 50) // Great
    {
        m_pTextGreat->setOpacity(255);
        m_pTextGreat->setPosition(Point(m_pPlayer->getPositionX(), m_pPlayer->getPositionY() + m_pPlayer->getBoundingBox().size.height + 70));
        m_pTextGreat->runAction(Sequence::create(
                                                 Spawn::create(
                                                               ScaleTo::create(0.5f, 2.0f),
                                                               MoveTo::create(0.5f, Point(m_pTextGreat->getPositionX(), m_pTextGreat->getPositionY() + 100)),
                                                               NULL),
                                                 FadeOut::create(0.5f),
                                                 NULL));
    }
    else // Good
    {
        m_pTextGood->setOpacity(255);
        m_pTextGood->setPosition(Point(m_pPlayer->getPositionX(), m_pPlayer->getPositionY() + m_pPlayer->getBoundingBox().size.height + 70));
        m_pTextGood->runAction(Sequence::create(
                                                Spawn::create(
                                                              ScaleTo::create(0.5f, 2.0f),
                                                              MoveTo::create(0.5f, Point(m_pTextGood->getPositionX(), m_pTextGood->getPositionY() + 100)),
                                                              NULL),
                                                FadeOut::create(0.5f),
                                                NULL));
    }
}

// item use functions
void PlayerLayer::startShowGuideLine(float duration)
{
    if (m_pGameMediator->getIsGuidelineForever())
        return;
    Size winSize = Director::getInstance()->getWinSize();
    m_pSpriteGuideLine->setPosition(winSize.width / 2, 0);
    m_pSpriteGuideLine->stopAllActions();
    m_pSpriteGuideLine->setOpacity(255);
    m_pSpriteGuideLine->setVisible(true);
    
    m_mCurCountDownTime[COUNTDOWN_GUIDELINE] = duration;
    m_mMaxCountDownTime[COUNTDOWN_GUIDELINE] = duration;
    Node* node = m_mCountDown.at(COUNTDOWN_GUIDELINE);
    if (m_vCountDown.find(node) == m_vCountDown.end())
    {
        node->setVisible(true);
        m_vCountDown.pushBack(node);
        this->setCountDownPosition();
    }
    
    this->unschedule("guideLineCountDown");
    this->schedule(CC_CALLBACK_1(PlayerLayer::startCountDown, this, COUNTDOWN_GUIDELINE, "ID_GAME_GUIDELINE"),
                   0.1f, int(duration * 10), 0, "guideLineCountDown");
}

void PlayerLayer::startPlayerEnlarge(float duration)
{
    m_pPlayer->runAction(ScaleTo::create(0.5f, 2));
    m_mCurCountDownTime[COUNTDOWN_ENLARGE] = duration;
    m_mMaxCountDownTime[COUNTDOWN_ENLARGE] = duration;
    // find shrink count down and delete it
    Node* nodeShrink = m_mCountDown.at(COUNTDOWN_SHRINK);
    m_mCurCountDownTime[COUNTDOWN_SHRINK] = 0;
    m_mMaxCountDownTime[COUNTDOWN_SHRINK] = 0;
    auto iter = m_vCountDown.find(nodeShrink);
    if (iter != m_vCountDown.end())
    {
        this->unschedule("shrinkCountDown");
        nodeShrink->setVisible(false);
        m_vCountDown.erase(iter);
    }
    // if no find enlarge then add it
    Node* nodeEnlarge = m_mCountDown.at(COUNTDOWN_ENLARGE);
    if (m_vCountDown.find(nodeEnlarge) == m_vCountDown.end())
    {
        nodeEnlarge->setVisible(true);
        m_vCountDown.pushBack(nodeEnlarge);
        this->setCountDownPosition();
    }
    
    this->unschedule("enlargeCountDown");
    this->schedule(CC_CALLBACK_1(PlayerLayer::startCountDown, this, COUNTDOWN_ENLARGE, "ID_GAME_ENLARGE"),
                   0.1f, int(duration * 10), 0, "enlargeCountDown");
}

void PlayerLayer::startPlayerShrink(float duration)
{
    m_pPlayer->runAction(ScaleTo::create(0.5f, 0.5f));
    m_mCurCountDownTime[COUNTDOWN_SHRINK] = duration;
    m_mMaxCountDownTime[COUNTDOWN_SHRINK] = duration;
    // find shrink count down and delete it
    Node* nodeEnlarge = m_mCountDown.at(COUNTDOWN_ENLARGE);
    m_mCurCountDownTime[COUNTDOWN_ENLARGE] = 0;
    m_mMaxCountDownTime[COUNTDOWN_ENLARGE] = 0;
    auto iter = m_vCountDown.find(nodeEnlarge);
    if (iter != m_vCountDown.end())
    {
        this->unschedule("enlargeCountDown");
        nodeEnlarge->setVisible(false);
        m_vCountDown.erase(iter);
    }
    // if no find enlarge then add it
    Node* nodeShrink = m_mCountDown.at(COUNTDOWN_SHRINK);
    if (m_vCountDown.find(nodeShrink) == m_vCountDown.end())
    {
        nodeShrink->setVisible(true);
        m_vCountDown.pushBack(nodeShrink);
        this->setCountDownPosition();
    }
    
    
    this->unschedule("shrinkCountDown");
    this->schedule(CC_CALLBACK_1(PlayerLayer::startCountDown, this, COUNTDOWN_SHRINK, "ID_GAME_SHRINK"),
                   0.1f, int(duration * 10), 0, "shrinkCountDown");
}

void PlayerLayer::startPlayerShield(float duration)
{
    m_pPlayer->playShieldAnimation(duration);
    m_mCurCountDownTime[COUNTDOWN_SHIELD] = duration;
    m_mMaxCountDownTime[COUNTDOWN_SHIELD] = duration;
    Node* node = m_mCountDown.at(COUNTDOWN_SHIELD);
    if (m_vCountDown.find(node) == m_vCountDown.end())
    {
        node->setVisible(true);
        m_vCountDown.pushBack(node);
        this->setCountDownPosition();
    }
    
    this->unschedule("shieldCountDown");
    this->schedule(CC_CALLBACK_1(PlayerLayer::startCountDown, this, COUNTDOWN_SHIELD, "ID_GAME_SHIELD"),
                   0.1f, int(duration * 10), 0, "shieldCountDown");
    
    return;
}

void PlayerLayer::setCountDownPosition()
{
    Point start = Point(0, Director::getInstance()->getWinSize().height * 0.7);
    for (auto obj : m_vCountDown)
    {
        if (obj->isVisible())
        {
            obj->setPosition(start);
            start.y -= 50;
        }
    }
}