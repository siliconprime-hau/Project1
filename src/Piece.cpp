#include "Piece.h"

Piece::Piece( Sprite* sprite, int stateStandAnimId, int stateMovingAnimId )
{
	mSprite = sprite;
	mStateStandAnimId = stateStandAnimId;
	mStateMovingAnimId = stateMovingAnimId;
}

Piece::~Piece()
{
}

void Piece::Paint( int state, float x, float y )
{
	if( state == PIECE_STATE_STAND )
	{
		mSprite->PaintAnim( mStateStandAnimId, x, y );
	}
	else if( state == PIECE_STATE_MOVING )
	{
		mSprite->PaintAnim( mStateMovingAnimId, x, y );
	}
}
