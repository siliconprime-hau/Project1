#include "Battle.h"
#include <stdlib.h>
#include "spriteDefine/spriteCharacters.h"
#include "l2d.h"
#include "Res.h"
#include "Globals.h"
#include "Level.h"

#include "TouchGestureDetector.h"
#include "KeyEventMng.h"

#include <Windows.h>
#include <ctime>

using namespace TouchGestureDetector;
using namespace KeyEventMng;

Battle::Battle()
{	
}

Battle::~Battle()
{
	delete mMap;
	delete[] mEnemys;
}

int tmp_num_enemy = 7;

void Battle::Init( int level, int levelSubMode )
{	
	mMap = new Map( 4, 6 );		
	mEnemys = new PieceHolder[tmp_num_enemy];

	mMap->SetPaintZone( gScreenHeight*LEVEL_MENU_PANEL_WIDTH + gScreenHeight*LEVEL_MAP_PADDING,
						gScreenHeight*LEVEL_MAP_PADDING,
						gScreenWidth - gScreenHeight*LEVEL_MENU_PANEL_WIDTH - gScreenHeight*LEVEL_MAP_PADDING*2,
						gScreenHeight - gScreenHeight*LEVEL_MAP_PADDING*2
						);


	//generate map
	int tmp_map_num_row = mMap->GetNumRow();
	int tmp_map_num_column = mMap->GetNumColumn();
	srand(time(0));
	for( int i = 0; i < tmp_map_num_row; i++ )
	{
		for( int j = 0; j < tmp_map_num_column; j++ )
		{
			int tmp_type = rand() % 7;

			if( i < ( tmp_map_num_row - 1 ) )
			{			
				mMap->SetBridge( i, j, i + 1, j, tmp_type );
			}

			if( j < ( tmp_map_num_column - 1 ) )
			{				
				mMap->SetBridge( i, j, i, j + 1, tmp_type );
			}
		}
	}
			
	ImageCover* characters_sprite_img = new ImageCover( gResImage[CHARACTERS_SPRITE] );
	Sprite* piece_sprite = new Sprite( charModules, charFrames, charAnims, characters_sprite_img );
		
	mMainChar.mPiece =  new Piece();
	for( int i = 0; i< tmp_num_enemy; i++ )
	{		
		mEnemys[i].mPiece = new Piece();
	}

	//raw init
	mMainChar.mPiece->Init( piece_sprite, 25, 24 );
	mMainChar.mCurrentRow = 0;
	mMainChar.mCurrentColumn = 0;
	SetPosRC( mMainChar, 0, 0 );

	mEnemys[0].mPiece->Init( piece_sprite, 6, 25 );
	mEnemys[0].mCurrentRow = 3;
	mEnemys[0].mCurrentColumn = 5;
	SetPosRC( mEnemys[7], 3, 5 );

	mEnemys[1].mPiece->Init( piece_sprite, 0, 25 );
	mEnemys[1].mCurrentRow = 0;
	mEnemys[1].mCurrentColumn = 2;
	SetPosRC( mEnemys[1], 0, 2 );

	mEnemys[2].mPiece->Init( piece_sprite, 1, 25 );
	mEnemys[2].mCurrentRow = 0;
	mEnemys[2].mCurrentColumn = 4;
	SetPosRC( mEnemys[2], 0, 4 );

	mEnemys[3].mPiece->Init( piece_sprite, 2, 25 );
	mEnemys[3].mCurrentRow = 2;
	mEnemys[3].mCurrentColumn = 1;
	SetPosRC( mEnemys[3], 2, 1 );

	mEnemys[4].mPiece->Init( piece_sprite, 3, 25 );
	mEnemys[4].mCurrentRow = 2;
	mEnemys[4].mCurrentColumn = 4;
	SetPosRC( mEnemys[4], 2, 4 );

	mEnemys[5].mPiece->Init( piece_sprite, 4, 25 );
	mEnemys[5].mCurrentRow = 3;
	mEnemys[5].mCurrentColumn = 0;
	SetPosRC( mEnemys[5], 3, 0 );

	mEnemys[6].mPiece->Init( piece_sprite, 5, 25 );
	mEnemys[6].mCurrentRow = 3;
	mEnemys[6].mCurrentColumn = 1;
	SetPosRC( mEnemys[6], 3, 1 );	
}

void Battle::UpdateMoving( PieceHolder &pieceHolder )
{
	if( mMap->isCanMove( pieceHolder.mCurrentRow, pieceHolder.mCurrentColumn, pieceHolder.mNextRow, pieceHolder.mNextColumn ) == false )
	{
		pieceHolder.isMoving = false;
		pieceHolder.mPiece->SetState( PIECE_STATE_STAND );
		pieceHolder.mNextColumn = pieceHolder.mCurrentColumn;
		pieceHolder.mNextRow = pieceHolder.mCurrentRow;
		
		return;
	}

	float move_distance = (PIECE_MOVE_SPEED*gScreenHeight)*(gCurrentTimeMillis - pieceHolder.mLastMovingTime)/1000;
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
	
	if(	pieceHolder.mPosY == mMap->RowToY( pieceHolder.mNextRow ) &&
		pieceHolder.mPosX == mMap->ColumnToX( pieceHolder.mNextColumn ) )
	{
		pieceHolder.isMoving = false;
		pieceHolder.mPiece->SetState( PIECE_STATE_STAND );
		pieceHolder.mCurrentColumn = pieceHolder.mNextColumn;
		pieceHolder.mCurrentRow = pieceHolder.mNextRow;
	}
}

void Battle::StartMoving( PieceHolder &pieceHolder )
{
	pieceHolder.isMoving = true;
	pieceHolder.mPiece->SetState( PIECE_STATE_MOVING );
	pieceHolder.mLastMovingTime = gCurrentTimeMillis;		
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


void Battle::MoveUp( PieceHolder &pieceHolder )
{
	SetNextPosRC( pieceHolder,
				(pieceHolder.mCurrentRow - 1)>=0?(pieceHolder.mCurrentRow - 1):0,
				pieceHolder.mCurrentColumn );
}

void Battle::MoveDown( PieceHolder &pieceHolder )
{
	SetNextPosRC( pieceHolder,
				(pieceHolder.mCurrentRow + 1)<mMap->GetNumRow()?(pieceHolder.mCurrentRow + 1):mMap->GetNumRow()-1,
				pieceHolder.mCurrentColumn );
}

void Battle::MoveLeft( PieceHolder &pieceHolder )
{
	SetNextPosRC( pieceHolder,
				pieceHolder.mCurrentRow,
				(pieceHolder.mCurrentColumn - 1)>=0?(pieceHolder.mCurrentColumn - 1):0 );
}

void Battle::MoveRight( PieceHolder &pieceHolder )
{
	SetNextPosRC( pieceHolder,
				pieceHolder.mCurrentRow,
				(pieceHolder.mCurrentColumn + 1)<mMap->GetNumColumn()?(pieceHolder.mCurrentColumn + 1):mMap->GetNumColumn()-1 );
}


void Battle::Update()
{	
	/*if( TouchGestureDetector::isClick( 0, 0, 100, 100 ) )
	{
		if( mMainChar.mPiece->GetState() == PIECE_STATE_MOVING )
		{
			mMainChar.mPiece->SetState( PIECE_STATE_STAND );
		}
		else
		{
			mMainChar.mPiece->SetState( PIECE_STATE_MOVING );
		}
	}*/
	bool tmp_is_start_move = false;


	int tmp = TouchGestureDetector::isFling( 0, 0, gScreenWidth, gScreenHeight );
	if( mMainChar.isMoving == false && tmp != FLING_NONE )
	{	
		if( tmp == FLING_DOWN )
		{
			MoveDown(mMainChar);
		}
		else if( tmp == FLING_UP )
		{
			MoveUp(mMainChar);
		}
		else if( tmp == FLING_LEFT )
		{
			MoveLeft(mMainChar);
		}
		else if( tmp == FLING_RIGHT )
		{
			MoveRight(mMainChar);
		}
		StartMoving( mMainChar );
		tmp_is_start_move = true;
	}

	if( mMainChar.isMoving == false && KeyEventMng::GetKeyAction( VK_UP ) == KEY_UP )
	{
		MoveUp(mMainChar);
		StartMoving( mMainChar );
		tmp_is_start_move = true;
	}
	if( mMainChar.isMoving == false && KeyEventMng::GetKeyAction( VK_DOWN ) == KEY_UP )
	{
		MoveDown(mMainChar);
		StartMoving( mMainChar );
		tmp_is_start_move = true;
	}
	if( mMainChar.isMoving == false && KeyEventMng::GetKeyAction( VK_LEFT ) == KEY_UP )
	{
		MoveLeft(mMainChar);
		StartMoving( mMainChar );
		tmp_is_start_move = true;
	}
	if( mMainChar.isMoving == false && KeyEventMng::GetKeyAction( VK_RIGHT ) == KEY_UP )
	{
		MoveRight(mMainChar);
		StartMoving( mMainChar );
		tmp_is_start_move = true;
	}


	//draft: random move enemy
	for( int i = 0; i< tmp_num_enemy; i++ )
	{
		if( mEnemys[i].isMoving == false && tmp_is_start_move == true )
		{
			int tmp_direction = rand() % 4;
			switch(tmp_direction)
			{
			case 0:
				MoveUp(mEnemys[i]);
				break;
			case 1:
				MoveDown(mEnemys[i]);
				break;
			case 2:
				MoveLeft(mEnemys[i]);
				break;
			case 3:
				MoveRight(mEnemys[i]);
				break;
			}
			StartMoving( mEnemys[i] );
		}
	}


	if( mMainChar.isMoving )
	{
		UpdateMoving( mMainChar );
	}
	for( int i = 0; i< tmp_num_enemy; i++ )
	{
		if( mEnemys[i].isMoving )
		{
			UpdateMoving( mEnemys[i] );
		}
	}
}

void Battle::Render()
{
	mMap->PaintMap();
	for( int i = 0; i< tmp_num_enemy; i++ )
	{						
		if( mEnemys[i].isMoving )
		{
			PaintXY( mEnemys[i] );
		}
		else
		{
			PaintRC( mEnemys[i] );
		}
	}	

	if( mMainChar.isMoving )
	{
		PaintXY( mMainChar );
	}
	else
	{
		PaintRC( mMainChar );
	}
}
