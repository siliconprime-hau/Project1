#ifndef __MAP__
#define __MAP__

#define UNLINK			0
#define LINK			1

#define COLOR_LINK			0x00FF00FF
#define COLOR_UNLINK		0xFF0000FF
#define COLOR_LINK_START	0x00FF00FF
#define COLOR_LINK_END		0xFF0000FF


enum BRIDGE_TYPE
{
	UNBRIDGE = 0,
	TWO_WAY_ALWAYS_ON,
	ONE_WAY_ALWAYS_ON,
	TWO_WAY_ONE_TIME,
	ONE_WAY_ONE_TIME,
	TWO_WAY_ONOFF_ON,
	TWO_WAY_ONOFF_OFF,
	ONE_WAY_ONOFF_ON,
	ONE_WAY_ONOFF_OFF
};


class Map
{
public:
	Map( int numRow, int numColumn );
	~Map();

	void SetPaintZone( float x, float y, float w, float h );
	void PaintMap();
	float RowToY( int row );
	float ColumnToX( int column );
	int GetNumRow(){ return mNumRow; }
	int GetNumColumn(){ return mNumColumn; }

	//only for direction row1,column1 -> row2,column2
	void SetBridge( int row1, int column1, int row2, int column2, int bridgeType );	

	//for both direction row1,column1 <-> row2,column2
	void SetBridgeBoth( int row1, int column1, int row2, int column2, int bridgeType );

	//return the bridgeType
	int GetBridge( int row1, int column1, int row2, int column2 );
	//check if can move from row1,column1 -> row2,column2
	bool isCanMove( int row1, int column1, int row2, int column2 );

private:
	int mNumRow, mNumColumn;
	float mXPos, mYPos, mWidth, mHeight; 

	unsigned char** mMap;
	void PaintBridge( int row1, int column1, int row2, int column2 );

	int RCToEdge( int row, int column );
	int* EdgeToRC( int edge );//return an int[2] with [0] is row and [1] is column
};

#endif //__MAP__