#include "TouchGestureDetector.h"
#include "Globals.h"
#include <math.h>



bool is_down_inside( TouchGestureHolder touch, float x, float y, float w, float h );
bool is_up_inside( TouchGestureHolder touch, float x, float y, float w, float h );
bool is_current_inside( TouchGestureHolder touch, float x, float y, float w, float h );

bool is_down_inside( TouchGestureHolder touch, float x, float y, float w, float h )
{
	if(	( touch.mDownX >= x ) && ( touch.mDownX <= ( x + w ) ) &&
		( touch.mDownY >= y ) && ( touch.mDownY <= ( y + h ) ) )
	{
		return true;
	}

	return false;
}

bool is_up_inside( TouchGestureHolder touch, float x, float y, float w, float h )
{
	if(	( touch.mUpX >= x ) && ( touch.mUpX <= ( x + w ) ) &&
		( touch.mUpY >= y ) && ( touch.mUpY <= ( y + h ) ) )
	{
		return true;
	}

	return false;
}

bool is_current_inside( TouchGestureHolder touch, float x, float y, float w, float h )
{
	if(	( touch.mCurrentX >= x ) && ( touch.mCurrentX <= ( x + w ) ) &&
		( touch.mCurrentY >= y ) && ( touch.mCurrentY <= ( y + h ) ) )
	{
		return true;
	}

	return false;
}




void TouchGestureDetector::Update()
{
	//reset proccessed touch
	for( int i = 0; i < NUM_POINTER_MAX; i++ )
	{
		if( mTouchGSList[i].mTouchGSType == TOUCH_UP )
		{
			mTouchGSList[i].Clear();
		}
	}

	for( int i = 0; i < gTouchQueueProgressing.size(); i++ )
	{
		TouchHolder touch = gPopTouch( gTouchQueueProgressing );
		if( touch.mTouchType == TOUCH_DOWN )//add new touch
		{
			for( int j = 0; j < NUM_POINTER_MAX; j++ )
			{
				if( mTouchGSList[j].mTouchGSType == TOUCH_INACTIVE )
				{
					mTouchGSList[j].mTouchGSId = touch.mTouchId;
					mTouchGSList[j].mTouchGSType = TOUCH_DOWN;
					mTouchGSList[j].mDownX = mTouchGSList[j].mCurrentX = touch.mTouchPosX;
					mTouchGSList[j].mDownY = mTouchGSList[j].mCurrentY = touch.mTouchPosY;
					break;
				}
			}
		}
		else//update exist touch
		{
			for( int j = 0; j < NUM_POINTER_MAX; j++ )
			{
				if( mTouchGSList[j].mTouchGSId == touch.mTouchId )
				{					
					mTouchGSList[j].mTouchGSType = touch.mTouchType;
					mTouchGSList[j].mUpX = mTouchGSList[j].mCurrentX = touch.mTouchPosX;
					mTouchGSList[j].mUpY = mTouchGSList[j].mCurrentY = touch.mTouchPosY;
					break;
				}
			}
		}
	}
}

bool TouchGestureDetector::isClick( float x, float y, float w, float h )
{
	for( int i = 0; i < NUM_POINTER_MAX; i++ )
	{
		if(	mTouchGSList[i].mTouchGSType == TOUCH_UP &&
			( mTouchGSList[i].mUpTime - mTouchGSList[i].mDownTime ) <= TOUCH_CLICK_TIME )
		{
			if( is_down_inside( mTouchGSList[i], x, y, w, h ) && is_up_inside( mTouchGSList[i], x, y, w, h ) )
			{
				return true;
			}
		}
	}

	return false;
}

bool TouchGestureDetector::isPress( float x, float y, float w, float h )
{
	for( int i = 0; i < NUM_POINTER_MAX; i++ )
	{
		if( ( mTouchGSList[i].mTouchGSType == TOUCH_DOWN ) || ( mTouchGSList[i].mTouchGSType == TOUCH_MOVE ) )
		{
			if( is_down_inside( mTouchGSList[i], x, y, w, h ) || is_current_inside( mTouchGSList[i], x, y, w, h ) )
			{
				return true;
			}
		}
	}

	return false;
}

int TouchGestureDetector::isFling( float x, float y, float w, float h )
{
	for( int i = 0; i < NUM_POINTER_MAX; i++ )
	{
		if(	mTouchGSList[i].mTouchGSType == TOUCH_UP &&
			( mTouchGSList[i].mUpTime - mTouchGSList[i].mDownTime ) <= FLING_TIME )
		{
			if( is_down_inside( mTouchGSList[i], x, y, w, h ) &&
				( sqrt(	pow( mTouchGSList[i].mUpX - mTouchGSList[i].mDownX, 2 ) +
						pow( mTouchGSList[i].mUpY - mTouchGSList[i].mDownY, 2 ) ) >= FLING_RANGE ) )
			{
				float delta_x = mTouchGSList[i].mUpX - mTouchGSList[i].mDownX;
				float delta_y = mTouchGSList[i].mUpY - mTouchGSList[i].mDownY;

				if( fabs( delta_x ) > fabs( delta_y ) )//left/right
				{
					if( delta_x > 0 )
					{
						return FLING_RIGHT;
					}
					else
					{
						return FLING_LEFT;
					}
				}
				else//up/down
				{
					if( delta_y > 0 )
					{
						return FLING_DOWN;
					}
					else
					{
						return FLING_UP;
					}
				}												
			}
		}
	}

	return FLING_NONE;
}