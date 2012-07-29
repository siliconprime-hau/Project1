#ifndef __IMAGECOVER__
#define __IMAGECOVER__

//class that cover an image as a texture

#include <GLES2/gl2.h>
#include "GraphicObject.h"

enum ANCHOR
{
	ANCHOR_CENTER = 0,
	ANCHOR_TOP,
	ANCHOR_BOTTOM,
	ANCHOR_LEFT,
	ANCHOR_RIGHT
};

class ImageCover: public GraphicObject
{
private:
	GLuint mTexID;	
	unsigned int mWidth, mHeight;

public:
	ImageCover( const char* fileName );
	~ImageCover();		

	void PaintA
		(
			float scr_x, float scr_y, float scr_w, float scr_h,
			float img_x, float img_y, float img_w, float img_h,
			int anchor_h, int anchor_v
		);	
	void PaintA( float scr_x, float scr_y, int anchor_h, int anchor_v );		
	void PaintA( float scr_x, float scr_y, float img_x, float img_y, float img_w, float img_h, int anchor_h, int anchor_v );
	void PaintA( float scr_x, float scr_y, float scr_w, float scr_h, int anchor_h, int anchor_v );
	
	//----------//		
	void Paint( float scr_x, float scr_y );
	void Paint( float scr_x, float scr_y, float img_x, float img_y, float img_w, float img_h );
	void Paint( float scr_x, float scr_y, float scr_w, float scr_h );
	void Paint
		(
			float scr_x, float scr_y, float scr_w, float scr_h,
			float img_x, float img_y, float img_w, float img_h			
		);
};

#endif //__IMAGECOVER__