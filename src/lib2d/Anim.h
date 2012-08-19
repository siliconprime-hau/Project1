#ifndef __ANIM__
#define __ANIM__

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

#endif //__ANIM__