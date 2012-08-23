#include "Battle.h"
#include <stdlib.h>
#include "spriteDefine/test_sprite.h"
#include "l2d.h"
#include "Res.h"
#include "Globals.h"

Battle::Battle()
{	
}

Battle::~Battle()
{
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
	mPieceHolders[0].mPiece->Init( piece_sprite, 0, 1 );
	mPieceHolders[0].mCurrentRow = 0;
	mPieceHolders[0].mCurrentColumn = 0;

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

	mPieceHolders[5].mPiece->Init( piece_sprite, 3, 1 );
	mPieceHolders[5].mCurrentRow = 3;
	mPieceHolders[5].mCurrentColumn = 0;

	mPieceHolders[6].mPiece->Init( piece_sprite, 0, 1 );
	mPieceHolders[6].mCurrentRow = 3;
	mPieceHolders[6].mCurrentColumn = 1;

	mPieceHolders[7].mPiece->Init( piece_sprite, 0, 1 );
	mPieceHolders[7].mCurrentRow = 3;
	mPieceHolders[7].mCurrentColumn = 5;

}

void Battle::PaintRC( PieceHolder pieceHolder )
{
	pieceHolder.mPiece->Paint( mMap->ColumnToX( pieceHolder.mCurrentColumn ), mMap->RowToY( pieceHolder.mCurrentRow ) );
}

void Battle::PaintXY( PieceHolder pieceHolder )
{
	pieceHolder.mPiece->Paint( pieceHolder.mPosX, pieceHolder.mPosY );
}

void Battle::Render()
{
	mMap->PaintMap();
	for( int i = 0; i< tmp_num_piece; i++ )
	{				
		//mPieceHolders[2].mPiece->Paint( 100, 100 );
		PaintRC( mPieceHolders[i] );
	}	
}
