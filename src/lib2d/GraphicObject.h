#ifndef __GRAPHICOBJECT__
#define __GRAPHICOBJECT__

//base class provide ability to handler touch event

class GraphicObject
{
protected:
	int mVisiblePosX, mVisiblePosY, mVisibleWidth, mVisibleHeight;

public:
	GraphicObject();
	~GraphicObject();

	bool IsInside( int x, int y );//check if (x,y) is inside this object
};

#endif //__GRAPHICOBJECT__