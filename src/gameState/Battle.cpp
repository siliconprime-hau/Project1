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

void Battle::Init( int level, int levelSubMode )
{
	mMap = new Map( 8, 10 );
	mPieces = new Piece[8];


	mMap->SetPaintZone( gScreenHeight*LEVEL_MENU_PANEL_WIDTH + gScreenHeight*LEVEL_MAP_PADDING,
						gScreenHeight*LEVEL_MAP_PADDING,
						gScreenWidth - gScreenHeight*LEVEL_MENU_PANEL_WIDTH - gScreenHeight*LEVEL_MAP_PADDING*2,
						gScreenHeight - gScreenHeight*LEVEL_MAP_PADDING*2
						);
	
	ImageCover* test_sprite_img = new ImageCover( gResImage[TEST_SPRITE] );
	Sprite* piece_sprite = new Sprite( testModules, testFrames, testAnims, test_sprite_img );
	for( int i = 0; i< 8; i++ )
	{
		mPieces[i].Init( piece_sprite, 0, 1 );
	}
}

void Battle::Render()
{
	mMap->PaintMap();
}
