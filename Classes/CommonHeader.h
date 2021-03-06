#pragma once
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "tinyxml2/tinyxml2.h"

USING_NS_CC;
using namespace cocostudio::timeline;
using namespace ui;
using namespace std;
using namespace tinyxml2;

const int GRAVITY = 2940;
const string BACKGROUND_MUSIC_FILE = "background.mp3";

#define MAXDWORD 0xffffffff
// Flags 
#define DEBUG_FLAG 0
#define IAPTEST_FLAG 0

enum GameState {
	GAMESTATE_ENTER = 0,
	GAMESTATE_RUN,
};

enum ItemType {
	ITEMTYPE_MIN = 0,

	ITEMTYPE_GOLD = 1,
	ITEMTYPE_HEART,
	ITEMTYPE_GUIDELINE,
	ITEMTYPE_ENLARGE,
	ITEMTYPE_SHRINK,
	ITEMTYPE_BOMB,
	ITEMTYPE_HEARTBROKENLEFT,
	ITEMTYPE_HEARTBROKENRIGHT,
	ITEMTYPE_HEARTPLUS,
	ITEMTYPE_HEARTSECRET,
	ITEMTYPE_HEARTGREENTEA,
	ITEMTYPE_SHIELD,

	ITEMTYPE_MAX,
};

enum CountdownType {
	COUNTDOWN_MIN = 0, 

	COUNTDOWN_GUIDELINE = 1,
	COUNTDOWN_ENLARGE,
	COUNTDOWN_SHRINK,
	COUNTDOWN_SHIELD,

	COUNTDOWN_MAX,
};

enum ActionTag {
	ACTIONTAG_PLAYER_SCALEY = 0,
};

enum GameStage {
	GAMESTAGE_BIRTH = 1,
	GAMESTAGE_CHILDHOOD,
	GAMESTAGE_TEENAGE,
	GAMESTAGE_YOUTH,
	GAMESTAGE_MIDAGE,
	GAMESTAGE_ELDER,
};

enum BackImageID {
	BACKIMAGE_MAINMENU = 0,
	BACKIMAGE_GAMESCENE_BIRTH,
	BACKIMAGE_GAMESCENE_CHILDHOOD,
	BACKIMAGE_GAMESCENE_TEENAGE,
	BACKIMAGE_GAMESCENE_YOUTH,
	BACKIMAGE_GAMESCENE_MIDAGE,
	BACKIMAGE_GAMESCENE_ELDER,
};