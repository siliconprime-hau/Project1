#ifndef __SSP__
#define __SSP__

#include "GameState.h"
#include "Map.h"
#include "Piece.h"

enum BATTLE_LEVEL//game difficult level
{
	BATTLE_LEVEL_1 = 0
};

enum BATTLE_LEVEL_SUB_MODE//game level sub mode 
{
	BATTLE_LEVEL_SUB_MODE_1 = 0
};

class Battle: public GameState
{
public:
	Battle();
	~Battle();

	void Render();
	void Init( int level, int levelSubMode );

private:
	Map* mMap;
	Piece* mPieces;
};

#endif //__SSP__