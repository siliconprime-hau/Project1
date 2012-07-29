#include "Globals.h"
#include "GameState.h"
#include <stack>

using namespace std;

float gScreenWidth;
float gScreenHeight;

GameState* gGameState;
stack<GameState*> gGameStateStack;