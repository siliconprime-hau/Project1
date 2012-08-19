#include "Anim.h"

Anim::Anim( short* anim )
{
	mAnim = anim;
	mNumFrame = mAnim[0];
	mCurrentFrame = 0;
	mLastFrameTime = 0;
	mPaintedFrameCount = 0;
}

void Anim::ResetAnim()
{
	mCurrentFrame = 0;
	mLastFrameTime = 0;
	mPaintedFrameCount = 0;
}
