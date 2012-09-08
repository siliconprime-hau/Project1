#include "Sprite.h"

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
	PaintModuleA( moduleId, x, y, ANCHOR_LEFT, ANCHOR_TOP );
}

void Sprite::PaintModuleA( int moduleId, int x, int y, int anchor_h, int anchor_v )
{	
	mImageCover->PaintA( x, y, mModules[moduleId*4], mModules[moduleId*4 + 1], mModules[moduleId*4 +2], mModules[moduleId*4 + 3], anchor_h, anchor_v );
}

void Sprite::PaintFrame( int frameId, int x, int y )
{
	PaintFrameA( frameId, x, y, ANCHOR_LEFT, ANCHOR_TOP );
}

void Sprite::PaintFrameA( int frameId, int x, int y, int anchor_h, int anchor_v )
{
	short* frame = mFrames[frameId];

	for( int i = 0; i < frame[0]; i ++ )
	{
		PaintModuleA( frame[i*3 + 1], frame[i*3 + 2] + x, frame[i*3 + 3] + y, anchor_h, anchor_v );
	}
}

void Sprite::PaintAnimByTime( int animId, int x, int y, unsigned long currentTimeMillis )
{
	PaintAnimAByTime( animId, x, y, currentTimeMillis, ANCHOR_LEFT, ANCHOR_TOP );
}

void Sprite::PaintAnimAByTime( int animId, int x, int y, unsigned long currentTimeMillis, int anchor_h, int anchor_v )
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
		/* one frame per step
		if( ( currentTimeMillis - anim->mLastFrameTime ) > anim_data[anim->mCurrentFrame * 4 + 4] )
		{
			anim->mCurrentFrame++;
			anim->mLastFrameTime = currentTimeMillis;
		}
		*/

		if( ( currentTimeMillis - anim->mLastFrameTime ) > anim_data[anim->mCurrentFrame * 4 + 4] )
		{
			int num_frame_to_skip = 1;
			int tmp_current_frame = anim->mCurrentFrame;
			unsigned long frame_time_sum = anim_data[tmp_current_frame * 4 + 4];
			while( ( frame_time_sum + anim_data[((tmp_current_frame+1)%anim->mNumFrame) * 4 + 4] ) < ( currentTimeMillis - anim->mLastFrameTime ) )
			{
				frame_time_sum += anim_data[(tmp_current_frame+1) * 4 + 4];
				num_frame_to_skip++;				
				tmp_current_frame = (tmp_current_frame+1)%anim->mNumFrame;
			}
			
			anim->mCurrentFrame += num_frame_to_skip;			
			anim->mLastFrameTime = currentTimeMillis - ( currentTimeMillis - anim->mLastFrameTime ) + frame_time_sum;
		}
	}
		
	anim->mCurrentFrame = anim->mCurrentFrame%anim->mNumFrame;

	PaintFrameA( anim_data[anim->mCurrentFrame * 4 + 1], anim_data[anim->mCurrentFrame * 4 + 2] + x,  anim_data[anim->mCurrentFrame * 4 + 3] + y, anchor_h, anchor_v );
}

void Sprite::PaintAnim( int animId, int x, int y )
{
	PaintAnimA( animId, x, y, ANCHOR_LEFT, ANCHOR_TOP );
}

void Sprite::PaintAnimA( int animId, int x, int y, int anchor_h, int anchor_v )
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

	PaintFrameA( anim_data[anim->mCurrentFrame * 4 + 1], anim_data[anim->mCurrentFrame * 4 + 2] + x,  anim_data[anim->mCurrentFrame * 4 + 3] + y, anchor_h, anchor_v );
}
