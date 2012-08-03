#include "Sprite.h"

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


Sprite::Sprite( unsigned short* modules, short** frames, Anim** anims, ImageCover* imageCover )
{
	mModules = modules;
	mFrames = frames;
	mAnims = anims;
	mImageCover = imageCover;
}

Sprite::~Sprite()
{
}

void Sprite::PaintModule( int moduleId, int x, int y )
{	
	mImageCover->Paint( x, y, mModules[moduleId*4], mModules[moduleId*4 + 1], mModules[moduleId*4 +2], mModules[moduleId*4 + 3] );
}

void Sprite::PaintFrame( int frameId, int x, int y )
{
	short* frame = mFrames[frameId];

	for( int i = 0; i < frame[0]; i ++ )
	{
		PaintModule( frame[i*3 + 1], frame[i*3 + 2] + x, frame[i*3 + 3] + y );
	}
}

void Sprite::PaintAnim( int animId, int x, int y, unsigned long currentTimeMillis )
{
	Anim* anim = mAnims[animId];
	short* anim_data = anim->mAnim;

	if( anim->mLastFrameTime == 0 )
	{
		anim->mCurrentFrame = 0;		
		anim->mLastFrameTime = currentTimeMillis;
	}
	else
	{		
		if( ( currentTimeMillis - anim->mLastFrameTime ) > anim_data[anim->mCurrentFrame * 4 + 4] )
		{
			anim->mCurrentFrame++;
			anim->mLastFrameTime = currentTimeMillis;
		}
	}
		
	anim->mCurrentFrame = anim->mCurrentFrame%anim->mNumFrame;

	PaintFrame( anim_data[anim->mCurrentFrame * 4 + 1], anim_data[anim->mCurrentFrame * 4 + 2] + x,  anim_data[anim->mCurrentFrame * 4 + 3] + y );
}

void Sprite::PaintAnim( int animId, int x, int y )
{
	Anim* anim = mAnims[animId];
	short* anim_data = anim->mAnim;
		
	if( anim->mPaintedFrameCount >= anim_data[anim->mCurrentFrame * 4 + 4] )
	{
		anim->mCurrentFrame++;
		anim->mPaintedFrameCount = 0;
	}
	
	anim->mPaintedFrameCount++;
	anim->mCurrentFrame = anim->mCurrentFrame%anim->mNumFrame;

	PaintFrame( anim_data[anim->mCurrentFrame * 4 + 1], anim_data[anim->mCurrentFrame * 4 + 2] + x,  anim_data[anim->mCurrentFrame * 4 + 3] + y );
}
