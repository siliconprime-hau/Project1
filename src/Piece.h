#ifndef __PIECE__
#define __PIECE__

#include "l2d.h"



enum PIECE_STATE
{
	PIECE_STATE_STAND = 0,
	PIECE_STATE_MOVING = 1
};

struct Piece
{
	Sprite* mSprite;
	int mStateStandAnimId, mStateMovingAnimId;
	int mState;
	
	Piece();
	~Piece();
	void Init( Sprite* sprite, int stateStandAnimId, int stateMovingAnimId );
	void Paint( float x, float y );
	void PaintA( float x, float y, int anchor_h, int anchor_v );
	void SetState( int state ){ mState = state; }
	int GetState(){ return mState; }
};

#endif //__PIECE__