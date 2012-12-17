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
			mMap[i][j] = UNBRIDGE;
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

void Map::SetRoad( int row1, int column1, int row2, int column2, int roadType )
{
	int row = RCToEdge( row1, column1 );
	int column = RCToEdge( row2, column2 );
	mMap[row][column] = roadType;
}

void Map::SetBridge( int row1, int column1, int row2, int column2, int bridgeType )
{
	if( bridgeType == TWO_WAY_ALWAYS_ON )
	{
		SetRoad( row1, column1, row2, column2, ROAD_ON );
		SetRoad( row2, column2, row1, column1, ROAD_ON );
	}
	else if( bridgeType == TWO_WAY_ONE_TIME )
	{
		SetRoad( row1, column1, row2, column2, ROAD_ONE_TIME );
		SetRoad( row2, column2, row1, column1, ROAD_ONE_TIME );
	}
	else if( ( bridgeType == TWO_WAY_ONOFF_ON ) || ( bridgeType == TWO_WAY_ONOFF_OFF ) )
	{
		if( bridgeType == TWO_WAY_ONOFF_ON )
		{
			SetRoad( row1, column1, row2, column2, ROAD_ONOFF_ON );
			SetRoad( row2, column2, row1, column1, ROAD_ONOFF_ON );
		}
		else//( bridgeType == TWO_WAY_ONOFF_OFF )
		{
			SetRoad( row1, column1, row2, column2, ROAD_ONOFF_OFF );
			SetRoad( row2, column2, row1, column1, ROAD_ONOFF_OFF );
		}
	}
	else if( bridgeType == ONE_WAY_ALWAYS_ON )
	{
		SetRoad( row1, column1, row2, column2, ROAD_ON );
		SetRoad( row2, column2, row1, column1, ROAD_OFF );
	}
	else if( bridgeType == ONE_WAY_ONE_TIME )
	{
		SetRoad( row1, column1, row2, column2, ROAD_ONE_TIME );
		SetRoad( row2, column2, row1, column1, ROAD_OFF );
	}
	else if( ( bridgeType == ONE_WAY_ONOFF_ON ) || ( bridgeType == ONE_WAY_ONOFF_OFF ) )
	{
		if( bridgeType == ONE_WAY_ONOFF_ON )
		{
			SetRoad( row1, column1, row2, column2, ROAD_ONOFF_ON );
			SetRoad( row2, column2, row1, column1, ROAD_OFF );
		}
		else//( bridgeType == ONE_WAY_ONOFF_OFF )
		{
			SetRoad( row1, column1, row2, column2, ROAD_ONOFF_OFF );
			SetRoad( row2, column2, row1, column1, ROAD_OFF );
		}
	}
	else if( bridgeType == UNBRIDGE )
	{
		SetRoad( row1, column1, row2, column2, ROAD_OFF );
		SetRoad( row2, column2, row1, column1, ROAD_OFF );
	}
}

int Map::GetRoad( int row1, int column1, int row2, int column2 )
{
	int row = RCToEdge( row1, column1 );
	int column = RCToEdge( row2, column2 );
	return mMap[row][column];
}

int Map::GetBridge( int row1, int column1, int row2, int column2 )
{
	int road12 = GetRoad( row1, column1, row2, column2 );
	int road21 = GetRoad( row2, column2, row1, column1 );

	if( road12 == ROAD_OFF && road21 == ROAD_OFF )
	{
		return UNBRIDGE;
	}
	else if( road12 == ROAD_ON && road21 == ROAD_ON )
	{
		return TWO_WAY_ALWAYS_ON;
	}
	else if( road12 == ROAD_ON && road21 == ROAD_OFF )
	{
		return ONE_WAY_ALWAYS_ON;
	}
	else if( road12 == ROAD_ONE_TIME && road21 == ROAD_ONE_TIME )
	{
		return TWO_WAY_ONE_TIME;
	}
	else if( road12 == ROAD_ONE_TIME && road21 == ROAD_OFF )
	{
		return ONE_WAY_ONE_TIME;
	}
	else if( road12 == ROAD_ONOFF_ON && road21 == ROAD_ONOFF_ON )
	{
		return TWO_WAY_ONOFF_ON;
	}
	else if( road12 == ROAD_ONOFF_OFF && road21 == ROAD_ONOFF_OFF )
	{
		return TWO_WAY_ONOFF_OFF;
	}
	else if( road12 == ROAD_ONOFF_ON && road21 == ROAD_OFF )
	{
		return ONE_WAY_ONOFF_ON;
	}
	else if( road12 == ROAD_ONOFF_OFF && road21 == ROAD_OFF )
	{
		return ONE_WAY_ONOFF_OFF;
	}

	return UNBRIDGE;
}

bool Map::isCanMove( int row1, int column1, int row2, int column2 )
{
	int current_type = GetRoad( row1, column1, row2, column2 );

	return !( current_type == ROAD_OFF || current_type == ROAD_ONOFF_OFF );
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

	int bridge12 = GetBridge( row1, column1, row2, column2 );
	int bridge21 = GetBridge( row2, column2, row1, column1 );

	if( bridge12 == UNBRIDGE )
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_UNLINK
		);
	}
	else if( bridge12 == TWO_WAY_ALWAYS_ON )
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_LINK
		);
	}
	else if( bridge12 == ONE_WAY_ALWAYS_ON )
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
			( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
			COLOR_LINK
		);
		DrawLine
		(
			( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
			( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_UNLINK
		);
	}
	else if( bridge12 == TWO_WAY_ONE_TIME )
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_LINK_ONE_TIME
		);
	}
	else if( bridge12 == ONE_WAY_ONE_TIME )
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
			( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
			COLOR_LINK_ONE_TIME
		);
		DrawLine
		(
			( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
			( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_UNLINK
		);
	}
	else if( bridge12 == TWO_WAY_ONOFF_ON )
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_LINK_ONOFF_ON
		);
	}
	else if( bridge12 == TWO_WAY_ONOFF_OFF )
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_LINK_ONOFF_OFF
		);
	}
	else if( bridge12 == ONE_WAY_ONOFF_ON )
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
			( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
			COLOR_LINK_ONOFF_ON
		);
		DrawLine
		(
			( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
			( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_UNLINK
		);
	}
	else if( bridge12 == ONE_WAY_ONOFF_OFF )
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
			( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
			COLOR_LINK_ONOFF_OFF
		);
		DrawLine
		(
			( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
			( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_UNLINK
		);
	}
	//--------------------------------------
	else if( bridge21 == ONE_WAY_ALWAYS_ON )
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
			( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
			COLOR_UNLINK
		);
		DrawLine
		(
			( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
			( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_LINK
		);
	}
	else if( bridge21 == ONE_WAY_ONE_TIME )
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
			( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
			COLOR_UNLINK
		);
		DrawLine
		(
			( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
			( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_LINK_ONE_TIME
		);
	}
	else if( bridge21 == ONE_WAY_ONOFF_ON )
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
			( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
			COLOR_UNLINK
		);
		DrawLine
		(
			( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
			( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_LINK_ONOFF_ON
		);
	}
	else if( bridge21 == ONE_WAY_ONOFF_OFF )
	{
		DrawLine
		(
			column1 * column_width + mXPos, row1 * row_height + mYPos,
			( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
			( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
			COLOR_UNLINK
		);
		DrawLine
		(
			( ( column2 * column_width + mXPos ) + ( column1 * column_width + mXPos ) ) / 2,
			( ( row2 * row_height + mYPos ) + ( row1 * row_height + mYPos ) ) / 2,
			column2 * column_width + mXPos, row2 * row_height + mYPos,
			COLOR_LINK_ONOFF_OFF
		);
	}
}
