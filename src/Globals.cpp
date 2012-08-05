#include "Globals.h"
#include "GameState.h"
#include <stack>

using namespace std;

float gScreenWidth;
float gScreenHeight;

GameState* gGameState;
stack<GameState*> gGameStateStack;

void PushState( GameState* gameState )
{
	gGameStateStack.push(gameState);
}

GameState* PopState()
{
	GameState* game_state = gGameStateStack.top();
	gGameStateStack.pop();

	return game_state;
}