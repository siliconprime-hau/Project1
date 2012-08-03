#ifndef __SPRITE__
#define __SPRITE__

#include "ImageCover.h"

struct Anim
{
	int mCurrentFrame;
	int mNumFrame;
	unsigned long mLastFrameTime;
	int mPaintedFrameCount;
	short* mAnim;

	Anim( short* anim );
	void ResetAnim();
};

/* idea of sprite structure

unsigned short modules[] =
{
	0, 0, 10, 20,//x, y, widht, height
	0, 0, 10, 20
};

short frame1[] =
{
	1,//nums count
	0, 10, 20//moduleId, x, y
};
short frame2[] =
{
	2,//nums count
	0, 10, 20,
	0, 10, 20
};
short* frames[] =
{
	frame1,
	frame2
};

short anim1_data[] =
{
	2,//nums count
	0, 10, 20, 100,//frameId, x, y, time milliseconds
	0, 10, 20, 100
};
short anim2_data[] =
{
	1,//nums count
	0, 10, 20, 100
};
Anim* anim1 = new Anim( anim1_data );
Anim* anim2 = new Anim( anim2_data );

Anim* anims[] =
{
	anim1,
	anim2
};

*/

class Sprite
{
private:
	unsigned short* mModules;
	short** mFrames;
	Anim** mAnims;
	ImageCover* mImageCover;

public:	
	Sprite( unsigned short* modules, short** frames, Anim** anims, ImageCover* imageCover );
	~Sprite();

	void PaintModule( int moduleId, int x, int y );
	void PaintFrame( int frameId, int x, int y );
	
	/*
	update anim by time
	the anim data will be like this
	short anim1_data[] =
	{
		2,//nums count
		0, 10, 20, 100,//frameId, x, y, time milliseconds
		0, 10, 20, 100
	};
	*/
	void PaintAnim( int animId, int x, int y, unsigned long currentTimeMillis );

	/*
	update anim by fps
	the anim data will be like this
	short anim1_data[] =
	{
		2,//nums count
		0, 10, 20, 3,//frameId, x, y, num frames to paint
		0, 10, 20, 1
	};
	*/
	void PaintAnim( int animId, int x, int y );
};

#endif //__SPRITE__