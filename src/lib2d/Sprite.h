#ifndef __SPRITE__
#define __SPRITE__

#include "ImageCover.h"

struct Anim
{
	int mCurrentFrame;
	int mNumFrame;
	unsigned long mLastFrameTime;
	short* mAnim;

	Anim( short* anim );
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
	0, 10, 20, 100,//moduleId( but going to frameId ), x, y, time milliseconds
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
	void PaintAnim( int animId, int x, int y, unsigned long currentTimeMillis );
};

#endif //__SPRITE__