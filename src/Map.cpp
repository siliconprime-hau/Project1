#include "Map.h"
#include "Geometry.h"

Map::Map( int numRow, int numColumn )
{
	mNumRow = numRow;
	mNumColumn = numColumn;

	mMap = new unsigned char*[mNumRow];
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
	}
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

	if( ( mMap[row1][column2] == LINK ) && ( mMap[row2][column1] == LINK ) )//two way link
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_LINK
		);
	}
	else if( ( mMap[row1][column2] == UNLINK ) && ( mMap[row2][column1] == UNLINK) )//unlink
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
		if( mMap[row1][column2] == LINK )
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