#ifndef __PIECE__
#define __PIECE__

#include "Sprite.h"

enum PieceState
{
	PIECE_STATE_STAND = 0,
	PIECE_STATE_MOVING = 1
};

struct Piece
{
	Sprite* mSprite;
	int mStateStandAnimId, mStateMovingAnimId;

	Piece( Sprite* sprite, int stateStandAnimId, int stateMovingAnimId );
	~Piece();
	void Paint( int state, float x, float y );
};

#endif //__PIECE__