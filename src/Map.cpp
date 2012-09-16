#include "Map.h"
#include "l2d.h"

//raw init
#include "Globals.h"

	//int X = LINK;
	//int Y = UNLINK;
	//
	//unsigned char tmp[24][24] =//4 row/6 column
	//{
	//	/*0*/	{	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
	//	/*1*/	{	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
	//	/*2*/	{	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
	//	/*3*/	{	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
	//	/*4*/	{	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
	//	/*5*/	{	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
	//	/*6*/	{	X,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
	//	/*7*/	{	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
	//	/*8*/	{	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0,	0 },
	//	/*9*/	{	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0,	0 },
	//	/*10*/	{	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	0 },
	//	/*11*/	{	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0 },
	//	/*12*/	{	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0 },
	//	/*13*/	{	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0 },
	//	/*14*/	{	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0 },
	//	/*15*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0,	0 },
	//	/*16*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0,	0,	X,	0 },
	//	/*17*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	X },
	//	/*18*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0 },
	//	/*19*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0,	0 },
	//	/*20*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0,	0 },
	//	/*21*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X,	0 },
	//	/*22*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0,	X },
	//	/*23*/	{	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	X,	0,	0,	0,	0,	X,	0 }
	//};


Map::Map( int numRow, int numColumn )
{
	mNumRow = numRow;
	mNumColumn = numColumn;

	int tmp_row_column = mNumRow * mNumColumn;
	mMap = new unsigned char*[tmp_row_column];

	for( int i = 0; i < tmp_row_column; i++ )
	{
		mMap[i] = new unsigned char[tmp_row_column];
	}
	for( int i = 0; i < tmp_row_column; i++ )
	{
		for( int j = 0; j < tmp_row_column; j++ )
		{						
			mMap[i][j] = BRIDGE_TYPE::UNBRIDGE;			
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

int Map::RCToEdge( int row, int column )
{
	return mNumColumn*row + column;
}

int* Map::EdgeToRC( int edge )
{
	int tmp[2];

	tmp[0] = edge/mNumColumn;
	tmp[1] = edge%mNumColumn;

	return tmp;
}

void Map::SetBridge( int row1, int column1, int row2, int column2, int bridgeType )
{
	int row = RCToEdge( row1, column1 );
	int column = RCToEdge( row2, column2 );
	mMap[row][column] = bridgeType;
}

void Map::SetBridgeBoth( int row1, int column1, int row2, int column2, int bridgeType )
{
	if( bridgeType == BRIDGE_TYPE::TWO_WAY_ALWAYS_ON )
	{
		SetBridge( row1, column1, row2, column2, BRIDGE_TYPE::TWO_WAY_ALWAYS_ON );
		SetBridge( row2, column2, row1, column1, BRIDGE_TYPE::TWO_WAY_ALWAYS_ON );
	}
	else if( bridgeType == BRIDGE_TYPE::TWO_WAY_ONE_TIME )
	{
		SetBridge( row1, column1, row2, column2, BRIDGE_TYPE::TWO_WAY_ONE_TIME );
		SetBridge( row2, column2, row1, column1, BRIDGE_TYPE::TWO_WAY_ONE_TIME );
	}
	else if( ( bridgeType == BRIDGE_TYPE::TWO_WAY_ONOFF_ON ) || ( bridgeType == BRIDGE_TYPE::TWO_WAY_ONOFF_OFF ) )
	{
		SetBridge( row1, column1, row2, column2, bridgeType );
		SetBridge( row2, column2, row1, column1, bridgeType );
	}
	else if( bridgeType == BRIDGE_TYPE::ONE_WAY_ALWAYS_ON )
	{
		SetBridge( row1, column1, row2, column2, BRIDGE_TYPE::ONE_WAY_ALWAYS_ON );
		SetBridge( row2, column2, row1, column1, BRIDGE_TYPE::UNBRIDGE );
	}
	else if( bridgeType == BRIDGE_TYPE::ONE_WAY_ONE_TIME )
	{
		SetBridge( row1, column1, row2, column2, BRIDGE_TYPE::ONE_WAY_ONE_TIME );
		SetBridge( row2, column2, row1, column1, BRIDGE_TYPE::UNBRIDGE );
	}
	else if( ( bridgeType == BRIDGE_TYPE::ONE_WAY_ONOFF_ON ) || ( bridgeType == BRIDGE_TYPE::ONE_WAY_ONOFF_OFF ) )
	{
		SetBridge( row1, column1, row2, column2, bridgeType );
		SetBridge( row2, column2, row1, column1, BRIDGE_TYPE::UNBRIDGE );
	}
	else if( bridgeType == BRIDGE_TYPE::UNBRIDGE )
	{
		SetBridge( row1, column1, row2, column2, BRIDGE_TYPE::UNBRIDGE );
		SetBridge( row2, column2, row1, column1, BRIDGE_TYPE::UNBRIDGE );
	}
}

int Map::GetBridge( int row1, int column1, int row2, int column2 )
{
	int row = RCToEdge( row1, column1 );
	int column = RCToEdge( row2, column2 );
	return mMap[row][column];
}

bool Map::isCanMove( int row1, int column1, int row2, int column2 )
{
	int current_type = GetBridge( row1, column1, row2, column2 );

	return !(	current_type == BRIDGE_TYPE::UNBRIDGE ||
				current_type == BRIDGE_TYPE::TWO_WAY_ONOFF_OFF ||
				current_type == BRIDGE_TYPE::ONE_WAY_ONOFF_OFF
			);
}

float Map::RowToY( int row )
{
	return mYPos + mHeight/(mNumRow-1)*row;
}

float Map::ColumnToX( int column )
{
	return mXPos + mWidth/(mNumColumn-1)*column;
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


	if( ( mMap[tmp_point_1][tmp_point_2] != BRIDGE_TYPE::UNBRIDGE ) && ( mMap[tmp_point_2][tmp_point_1] != BRIDGE_TYPE::UNBRIDGE ) )//two way link
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_LINK
		);
	}
	else if( ( mMap[tmp_point_1][tmp_point_2] == BRIDGE_TYPE::UNBRIDGE ) && ( mMap[tmp_point_2][tmp_point_1] == BRIDGE_TYPE::UNBRIDGE) )//unlink
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
		if( mMap[tmp_point_1][tmp_point_2] != BRIDGE_TYPE::UNBRIDGE )
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