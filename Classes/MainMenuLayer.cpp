#include "MainMenuLayer.h"
#include "GameScene.h"
#include "PlayerUpgradeScene.h"
#include "PurchaseLayer.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#import "GameKitHelper.h"
#import "Reachability.h"
#import "ProgressHUD.h"
#endif

MainMenuLayer::MainMenuLayer(void)
{
    m_pGameMediator = GameMediator::getInstance();
	m_pmGameText = m_pGameMediator->getGameText();
    m_pPlayerData = m_pGameMediator->getPlayerData();
    m_pTextHighscore = NULL;
}


MainMenuLayer::~MainMenuLayer(void)
{
}

bool MainMenuLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	// add scene
	auto rootNode = CSLoader::createNode("MainMenuScene.csb");
	this->addChild(rootNode, ZORDER_MAINMENULAYER_MAINLAYER);

	// get button
	auto buttonStart = dynamic_cast<Button*>(rootNode->getChildByName("Button_StartGame"));
	buttonStart->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Start, this));
	//auto buttonExit = dynamic_cast<Button*>(rootNode->getChildByName("Button_ExitGame"));
	//buttonExit->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Exit, this));
	auto buttonUpgrade = dynamic_cast<Button*>(rootNode->getChildByName("Button_Upgrade"));
	buttonUpgrade->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Upgrade, this));
    auto buttonLeaderboard = dynamic_cast<Button*>(rootNode->getChildByName("Button_Leaderboard"));
    buttonLeaderboard->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Leaderboard, this));
    auto buttonAchievement = dynamic_cast<Button*>(rootNode->getChildByName("Button_Achievement"));
    buttonAchievement->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Achievement, this));
	auto buttonPurchaseNoAd = dynamic_cast<Button*>(rootNode->getChildByName("Button_Purchase_noAd"));
	buttonPurchaseNoAd->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_PurchaseNoAd, this));


	auto buttonReload = dynamic_cast<Button*>(rootNode->getChildByName("Button_Reload"));
	buttonReload->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Reload, this));
    auto buttonPurchase = dynamic_cast<Button*>(rootNode->getChildByName("Button_TestPurchase"));
    buttonPurchase->addClickEventListener(CC_CALLBACK_1(MainMenuLayer::menuCallback_Purchase, this));
#if DEBUGFLAG == 0
    buttonReload->setVisible(false);
    buttonPurchase->setVisible(false);
#endif
    
	// get gold number
	dynamic_cast<Text*>(rootNode->getChildByName("Node_GoldNumber")->getChildByName("Text_GoldNumber"))
    ->setString(StringUtils::format("%d", m_pPlayerData->getGoldNumberAll()));
    
    // get text
    m_pTextHighscore = dynamic_cast<Text*>(rootNode->getChildByName("Text_HighestScore"));

	// set all text
	auto mapGameText = m_pGameMediator->getGameText();
	buttonStart->setTitleText(mapGameText->at(GAMETEXT_MAINMENU_STARTGAME));
	//buttonExit->setTitleText(mapGameText->at(GAMETEXT_MAINMENU_EXITGAME));
	buttonUpgrade->setTitleText(mapGameText->at(GAMETEXT_MAINMENU_PLAYERUPGRADE));
	buttonLeaderboard->setTitleText(mapGameText->at(GAMETEXT_MAINMENU_LEADERBOARD));
	buttonAchievement->setTitleText(mapGameText->at(GAMETEXT_MAINMENU_ACHIEVEMENT));
	dynamic_cast<Text*>(rootNode->getChildByName("Text_GameTitle"))->setString(mapGameText->at(GAMETEXT_MAINMENU_TITLE));
	m_pTextHighscore->setString(StringUtils::format("%s%lld",
                                                    mapGameText->at(GAMETEXT_MAINMENU_HIGHESTSCORE).c_str(),
                                                    m_pPlayerData->getHighscore()));

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    // add custom event lisenter
    auto listener = EventListenerCustom::create(EVENT_PLARERDATA_SCOREUPDATED, [=](EventCustom* event){
        m_pTextHighscore->setString(StringUtils::format("%s%lld",
                                                        m_pGameMediator->getGameText()->at(GAMETEXT_MAINMENU_HIGHESTSCORE).c_str(),
                                                        m_pPlayerData->getHighscore()));
    });
    _eventDispatcher->addEventListenerWithFixedPriority(listener, 1);
#endif
    
    return true;
}

void MainMenuLayer::menuCallback_Start(Ref* pSender)
{
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
	Director::getInstance()->replaceScene(GameScene::create()); 
}

void MainMenuLayer::menuCallback_Exit(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif
	Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void MainMenuLayer::menuCallback_Upgrade(Ref* pSender)
{
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
	Director::getInstance()->replaceScene(PlayerUpgradeScene::create());
}

void MainMenuLayer::menuCallback_Leaderboard(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    GameKitHelper* helper = [GameKitHelper sharedHelper];
    [helper showLeaderboard : @"Highscore"];
#endif
}

void MainMenuLayer::menuCallback_Achievement(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    GameKitHelper* helper = [GameKitHelper sharedHelper];
    [helper showAchievements];
#endif
}

void MainMenuLayer::menuCallback_PurchaseNoAd(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	// load iap
	IAPHelper* helper = [IAPShare sharedHelper].iap;
	Reachability *reach = [Reachability reachabilityForInternetConnection];
	NetworkStatus netStatus = [reach currentReachabilityStatus];
	if (netStatus == NotReachable) {
		NSLog(@"No internet connection!");
	}
	else {
		if (helper.products == nil) {
			helper.production = NO; // No for test, YES for release
			[helper requestProductsWithCompletion : ^ (SKProductsRequest* request, SKProductsResponse* response) {
				if (response > 0) {
					[ProgressHUD dismiss];
					this->unschedule(schedule_selector(PurchaseLayer::waitingTimeOut));
					this->showListItems();
				}
			}];
			[ProgressHUD show : m_pmGameText->at(GAMETEXT_PROGRESSHUD_DOWNLOADINFO) Interaction : FALSE];
			this->scheduleOnce(schedule_selector(PurchaseLayer::waitingTimeOut), 10.0f);
		}
		else {
			// buy product
			SKProduct *product = helper.products objectAtIndex : 0;
			[ProgressHUD show : m_pmGameText->at(GAMETEXT_PROGRESSHUD_BUYING) Interaction : FALSE];
			[helper buyProduct : product
				onCompletion : ^ (SKPaymentTransaction* trans) {
				[ProgressHUD dismiss];
				if (trans.error) {
					NSLog(@"Fail %@",[trans.error localizedDescription]);
				}
				else if (trans.transactionState == SKPaymentTransactionStatePurchased) {
					[ProgressHUD show : m_pmGameText->at(GAMETEXT_PROGRESSHUD_CHECKINGRECEPIT) Interaction : FALSE];
					[helper checkReceipt : trans.transactionReceipt
						AndSharedSecret : @"your sharesecret"
						onCompletion: ^ (NSString *response, NSError *error) {
						[ProgressHUD dismiss];
						if (response) {
							//Convert JSON String to NSDictionary
							NSDictionary* rec = [IAPShare toJSON : response];
							if ([rec[@"status"] integerValue] == 0) {
								[helper provideContentWithTransaction : trans];
								NSLog(@"SUCCESS %@",response);
								NSLog(@"Pruchases %@",helper.purchasedProducts);
								// buy success, proceed next step
								m_pGameMediator->setIsAd(false);
								m_pGameMediator->setIsGuidelineForever(true);
							}
							else {
								[ProgressHUD showError : m_pmGameText->at(GAMETEXT_PROGRESSHUD_RECEIPTSTATUSERROR)];
								NSLog(@"Fail in response status is 0");
							}
						}
						else {
							[ProgressHUD showError : m_pmGameText->at(GAMETEXT_PROGRESSHUD_NORESPONSE)];
						}
					}];
				}
				else if (trans.transactionState == SKPaymentTransactionStateFailed) {
					[ProgressHUD showError : m_pmGameText->at(GAMETEXT_PROGRESSHUD_RECEIPTCHECKERROR)];
					NSLog(@"Fail in SKPaymentTransactionStateFailed");
				}
			}];//end of buy product
		}
	}
#endif
}

void MainMenuLayer::waitingTimeOut(float dt)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	[ProgressHUD showError : m_pmGameText->at(GAMETEXT_PROGRESSHUD_RESPONSETIMEOUT)];
#endif
}

// DEBUG only
void MainMenuLayer::menuCallback_Reload(Ref* pSender)
{
	GameMediator::getInstance()->reloadAllConfigFiles();
}

void MainMenuLayer::menuCallback_Purchase(Ref* pSender)
{
    PurchaseLayer* layer = PurchaseLayer::create();
    this->addChild(layer, ZORDER_MAINMENULAYER_PURCHASELAYER);
}