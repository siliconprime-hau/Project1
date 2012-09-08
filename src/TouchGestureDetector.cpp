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



TouchGestureHolder gTouchGSList[NUM_POINTER_MAX];

namespace TouchGestureDetector
{
	void Update()
	{
		//reset proccessed touch
		for( int i = 0; i < NUM_POINTER_MAX; i++ )
		{
			if( gTouchGSList[i].mTouchGSType == TOUCH_UP )
			{
				gTouchGSList[i].Clear();
			}
		}

		for( int i = 0; i < gTouchQueueProgressing.size(); i++ )
		{
			TouchHolder touch = gPopTouch( gTouchQueueProgressing );
			if( touch.mTouchType == TOUCH_DOWN )//add new touch
			{
				for( int j = 0; j < NUM_POINTER_MAX; j++ )
				{
					if( gTouchGSList[j].mTouchGSType == TOUCH_INACTIVE )
					{
						gTouchGSList[j].mDownTime = gCurrentTimeMillis;

						gTouchGSList[j].mTouchGSId = touch.mTouchId;
						gTouchGSList[j].mTouchGSType = TOUCH_DOWN;
						gTouchGSList[j].mDownX = gTouchGSList[j].mCurrentX = touch.mTouchPosX;
						gTouchGSList[j].mDownY = gTouchGSList[j].mCurrentY = touch.mTouchPosY;
						break;
					}
				}
			}
			else//update exist touch
			{
				for( int j = 0; j < NUM_POINTER_MAX; j++ )
				{
					if( gTouchGSList[j].mTouchGSId == touch.mTouchId )
					{					
						if( touch.mTouchType == TOUCH_UP )
						{
							gTouchGSList[j].mUpTime = gCurrentTimeMillis;
						}

						gTouchGSList[j].mTouchGSType = touch.mTouchType;
						gTouchGSList[j].mUpX = gTouchGSList[j].mCurrentX = touch.mTouchPosX;
						gTouchGSList[j].mUpY = gTouchGSList[j].mCurrentY = touch.mTouchPosY;
						break;
					}
				}
			}
		}
	}

	bool isClick( float x, float y, float w, float h )
	{
		for( int i = 0; i < NUM_POINTER_MAX; i++ )
		{
			if(	gTouchGSList[i].mTouchGSType == TOUCH_UP &&
				( gTouchGSList[i].mUpTime - gTouchGSList[i].mDownTime ) <= TOUCH_CLICK_TIME )
			{
				if( is_down_inside( gTouchGSList[i], x, y, w, h ) && is_up_inside( gTouchGSList[i], x, y, w, h ) )
				{
					return true;
				}
			}
		}

		return false;
	}

	bool isPress( float x, float y, float w, float h )
	{
		for( int i = 0; i < NUM_POINTER_MAX; i++ )
		{
			if( ( gTouchGSList[i].mTouchGSType == TOUCH_DOWN ) || ( gTouchGSList[i].mTouchGSType == TOUCH_MOVE ) )
			{
				if( is_down_inside( gTouchGSList[i], x, y, w, h ) || is_current_inside( gTouchGSList[i], x, y, w, h ) )
				{
					return true;
				}
			}
		}

		return false;
	}

	int isFling( float x, float y, float w, float h )
	{
		for( int i = 0; i < NUM_POINTER_MAX; i++ )
		{
			if(	gTouchGSList[i].mTouchGSType == TOUCH_UP &&
				( gTouchGSList[i].mUpTime - gTouchGSList[i].mDownTime ) <= FLING_TIME )
			{
				if( is_down_inside( gTouchGSList[i], x, y, w, h ) &&
					( sqrt(	pow( gTouchGSList[i].mUpX - gTouchGSList[i].mDownX, 2 ) +
							pow( gTouchGSList[i].mUpY - gTouchGSList[i].mDownY, 2 ) ) >= FLING_RANGE ) )
				{
					float delta_x = gTouchGSList[i].mUpX - gTouchGSList[i].mDownX;
					float delta_y = gTouchGSList[i].mUpY - gTouchGSList[i].mDownY;

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
}