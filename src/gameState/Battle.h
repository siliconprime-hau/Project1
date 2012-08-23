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

struct PieceHolder
{
	float mPosX, mPosY;
	int mCurrentRow, mCurrentColumn;
	Piece* mPiece;	
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
	PieceHolder* mPieceHolders;
	
	void PaintRC( PieceHolder pieceHolder );//paint by current row/column
	void PaintXY( PieceHolder pieceHolder );//paint by posx/poxy
};

#endif //__SSP__