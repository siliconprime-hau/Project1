#ifndef __GLOBALS__
#define __GLOBALS__

#include "GameState.h"
#include <stack>

using namespace std;

extern float gScreenWidth;
extern float gScreenHeight;

extern GameState* gGameState;
extern stack<GameState*> gGameStateStack;

enum TOUCH_TYPE
{
	TOUCH_DOWN = 0,
	TOUCH_UP,
	TOUCH_MOVE
};

#endif //__GLOBALS__