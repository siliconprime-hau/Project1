#include "Globals.h"
#include "GameState.h"
#include <stack>
#include <queue>

using namespace std;

float gScreenWidth;
float gScreenHeight;

float gScreenOutputWidth;
float gScreenOutPutHeight;
float gScreenScaleRatio;

unsigned long gCurrentTimeMillis;




GameState* gGameState;
stack<GameState*> gGameStateStack;

void gPushState( GameState* gameState )
{
	gGameStateStack.push(gameState);
}

GameState* gPopState()
{
	GameState* game_state = gGameStateStack.top();
	gGameStateStack.pop();

	return game_state;
}




queue<TouchHolder> gTouchQueuePending;
queue<TouchHolder> gTouchQueueProgressing;

void gPushTouch( queue<TouchHolder> &touchQueue, TouchHolder touchHolder )
{
	touchQueue.push(touchHolder);
}

TouchHolder gPopTouch( queue<TouchHolder> &touchQueue )
{
	TouchHolder touch_holder = touchQueue.front();
	touchQueue.pop();

	return touch_holder;
}



queue<KeyHolder> gKeyQueuePending;
queue<KeyHolder> gKeyQueueProgressing;

void gPushKey( queue<KeyHolder> &keyQueue, KeyHolder keyHolder )
{
	keyQueue.push(keyHolder);
}

KeyHolder gPopKey( queue<KeyHolder> &keyQueue )
{
	KeyHolder key_holder = keyQueue.front();
	keyQueue.pop();

	return key_holder;
}