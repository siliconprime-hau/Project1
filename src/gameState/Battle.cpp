#include "Battle.h"
#include <stdlib.h>
#include "spriteDefine/test_sprite.h"
#include "l2d.h"
#include "Res.h"
#include "Globals.h"
#include "Level.h"

#include "TouchGestureDetector.h"

using namespace TouchGestureDetector;

Battle::Battle()
{	
}

Battle::~Battle()
{
	delete mMap;
	delete[] mPieceHolders;
}

int tmp_num_piece = 8;

void Battle::Init( int level, int levelSubMode )
{	
	mMap = new Map( 4, 6 );	
	mPieceHolders = new PieceHolder[tmp_num_piece];

	mMap->SetPaintZone( gScreenHeight*LEVEL_MENU_PANEL_WIDTH + gScreenHeight*LEVEL_MAP_PADDING,
						gScreenHeight*LEVEL_MAP_PADDING,
						gScreenWidth - gScreenHeight*LEVEL_MENU_PANEL_WIDTH - gScreenHeight*LEVEL_MAP_PADDING*2,
						gScreenHeight - gScreenHeight*LEVEL_MAP_PADDING*2
						);
	
	ImageCover* test_sprite_img = new ImageCover( gResImage[TEST_SPRITE] );
	Sprite* piece_sprite = new Sprite( testModules, testFrames, testAnims, test_sprite_img );
	
	for( int i = 0; i< tmp_num_piece; i++ )
	{		
		mPieceHolders[i].mPiece = new Piece();
		//mPieceHolders[i].mPiece->Init( piece_sprite, 0, 1 );
	}

	//raw init
	mPieceHolders[0].mPiece->Init( piece_sprite, 4, 1 );
	mPieceHolders[0].mCurrentRow = 0;
	mPieceHolders[0].mCurrentColumn = 0;
	SetPosRC( mPieceHolders[0], 0, 0 );

	mPieceHolders[1].mPiece->Init( piece_sprite, 1, 2 );
	mPieceHolders[1].mCurrentRow = 0;
	mPieceHolders[1].mCurrentColumn = 2;

	mPieceHolders[2].mPiece->Init( piece_sprite, 2, 3 );
	mPieceHolders[2].mCurrentRow = 0;
	mPieceHolders[2].mCurrentColumn = 4;

	mPieceHolders[3].mPiece->Init( piece_sprite, 1, 3 );
	mPieceHolders[3].mCurrentRow = 2;
	mPieceHolders[3].mCurrentColumn = 1;

	mPieceHolders[4].mPiece->Init( piece_sprite, 2, 1 );
	mPieceHolders[4].mCurrentRow = 2;
	mPieceHolders[4].mCurrentColumn = 4;

	mPieceHolders[5].mPiece->Init( piece_sprite, 2, 1 );
	mPieceHolders[5].mCurrentRow = 3;
	mPieceHolders[5].mCurrentColumn = 0;

	mPieceHolders[6].mPiece->Init( piece_sprite, 0, 1 );
	mPieceHolders[6].mCurrentRow = 3;
	mPieceHolders[6].mCurrentColumn = 1;

	mPieceHolders[7].mPiece->Init( piece_sprite, 2, 1 );
	mPieceHolders[7].mCurrentRow = 3;
	mPieceHolders[7].mCurrentColumn = 5;

}

void Battle::UpdateMoving( PieceHolder &pieceHolder )
{
	float move_distance = (PIECE_MOVE_SPEED*gScreenHeight)*(gCurrentTimeMillis - pieceHolder.mLastMovingTime)/1000;
	//printf( "current time: %d, last time: %d, move distance: %f\n", gCurrentTimeMillis, pieceHolder.mLastMovingTime, move_distance );
	pieceHolder.mLastMovingTime = gCurrentTimeMillis;
	

	if( pieceHolder.mCurrentRow < pieceHolder.mNextRow )
	{
		if( pieceHolder.mPosY + move_distance < mMap->RowToY( pieceHolder.mNextRow ) )
		{
			pieceHolder.mPosY += move_distance;
		}
		else
		{
			pieceHolder.mPosY = mMap->RowToY( pieceHolder.mNextRow );
		}
	}
	else if( pieceHolder.mCurrentRow > pieceHolder.mNextRow )
	{
		if( pieceHolder.mPosY - move_distance > mMap->RowToY( pieceHolder.mNextRow ) )
		{
			pieceHolder.mPosY -= move_distance;
		}
		else
		{
			pieceHolder.mPosY = mMap->RowToY( pieceHolder.mNextRow );
		}
	}
	/*else
	{
		pieceHolder.mPosY = mMap->RowToY( pieceHolder.mNextRow );
	}*/
	
	if( pieceHolder.mCurrentColumn < pieceHolder.mNextColumn )
	{
		if( pieceHolder.mPosX + move_distance < mMap->ColumnToX( pieceHolder.mNextColumn ) )
		{
			pieceHolder.mPosX += move_distance;
		}
		else
		{
			pieceHolder.mPosX = mMap->ColumnToX( pieceHolder.mNextColumn );
		}
	}
	else if( pieceHolder.mCurrentColumn > pieceHolder.mNextColumn )
	{
		if( pieceHolder.mPosX - move_distance > mMap->ColumnToX( pieceHolder.mNextColumn ) )
		{
			pieceHolder.mPosX -= move_distance;
		}
		else
		{
			pieceHolder.mPosX = mMap->ColumnToX( pieceHolder.mNextColumn );
		}
	}
	/*else
	{
		pieceHolder.mPosX = mMap->ColumnToX( pieceHolder.mNextColumn );
	}*/

	//printf( "pos x: %f, pos y: %f\n", pieceHolder.mPosX, pieceHolder.mPosY );

	if(	pieceHolder.mPosY == mMap->RowToY( pieceHolder.mNextRow ) &&
		pieceHolder.mPosX == mMap->ColumnToX( pieceHolder.mNextColumn ) )
	{
		pieceHolder.isMoving = false;
		pieceHolder.mPiece->SetState( PIECE_STATE_STAND );
		pieceHolder.mCurrentColumn = pieceHolder.mNextColumn;
		pieceHolder.mCurrentRow = pieceHolder.mNextRow;
		//printf( "stop time: %d\n", gCurrentTimeMillis );
	}
}

void Battle::StartMoving( PieceHolder &pieceHolder )
{
	pieceHolder.isMoving = true;
	pieceHolder.mPiece->SetState( PIECE_STATE_MOVING );
	pieceHolder.mLastMovingTime = gCurrentTimeMillis;	
	//printf( "start time: %d\n", gCurrentTimeMillis );
}

void Battle::SetPosXY( PieceHolder &pieceHolder, float posX, float posY )
{
	pieceHolder.mPosX = posX;
	pieceHolder.mPosY = posY;
}

void Battle::SetPosRC( PieceHolder &pieceHolder, int row, int column )
{
	pieceHolder.mCurrentRow = row;
	pieceHolder.mCurrentColumn = column;
	pieceHolder.mNextRow = row;
	pieceHolder.mNextColumn = column;
	pieceHolder.mPosX = mMap->ColumnToX( column );
	pieceHolder.mPosY = mMap->RowToY( row );
}

void Battle::SetNextPosRC( PieceHolder &pieceHolder, int row, int column )
{
	pieceHolder.mNextRow = row;
	pieceHolder.mNextColumn = column;
}

void Battle::PaintRC( PieceHolder pieceHolder )
{
	pieceHolder.mPiece->Paint( mMap->ColumnToX( pieceHolder.mCurrentColumn ), mMap->RowToY( pieceHolder.mCurrentRow ) );
}

void Battle::PaintXY( PieceHolder pieceHolder )
{
	pieceHolder.mPiece->Paint( pieceHolder.mPosX, pieceHolder.mPosY );
}

void Battle::Update()
{	
	if( TouchGestureDetector::isClick( 0, 0, 100, 100 ) )
	{
		if( mPieceHolders[0].mPiece->GetState() == PIECE_STATE_MOVING )
		{
			mPieceHolders[0].mPiece->SetState( PIECE_STATE_STAND );
		}
		else
		{
			mPieceHolders[0].mPiece->SetState( PIECE_STATE_MOVING );
		}
	}


	int tmp = TouchGestureDetector::isFling( 0, 0, gScreenWidth, gScreenHeight );
	if( mPieceHolders[0].isMoving == false && tmp != FLING_NONE )
	{	
		if( tmp == FLING_DOWN )
		{
			SetNextPosRC( mPieceHolders[0],
				(mPieceHolders[0].mCurrentRow + 1)<mMap->GetNumRow()?(mPieceHolders[0].mCurrentRow + 1):mMap->GetNumRow()-1,
				mPieceHolders[0].mCurrentColumn );
		}
		else if( tmp == FLING_UP )
		{
			SetNextPosRC( mPieceHolders[0],
				(mPieceHolders[0].mCurrentRow - 1)>=0?(mPieceHolders[0].mCurrentRow - 1):0,
				mPieceHolders[0].mCurrentColumn );
		}
		else if( tmp == FLING_LEFT )
		{
			SetNextPosRC( mPieceHolders[0],
				mPieceHolders[0].mCurrentRow,
				(mPieceHolders[0].mCurrentColumn - 1)>=0?(mPieceHolders[0].mCurrentColumn - 1):0 );
		}
		else if( tmp == FLING_RIGHT )
		{
			SetNextPosRC( mPieceHolders[0],
				mPieceHolders[0].mCurrentRow,
				(mPieceHolders[0].mCurrentColumn + 1)<mMap->GetNumColumn()?(mPieceHolders[0].mCurrentColumn + 1):mMap->GetNumColumn()-1 );
		}
		StartMoving( mPieceHolders[0] );
	}

	//for( int i = 0; i< tmp_num_piece; i++ )
	{
		if( mPieceHolders[0].isMoving )
		{
			UpdateMoving( mPieceHolders[0] );
		}
	}
}

void Battle::Render()
{
	mMap->PaintMap();
	for( int i = 0; i< tmp_num_piece; i++ )
	{						
		if( mPieceHolders[i].isMoving )
		{
			PaintXY( mPieceHolders[i] );
		}
		else
		{
			PaintRC( mPieceHolders[i] );
		}
	}	
}
