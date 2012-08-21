#ifndef __PIECE__
#define __PIECE__

#include "l2d.h"

enum PieceState
{
	PIECE_STATE_STAND = 0,
	PIECE_STATE_MOVING = 1
};

struct Piece
{
	Sprite* mSprite;
	int mStateStandAnimId, mStateMovingAnimId;

	Piece();
	~Piece();
	void Init( Sprite* sprite, int stateStandAnimId, int stateMovingAnimId );
	void Paint( int state, float x, float y );
};

#endif //__PIECE__