#include "Piece.h"

Piece::Piece()
{	
}

Piece::~Piece()
{
}

void Piece::Init( Sprite* sprite, int stateStandAnimId, int stateMovingAnimId )
{
	mSprite = sprite;
	mStateStandAnimId = stateStandAnimId;
	mStateMovingAnimId = stateMovingAnimId;
	mState = PIECE_STATE_STAND;
}

void Piece::SetState( int state )
{
	mState = state;
}

void Piece::Paint( float x, float y )
{
	PaintA( x, y, ANCHOR_CENTER, ANCHOR_CENTER );//default anchor is center
}

void Piece::PaintA( float x, float y, int anchor_h, int anchor_v )
{
	if( mState == PIECE_STATE_STAND )
	{
		mSprite->PaintAnimA( mStateStandAnimId, x, y, anchor_h, anchor_v );
	}
	else if( mState == PIECE_STATE_MOVING )
	{
		mSprite->PaintAnimA( mStateMovingAnimId, x, y, anchor_h, anchor_v );
	}
}
