#include "Map.h"
#include "l2d.h"

//raw init
#include "Globals.h"

	int X = LINK;
	int B = UNLINK;
	
	unsigned char tmp[24][24] =//4 row/6 column
	{
		/*0*/	{	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
		/*1*/	{	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
		/*2*/	{	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
		/*3*/	{	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
		/*4*/	{	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
		/*5*/	{	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
		/*6*/	{	X,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
		/*7*/	{	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
		/*8*/	{	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
		/*9*/	{	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0 },
		/*10*/	{	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0 },
		/*11*/	{	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0 },
		/*12*/	{	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0 },
		/*13*/	{	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0 },
		/*14*/	{	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0 },
		/*15*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0 },
		/*16*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0 },
		/*17*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	X },
		/*18*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0 },
		/*19*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0 },
		/*20*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0 },
		/*21*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0 },
		/*22*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X },
		/*23*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0 }
	};


Map::Map( int numRow, int numColumn )
{
	mNumRow = numRow;
	mNumColumn = numColumn;


	//raw init	
	mNumRow = 4;
	mNumColumn = 6;
	int tmp_row_column = 24;//row*column
	mMap = new unsigned char*[tmp_row_column];
	for( int i = 0; i < tmp_row_column; i++ )
	{
		mMap[i] = new unsigned char[tmp_row_column];
	}
	for( int i = 0; i < tmp_row_column; i++ )
	{
		for( int j = 0; j < tmp_row_column; j++ )
		{			
			mMap[i][j] = tmp[i][j];			
		}
	}

	/*mMap = new unsigned char*[mNumRow];
	for( int i = 0; i < mNumRow; i++ )
	{
		mMap[i] = new unsigned char[mNumColumn];
	}

	for( int i = 0; i < mNumRow; i++ )
	{
		for( int j = 0; j < mNumColumn; j++ )
		{
			if( i%2 == 0 && j%2 == 0)
				mMap[i][j] = LINK;
			else
				mMap[i][j] = UNLINK;
		}
	}*/	
}

Map::~Map()
{
	for( int i = 0; i < mNumRow; i++ )
	{
		delete[] mMap[i];
	}
	delete[] mMap;
}

void Map::SetPaintZone( float x, float y, float w, float h )
{
	mXPos = x;
	mYPos = y;
	mWidth = w;
	mHeight = h;
}

void Map::PaintMap()
{	
	for( int i = 0; i < mNumRow; i++ )
	{
		for( int j = 0; j < mNumColumn; j++ )
		{
			if( i < ( mNumRow - 1 ) )
			{
				PaintBridge( i, j, i + 1, j );
			}

			if( j < ( mNumColumn - 1 ) )
			{
				PaintBridge( i, j, i, j + 1 );
			}
		}
	}
}

void Map::PaintBridge( int row1, int column1, int row2, int column2 )
{
	float column_width;
	float row_height;

	if( mNumColumn > 1 )
	{
		column_width = mWidth/( mNumColumn - 1 );
	}
	else
	{
		column_width = 0;
	}

	if( mNumRow > 1 )
	{
		row_height = mHeight/( mNumRow - 1 );
	}
	else
	{
		row_height = 0;
	}
	
	//battle to matrix
	int tmp_point_1 = row1*mNumColumn + column1;
	int tmp_point_2 = row2*mNumColumn + column2;	


	//if( ( mMap[row1][column2] == LINK ) && ( mMap[row2][column1] == LINK ) )//two way link
	if( ( mMap[tmp_point_1][tmp_point_2] == LINK ) && ( mMap[tmp_point_2][tmp_point_1] == LINK ) )//two way link
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_LINK
		);
	}
	//else if( ( mMap[row1][column2] == UNLINK ) && ( mMap[row2][column1] == UNLINK) )//unlink
	else if( ( mMap[tmp_point_1][tmp_point_2] == UNLINK ) && ( mMap[tmp_point_2][tmp_point_1] == UNLINK) )//unlink
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_UNLINK
		);
	}
	else//one way link
	{
		//if( mMap[row1][column2] == LINK )
		if( mMap[tmp_point_1][tmp_point_2] == LINK )
		{
			DrawLine
			(
				column1 * column_width + mXPos, row1 * row_height + mYPos,
				( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
				( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
				COLOR_LINK_START
			);
			DrawLine
			(
				( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
				( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
				column2 * column_width + mXPos, row2 * row_height + mYPos,
				COLOR_LINK_END
			);
		}
		else
		{
			DrawLine
			(
				column1 * column_width + mXPos, row1 * row_height + mYPos,
				( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
				( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
				COLOR_LINK_END
			);
			DrawLine
			(
				( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
				( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
				column2 * column_width + mXPos, row2 * row_height + mYPos,
				COLOR_LINK_START
			);
		}		
	}
}