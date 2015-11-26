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

#define MAXDWORD 0xffffffff
// Flags 
//#define LANGUAGE_CHINESE
#define LANGUAGE_ENGLISH
#define DEBUGFLAG 0

enum GameState {
	STATE_GAME_ENTER = 0,
	STATE_GAME_RUN,
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

enum GameoverReason {
	GAMEOVER_REASON_BOMB = 0,
	GAMEOVER_REASON_NOHEART,
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

// Custom event code
const string EVENT_GAMECENTER_AUTHENTICATED = "event_gamecenter_authenticated";
const string EVENT_GAMECENTER_SCORERETRIVED = "event_gamecenter_scoreretrived";
const string EVENT_PLARERDATA_SCOREUPDATED = "event_playerdata_scoreupdated";

// global zorder & layer zorder
const int ZORDER_MAINMENULAYER_MAINLAYER = 0;
const int ZORDER_MAINMENULAYER_PURCHASELAYER = 1;

const int ZORDER_UPGRADELAYER_MAINLAYER = 0;
const int ZORDER_UPGRADELAYER_NOTICELAYER = 1;

const int ZORDER_GAMELAYER_BACKLAYER = 0;
const int ZORDER_GAMELAYER_ENEMYLAYER = 1;
const int ZORDER_GAMELAYER_PLAYERLAYER = 2;
const int ZORDER_GAMELAYER_CONTROLLAYER = 3;
const int ZORDER_GAMELAYER_TEXTLAYER = 4;
const int ZORDER_GAMELAYER_NOTICELAYER = 5;

const int ZORDER_ENEMYLAYER_MAINLAYER = 0;
const int ZORDER_ENEMYLAYER_ENEMY = 1;
const int ZORDER_ENEMYLAYER_ITEM = 2;

const int ZORDER_PLAYERLAYER_MAINLAYER = 0;
const int ZORDER_PLAYERLAYER_FLOWINGGOLD = 1;
const int ZORDER_PLAYERLAYER_PLAYER = 2;
const int ZORDER_PLAYERLAYER_HEARTGREY = 3;
const int ZORDER_PLAYERLAYER_HEART = 4;
const int ZORDER_PLAYERLAYER_HEARTHALF = 5;
const int ZORDER_PLAYERLAYER_HEARTPROGRESS = 6;

enum GametextId {
	GAMETEXT_COMMON_CLOSE = 1,

	GAMETEXT_MAINMENU_TITLE,
	GAMETEXT_MAINMENU_HIGHESTSCORE,
	GAMETEXT_MAINMENU_STARTGAME,
	GAMETEXT_MAINMENU_EXITGAME,
	GAMETEXT_MAINMENU_PLAYERUPGRADE,
	GAMETEXT_MAINMENU_LEADERBOARD,
	GAMETEXT_MAINMENU_ACHIEVEMENT,

	GAMETEXT_CONTROLLAYER_TOUCHFORSTART,
	GAMETEXT_CONTROLLAYER_PAUSEGAME,

	GAMETEXT_ENEMYLAYER_LEVELUP,

	GAMETEXT_GAMEOVERLAYER_TITLE,
	GAMETEXT_GAMEOVERLAYER_RETRY,
	GAMETEXT_GAMEOVERLAYER_MAINMENU,
	GAMETEXT_GAMEOVERLAYER_REVIVE,

	GAMETEXT_PAUSELAYER_TITLE,
	GAMETEXT_PAUSELAYER_RESUME,

	GAMETEXT_PLAYERLAYER_SCORE,
	GAMETEXT_PLAYERLAYER_GUIDELINE,
	GAMETEXT_PLAYERLAYER_ENLARGE,
	GAMETEXT_PLAYERLAYER_SHRINK,
	GAMETEXT_PLAYERLAYER_SHIELD,

	GAMETEXT_PLAYER_GOOD,
	GAMETEXT_PLAYER_GREAT,
	GAMETEXT_PLAYER_PERFECT,

	GAMETEXT_PLAYERUPGRADE_UPGRADE,
	GAMETEXT_PLAYERUPGRADE_MAINMENU,
	GAMETEXT_PLAYERUPGRADE_JUMPTYPE,
	GAMETEXT_PLAYERUPGRADE_MAXHEARTNUMBER,
	GAMETEXT_PLAYERUPGRADE_STRENGTH,
	GAMETEXT_PLAYERUPGRADE_POWERTIME,
	GAMETEXT_PLAYERUPGRADE_GUIDELINETIME,
	GAMETEXT_PLAYERUPGRADE_ENLARGETIME,
	GAMETEXT_PLAYERUPGRADE_SHRINKTIME,
	GAMETEXT_PLAYERUPGRADE_SHIELDTIME,

	GAMETEXT_NORMALNOTICELAYER_NOTIFICATION,
	GAMETEXT_NORMALNOTICELAYER_NOTENOUGHGOLD,

	GAMETEXT_PROGRESSHUD_DOWNLOADINFO,
	GAMETEXT_PROGRESSHUD_BUYING,
	GAMETEXT_PROGRESSHUD_CHECKINGRECEPIT,
	GAMETEXT_PROGRESSHUD_RECEIPTSTATUSERROR,
	GAMETEXT_PROGRESSHUD_NORESPONSE,
	GAMETEXT_PROGRESSHUD_RECEIPTCHECKERROR,
	GAMETEXT_PROGRESSHUD_RESPONSETIMEOUT,
};