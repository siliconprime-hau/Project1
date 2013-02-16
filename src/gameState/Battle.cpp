#include "Battle.h"
#include <stdlib.h>
#include "spriteDefine/spriteCharacters.h"
#include "l2d.h"
#include "Res.h"
#include "Globals.h"
#include "Level.h"

#include "TouchGestureDetector.h"
#include "KeyEventMng.h"


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

void Battle::Init( int level, int levelSubMode )
{	
	mCurrentState = BATTLE_STATE_STAND;
	mMap = new Map( 8, 12 );		
	mNumEnemy = 17;
	mEnemys = new PieceHolder[mNumEnemy];

	mMap->SetPaintZone( gScreenHeight*LEVEL_MENU_PANEL_WIDTH + gScreenHeight*LEVEL_MAP_PADDING,
						gScreenHeight*LEVEL_MAP_PADDING,
						gScreenWidth - gScreenHeight*LEVEL_MENU_PANEL_WIDTH - gScreenHeight*LEVEL_MAP_PADDING*2,
						gScreenHeight - gScreenHeight*LEVEL_MAP_PADDING*2
						);


	//TODO generate map
	int tmp_map_num_row = mMap->GetNumRow();
	int tmp_map_num_column = mMap->GetNumColumn();	
	for( int i = 0; i < tmp_map_num_row; i++ )
	{
		for( int j = 0; j < tmp_map_num_column; j++ )
		{
			int tmp_type = rand() % 9;
			//int tmp_type = rand() % 6 + 3;//tmp_type = TWO_WAY_ALWAYS_ON;

			if( i < ( tmp_map_num_row - 1 ) )
			{			
				if( tmp_type%2 > 0 )
				{
					mMap->SetBridge( i, j, i + 1, j, tmp_type );
				}
				else
				{
					mMap->SetBridge( i + 1, j, i, j, tmp_type );
				}
			}

			if( j < ( tmp_map_num_column - 1 ) )
			{				
				if( tmp_type%2 > 0 )
				{
					mMap->SetBridge( i, j, i, j + 1, tmp_type );
				}
				else
				{
					mMap->SetBridge( i, j + 1, i, j, tmp_type );
				}
			}
		}
	}
			
	ImageCover* characters_sprite_img = new ImageCover( gResImage[CHARACTERS_SPRITE] );
	Sprite* piece_sprite = new Sprite( charModules, charFrames, charAnims, characters_sprite_img );
		
	mMainChar.mPiece =  new Piece();
	for( int i = 0; i< mNumEnemy; i++ )
	{		
		mEnemys[i].mPiece = new Piece();
	}

	//TODO raw init
	mMainChar.mPiece->Init( piece_sprite, 25, 24 );
	mMainChar.mCurrentRow = 0;
	mMainChar.mCurrentColumn = 0;
	SetPosRC( mMainChar, 0, 0 );

	int tmp_max_num_sprite = 24;
	int tmp_max_enemy_type = ENEMY_TYPE_HORIZONTAL_R1 + 1;
	for( int i = 0; i < mNumEnemy; i++ )
	{
		int tmp_row = rand()%tmp_map_num_row;
		int tmp_column = rand()%tmp_map_num_column;		
		int tmp_type = rand()%tmp_max_enemy_type;

		mEnemys[i].mType = tmp_type;
		mEnemys[i].mPiece->Init( piece_sprite, tmp_type%tmp_max_num_sprite, 25 );
		mEnemys[i].mCurrentRow = tmp_row;
		mEnemys[i].mCurrentColumn = tmp_column;
		SetPosRC( mEnemys[i], tmp_row, tmp_column );
	}

	//mEnemys[0].mPiece->Init( piece_sprite, 6, 25 );
	//mEnemys[0].mCurrentRow = 3;
	//mEnemys[0].mCurrentColumn = 5;
	//SetPosRC( mEnemys[7], 3, 5 );

	//mEnemys[1].mPiece->Init( piece_sprite, 0, 25 );
	//mEnemys[1].mCurrentRow = 0;
	//mEnemys[1].mCurrentColumn = 2;
	//SetPosRC( mEnemys[1], 0, 2 );

	//mEnemys[2].mPiece->Init( piece_sprite, 1, 25 );
	//mEnemys[2].mCurrentRow = 0;
	//mEnemys[2].mCurrentColumn = 4;
	//SetPosRC( mEnemys[2], 0, 4 );

	//mEnemys[3].mPiece->Init( piece_sprite, 2, 25 );
	//mEnemys[3].mCurrentRow = 2;
	//mEnemys[3].mCurrentColumn = 1;
	//SetPosRC( mEnemys[3], 2, 1 );

	//mEnemys[4].mPiece->Init( piece_sprite, 3, 25 );
	//mEnemys[4].mCurrentRow = 2;
	//mEnemys[4].mCurrentColumn = 4;
	//SetPosRC( mEnemys[4], 2, 4 );

	//mEnemys[5].mPiece->Init( piece_sprite, 4, 25 );
	//mEnemys[5].mCurrentRow = 3;
	//mEnemys[5].mCurrentColumn = 0;
	//SetPosRC( mEnemys[5], 3, 0 );

	//mEnemys[6].mPiece->Init( piece_sprite, 5, 25 );
	//mEnemys[6].mCurrentRow = 3;
	//mEnemys[6].mCurrentColumn = 1;
	//SetPosRC( mEnemys[6], 3, 1 );	

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
	else
	{
		pieceHolder.mPosY = mMap->RowToY( pieceHolder.mNextRow );
	}
	
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
	else
	{
		pieceHolder.mPosX = mMap->ColumnToX( pieceHolder.mNextColumn );
	}
	
	if(	pieceHolder.mPosY == mMap->RowToY( pieceHolder.mNextRow ) &&
		pieceHolder.mPosX == mMap->ColumnToX( pieceHolder.mNextColumn ) )
	{
		pieceHolder.isMoving = false;
		pieceHolder.mPiece->SetState( PIECE_STATE_STAND );
		pieceHolder.mPreviousColumn = pieceHolder.mCurrentColumn;
		pieceHolder.mPreviousRow = pieceHolder.mCurrentRow;
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
	pieceHolder.mPreviousRow = row;
	pieceHolder.mPreviousColumn = column;
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

void Battle::FindNextPos( PieceHolder &pieceHolder )
{
	int tmp_map_num_row = mMap->GetNumRow();
	int tmp_map_num_column = mMap->GetNumColumn();

	switch( pieceHolder.mType )
	{
	case ENEMY_TYPE_TO_TARGET_R1://TODO find pos
		//break;
	case ENEMY_TYPE_RANDOM_KNOW_R1:
	case ENEMY_TYPE_RANDOM_UNKNOW_R1:
		{			
			int next = rand()%4;
			if( next == 0 )//up
			{
				MoveUp( pieceHolder );
			}
			else if( next == 1 )//down
			{
				MoveDown( pieceHolder );
			}
			else if( next == 2 )//left
			{
				MoveLeft( pieceHolder );
			}
			else //right
			{
				MoveRight( pieceHolder );
			}
		}
		break;	
	case ENEMY_TYPE_UP_DOWN_R1:
		MoveDown( pieceHolder );
		break;
	case ENEMY_TYPE_DOWN_UP_R1:
		MoveUp( pieceHolder );
		break;
	case ENEMY_TYPE_LEFT_RIGHT_R1:
		MoveRight( pieceHolder );
		break;
	case ENEMY_TYPE_RIGHT_LEFT_R1:
		MoveLeft( pieceHolder );
		break;
	case ENEMY_TYPE_VERTICAL_R1:
		if( pieceHolder.mCurrentRow > pieceHolder.mPreviousRow )//moving down
		{
			if(	mMap->isMoveable( pieceHolder.mCurrentRow, pieceHolder.mCurrentColumn,
				(pieceHolder.mCurrentRow + 1)<mMap->GetNumRow()?(pieceHolder.mCurrentRow + 1):mMap->GetNumRow()-1,
				pieceHolder.mCurrentColumn ) == false )//can not move down, change to move up
			{
				MoveUp( pieceHolder );
			}
			else
			{
				MoveDown( pieceHolder );
			}
		}
		else //moving up
		{
			if(	mMap->isMoveable( pieceHolder.mCurrentRow, pieceHolder.mCurrentColumn,
				(pieceHolder.mCurrentRow - 1)>=0?(pieceHolder.mCurrentRow - 1):0,
				pieceHolder.mCurrentColumn ) == false )//can not move up, change to move down
			{
				MoveDown( pieceHolder );
			}
			else
			{
				MoveUp( pieceHolder );
			}
		}		
		break;
	case ENEMY_TYPE_HORIZONTAL_R1:
		if( pieceHolder.mCurrentColumn > pieceHolder.mPreviousColumn )//moving right
		{
			if(	mMap->isMoveable( pieceHolder.mCurrentRow, pieceHolder.mCurrentColumn, pieceHolder.mCurrentRow,
				(pieceHolder.mCurrentColumn + 1)<mMap->GetNumColumn()?(pieceHolder.mCurrentColumn + 1):mMap->GetNumColumn()-1 ) == false )//can not move right, change to move left
			{
				MoveLeft( pieceHolder );
			}
			else
			{
				MoveRight( pieceHolder );
			}
		}
		else //moving left
		{
			if(	mMap->isMoveable( pieceHolder.mCurrentRow, pieceHolder.mCurrentColumn, pieceHolder.mCurrentRow,
				(pieceHolder.mCurrentColumn - 1)>=0?(pieceHolder.mCurrentColumn - 1):0 ) == false )//can not move left, change to move right
			{
				MoveRight( pieceHolder );
			}
			else
			{
				MoveLeft( pieceHolder );
			}
		}
		break;
		//TODO more case
	}
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
		mCurrentState = BATTLE_STATE_MOVING;
		UpdateStateChange();
	}

	if( mMainChar.isMoving == false && KeyEventMng::GetKeyAction( KC_UP ) == KEY_UP )
	{
		MoveUp(mMainChar);
		StartMoving( mMainChar );
		tmp_is_start_move = true;
		mCurrentState = BATTLE_STATE_MOVING;
		UpdateStateChange();
	}
	if( mMainChar.isMoving == false && KeyEventMng::GetKeyAction( KC_DOWN ) == KEY_UP )
	{
		MoveDown(mMainChar);
		StartMoving( mMainChar );
		tmp_is_start_move = true;
		mCurrentState = BATTLE_STATE_MOVING;
		UpdateStateChange();
	}
	if( mMainChar.isMoving == false && KeyEventMng::GetKeyAction( KC_LEFT ) == KEY_UP )
	{
		MoveLeft(mMainChar);
		StartMoving( mMainChar );
		tmp_is_start_move = true;
		mCurrentState = BATTLE_STATE_MOVING;
		UpdateStateChange();
	}
	if( mMainChar.isMoving == false && KeyEventMng::GetKeyAction( KC_RIGHT ) == KEY_UP )
	{
		MoveRight(mMainChar);
		StartMoving( mMainChar );
		tmp_is_start_move = true;
		mCurrentState = BATTLE_STATE_MOVING;
		UpdateStateChange();
	}


	//TODO draft: random move enemy
	for( int i = 0; i< mNumEnemy; i++ )
	{
		if( mEnemys[i].isMoving == false && tmp_is_start_move == true )
		{
			/*int tmp_direction = rand() % 4;
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
			}*/
			FindNextPos( mEnemys[i] );
			StartMoving( mEnemys[i] );
		}
	}


	if( mMainChar.isMoving )
	{
		UpdateMoving( mMainChar );
	}
	for( int i = 0; i< mNumEnemy; i++ )
	{
		if( mEnemys[i].isMoving )
		{
			UpdateMoving( mEnemys[i] );
		}
	}

	if( mCurrentState == BATTLE_STATE_MOVING )
	{
		int tmp_is_moving;
		tmp_is_moving = mMainChar.isMoving;

		for( int i = 0; i< mNumEnemy; i++ )
		{
			if( mEnemys[i].isMoving == true )
			{
				tmp_is_moving = true;
				break;
			}
		}

		if( !tmp_is_moving )
		{
			mCurrentState = BATTLE_STATE_STAND;
			UpdateStateChange();
		}
	}
}

void Battle::UpdateStateChange()
{
	if( mCurrentState == BATTLE_STATE_STAND )//update moving finish
	{
		int tmp_map_num_row = mMap->GetNumRow();
		int tmp_map_num_column = mMap->GetNumColumn();		
		for( int i = 0; i < tmp_map_num_row; i++ )
		{
			for( int j = 0; j < tmp_map_num_column; j++ )
			{				
				if( i < ( tmp_map_num_row - 1 ) )
				{								
					UpdateMapBridgeState( i, j, i + 1, j );
				}

				if( j < ( tmp_map_num_column - 1 ) )
				{				
					UpdateMapBridgeState( i, j, i, j + 1 );
				}
			}
		}
	}
}

void Battle::UpdateMapBridgeState( int row1, int column1, int row2, int column2 )
{
	int bridge12 = mMap->GetBridge( row1, column1, row2, column2 );
	int bridge21 = mMap->GetBridge( row2, column2, row1, column1 );
		
	if( bridge12 == TWO_WAY_ONE_TIME )
	{
		if( isBridgePass( row1, column1, row2, column2 ) )
		{
			mMap->SetBridge( row1, column1, row2, column2, UNBRIDGE );
		}
	}
	else if( bridge12 == ONE_WAY_ONE_TIME )
	{
		if( isBridgePass( row1, column1, row2, column2 ) )
		{
			mMap->SetBridge( row1, column1, row2, column2, UNBRIDGE );
		}
	}
	else if( bridge12 == TWO_WAY_ONOFF_ON )
	{
		mMap->SetBridge( row1, column1, row2, column2, TWO_WAY_ONOFF_OFF );
	}
	else if( bridge12 == TWO_WAY_ONOFF_OFF )
	{
		mMap->SetBridge( row1, column1, row2, column2, TWO_WAY_ONOFF_ON );
	}
	else if( bridge12 == ONE_WAY_ONOFF_ON )
	{
		mMap->SetBridge( row1, column1, row2, column2, ONE_WAY_ONOFF_OFF );
	}
	else if( bridge12 == ONE_WAY_ONOFF_OFF )
	{
		mMap->SetBridge( row1, column1, row2, column2, ONE_WAY_ONOFF_ON );
	}
	//--------------------------------------
	else if( bridge21 == ONE_WAY_ONE_TIME )
	{
		if( isBridgePass( row1, column1, row2, column2 ) )
		{
			mMap->SetBridge( row2, column2, row1, column1, UNBRIDGE );
		}
	}
	else if( bridge21 == ONE_WAY_ONOFF_ON )
	{
		mMap->SetBridge( row2, column2, row1, column1, ONE_WAY_ONOFF_OFF );
	}
	else if( bridge21 == ONE_WAY_ONOFF_OFF )
	{
		mMap->SetBridge( row2, column2, row1, column1, ONE_WAY_ONOFF_ON );
	}
}

bool Battle::isPass( PieceHolder pieceHolder, int row1, int column1, int row2, int column2 )
{
	if(	( pieceHolder.mCurrentColumn == column1 && pieceHolder.mCurrentRow == row1 && 
		pieceHolder.mPreviousColumn == column2 && pieceHolder.mPreviousRow == row2 ) ||
		( pieceHolder.mCurrentColumn == column2 && pieceHolder.mCurrentRow == row2 && 
		pieceHolder.mPreviousColumn == column1 && pieceHolder.mPreviousRow == row1 ) )
	{
		return true;
	}

	return false;
}

bool Battle::isBridgePass( int row1, int column1, int row2, int column2 )
{
	if( isPass( mMainChar, row1, column1, row2, column2 ) )
	{
		return true;
	}

	for( int i = 0; i < mNumEnemy; i++ )
	{
		if( isPass( mEnemys[i], row1, column1, row2, column2 ) )
		{
			return true;
		}
	}

	return false;
}

void Battle::Render()
{
	mMap->PaintMap();
	for( int i = 0; i< mNumEnemy; i++ )
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
