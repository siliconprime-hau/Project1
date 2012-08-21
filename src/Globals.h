#ifndef __GLOBALS__
#define __GLOBALS__

#include "GameState.h"
#include <stack>

#define SCREEN_SIMULATE_HEIGHT	640.0f//sceeen heigth for caculate process

#define LEVEL_MENU_PANEL_WIDTH	0.3f//30% of screen height
#define LEVEL_MAP_PADDING		0.05f//5% of screen height

using namespace std;

//screen size for cacualte process
extern float gScreenWidth;
extern float gScreenHeight;
//real screen size
extern float gScreenOutputWidth;
extern float gScreenOutPutHeight;
extern float gScreenScaleRatio;

extern GameState* gGameState;
extern stack<GameState*> gGameStateStack;

void gPushState( GameState* gameState );
GameState* gPopState();

enum TOUCH_TYPE
{
	TOUCH_DOWN = 0,
	TOUCH_UP,
	TOUCH_MOVE
};




//enemy type
enum ENEMY_TYPE
{
	ENEMY_TYPE_TO_TARGET_R1 = 0,//range = 1
	ENEMY_TYPE_RANDOM_KNOW_R1,
	ENEMY_TYPE_RANDOM_UNKNOW_R1,
	ENEMY_TYPE_UP_DOWN_R1,
	ENEMY_TYPE_DOWN_UP_R1,
	ENEMY_TYPE_LEFT_RIGHT_R1,
	ENEMY_TYPE_RIGHT_LEFT_R1,
	ENEMY_TYPE_VERTICAL_R1,
	ENEMY_TYPE_HORIZONTAL_R1,
	ENEMY_TYPE_TO_TARGET_R2,//range = 2
	ENEMY_TYPE_RANDOM_KNOW_R2,
	ENEMY_TYPE_RANDOM_UNKNOW_R2,
	ENEMY_TYPE_UP_DOWN_R2,
	ENEMY_TYPE_DOWN_UP_R2,
	ENEMY_TYPE_LEFT_RIGHT_R2,
	ENEMY_TYPE_RIGHT_LEFT_R2,
	ENEMY_TYPE_VERTICAL_R2,
	ENEMY_TYPE_HORIZONTAL_R2
};

//bridge type
enum BRIDGE_TYPE
{
	BRIDGE_TYPE_TWO_WAY_S1 = 0,//always available
	BRIDGE_TYPE_ONE_WAY_S1,
	BRIDGE_TYPE_NO_WAY_S1,
	BRIDGE_TYPE_TWO_WAY_S2,//one time bridge
	BRIDGE_TYPE_ONE_WAY_S2,
	BRIDGE_TYPE_NO_WAY_S2,
	BRIDGE_TYPE_TWO_WAY_S3,//on/off bridge
	BRIDGE_TYPE_ONE_WAY_S3,
	BRIDGE_TYPE_NO_WAY_S3
};

#endif //__GLOBALS__