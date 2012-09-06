#ifndef __MAP__
#define __MAP__

#define UNLINK			0
#define LINK			1

#define COLOR_LINK			0x00FF00FF
#define COLOR_UNLINK		0xFF0000FF
#define COLOR_LINK_START	0x00FF00FF
#define COLOR_LINK_END		0xFF0000FF

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

private:
	int mNumRow, mNumColumn;
	float mXPos, mYPos, mWidth, mHeight; 

	unsigned char** mMap;
	void PaintBridge( int row1, int column1, int row2, int column2 );
};

#endif //__MAP__