#ifndef __SSP__
#define __SSP__

#include "GameState.h"
#include "Map.h"
#include "Piece.h"




#define PIECE_MOVE_SPEED		0.5//0.05 = 5% of screen height per second




enum BATTLE_LEVEL//game difficult level
{
	BATTLE_LEVEL_1 = 0
};

enum BATTLE_LEVEL_SUB_MODE//game level sub mode 
{
	BATTLE_LEVEL_SUB_MODE_1 = 0
};


enum BATTLE_STATE
{
	BATTLE_STATE_STAND = 0,
	BATTLE_STATE_MOVING
};


struct PieceHolder
{
	unsigned long mLastMovingTime;
	bool isMoving;
	float mPosX, mPosY;
	int mPreviousRow, mPreviousColumn;
	int mCurrentRow, mCurrentColumn;
	int mNextRow, mNextColumn;
	Piece* mPiece;
	PieceHolder()
	{
		isMoving = false;
	}
};

class Battle: public GameState
{
public:
	Battle();
	~Battle();
	
	void Init( int level, int levelSubMode );
	void Update();
	void Render();

private:	
	int mNumEnemy;
	int mCurrentState;
	Map* mMap;	
	PieceHolder* mEnemys;
	PieceHolder mMainChar;
	
	void SetPosXY( PieceHolder &pieceHolder, float posX, float posY );
	void SetPosRC( PieceHolder &pieceHolder, int row, int column );
	void SetNextPosRC( PieceHolder &pieceHolder, int row, int column );
	void UpdateMoving( PieceHolder &pieceHolder );
	void StartMoving( PieceHolder &pieceHolder );
	void PaintRC( PieceHolder pieceHolder );//paint by current row/column
	void PaintXY( PieceHolder pieceHolder );//paint by posx/poxy

	void MoveUp( PieceHolder &pieceHolder );
	void MoveDown( PieceHolder &pieceHolder );
	void MoveLeft( PieceHolder &pieceHolder );
	void MoveRight( PieceHolder &pieceHolder );

	void UpdateStateChange();
	void UpdateMapBridgeState( int row1, int column1, int row2, int column2 );
	//check if piece has just pass this bridge
	bool isPass( PieceHolder pieceHolder, int row1, int column1, int row2, int column2 );
	//check if bright has just passed
	bool isBridgePass( int row1, int column1, int row2, int column2 );
};

#endif //__SSP__