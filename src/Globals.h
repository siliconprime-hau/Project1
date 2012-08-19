#ifndef __GLOBALS__
#define __GLOBALS__

#include "GameState.h"
#include <stack>

#define SCREEN_SIMULATE_HEIGHT	640.0f//sceeen heigth for caculate process

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

#endif //__GLOBALS__