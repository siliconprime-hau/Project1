#include "GraphicObject.h"

GraphicObject::GraphicObject()
{
	mVisiblePosX = -1;
	mVisiblePosY = -1;
	mVisibleWidth = -1;
	mVisibleHeight = -1;
}

GraphicObject::~GraphicObject()
{
}

bool GraphicObject::IsInside( int x, int y )
{
	if
	(
		( x >= mVisiblePosX ) && ( x <= ( mVisiblePosX + mVisibleWidth ) )
		&& ( y >= mVisiblePosY ) && ( y <= ( mVisiblePosY + mVisibleHeight ) )
	)
	{
		return true;
	}

	return false;
}