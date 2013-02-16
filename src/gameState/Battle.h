#ifndef __BATTLE__
#define __BATTLE__

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



enum ENEMY_TYPE
{
	ENEMY_TYPE_TO_TARGET_R1 = 0,//range = 1
	ENEMY_TYPE_RANDOM_KNOW_R1,
	ENEMY_TYPE_RANDOM_UNKNOW_R1,
	ENEMY_TYPE_VERTICAL_R1,
	ENEMY_TYPE_HORIZONTAL_R1,
	ENEMY_TYPE_UP_DOWN_R1,
	ENEMY_TYPE_DOWN_UP_R1,
	ENEMY_TYPE_LEFT_RIGHT_R1,
	ENEMY_TYPE_RIGHT_LEFT_R1,
	ENEMY_TYPE_TO_TARGET_R2,//range = 2
	ENEMY_TYPE_RANDOM_KNOW_R2,
	ENEMY_TYPE_RANDOM_UNKNOW_R2,
	ENEMY_TYPE_VERTICAL_R2,
	ENEMY_TYPE_HORIZONTAL_R2,
	ENEMY_TYPE_UP_DOWN_R2,
	ENEMY_TYPE_DOWN_UP_R2,
	ENEMY_TYPE_LEFT_RIGHT_R2,
	ENEMY_TYPE_RIGHT_LEFT_R2	
};

#define DEFAULT_ENEMY_TYPE	ENEMY_TYPE_TO_TARGET_R1

struct PieceHolder
{
	unsigned long mLastMovingTime;
	bool isMoving;
	float mPosX, mPosY;
	int mPreviousRow, mPreviousColumn;
	int mCurrentRow, mCurrentColumn;
	int mNextRow, mNextColumn;
	int mType;
	Piece* mPiece;
	PieceHolder()
	{
		isMoving = false;
		mType = DEFAULT_ENEMY_TYPE;
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
	void FindNextPos( PieceHolder &pieceHolder );

	void UpdateStateChange();
	void UpdateMapBridgeState( int row1, int column1, int row2, int column2 );
	//check if piece has just pass this bridge
	bool isPass( PieceHolder pieceHolder, int row1, int column1, int row2, int column2 );
	//check if bright has just passed
	bool isBridgePass( int row1, int column1, int row2, int column2 );
};

#endif //__BATTLE__
