#ifndef __GLOBALS__
#define __GLOBALS__

#include "GameState.h"
#include <stack>
#include <queue>

using namespace std;




#define SCREEN_SIMULATE_HEIGHT	540.0f//sceeen heigth for caculate process




//screen size for cacualte process
extern float gScreenWidth;
extern float gScreenHeight;
//real screen size
extern float gScreenOutputWidth;
extern float gScreenOutPutHeight;
extern float gScreenScaleRatio;

extern unsigned long gCurrentTimeMillis;




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

struct TouchHolder
{
	int mTouchId, mTouchType;
	float mTouchPosX, mTouchPosY;
	TouchHolder( int id, int type, float x, float y )
	{
		mTouchId = id;
		mTouchType = type;
		mTouchPosX = x;
		mTouchPosY = y;
	}
};

extern queue<TouchHolder> gTouchQueuePending;
extern queue<TouchHolder> gTouchQueueProgressing;

void gPushTouch( queue<TouchHolder> &touchQueue, TouchHolder touchHolder );
TouchHolder gPopTouch( queue<TouchHolder> &touchQueue );




//keycode define
#ifdef __WINDOW__

#include <Windows.h>
#define KC_UP		VK_UP
#define KC_DOWN		VK_DOWN
#define KC_LEFT		VK_LEFT
#define KC_RIGHT	VK_RIGHT

#else //__WINDOW__

#ifdef __ANDROID__

#include <android/keycodes.h>
#define KC_UP		AKEYCODE_W
#define KC_DOWN		AKEYCODE_S
#define KC_LEFT		AKEYCODE_A
#define KC_RIGHT	AKEYCODE_D

#else //__ANDROID__

#endif //__ANDROID__

#endif //__WINDOW__

enum KEY_TYPE
{
	KEY_INACTIVE = -1,
	KEY_DOWN,
	KEY_UP
};

struct KeyHolder
{
	int mKeyCode, mKeyType;
	
	KeyHolder()
	{
		mKeyCode = mKeyType = KEY_INACTIVE;
	}
	
	KeyHolder( int keyCode, int keyType )
	{
		mKeyCode = keyCode;
		mKeyType = keyType;
	}

	void Clear()
	{
		mKeyCode = mKeyType = KEY_INACTIVE;
	}
};

extern queue<KeyHolder> gKeyQueuePending;
extern queue<KeyHolder> gKeyQueueProgressing;

void gPushKey( queue<KeyHolder> &keyQueue, KeyHolder keyHolder );
KeyHolder gPopKey( queue<KeyHolder> &keyQueue );


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
//enum BRIDGE_TYPE
//{
//	BRIDGE_TYPE_TWO_WAY_S1 = 0,//always available
//	BRIDGE_TYPE_ONE_WAY_S1,
//	BRIDGE_TYPE_NO_WAY_S1,
//	BRIDGE_TYPE_TWO_WAY_S2,//one time bridge
//	BRIDGE_TYPE_ONE_WAY_S2,
//	BRIDGE_TYPE_NO_WAY_S2,
//	BRIDGE_TYPE_TWO_WAY_S3,//on/off bridge
//	BRIDGE_TYPE_ONE_WAY_S3,
//	BRIDGE_TYPE_NO_WAY_S3
//};

#endif //__GLOBALS__