#ifndef __TOUCHGESTUREDETECTOR__
#define __TOUCHGESTUREDETECTOR__

#define TOUCH_INACTIVE		-1
#define TOUCH_CLICK_TIME	100//milli second

struct TouchGestureHolder
{
	int mTouchGSId, mTouchGSType;
	unsigned long mDownTime, mUpTime;
	float mDownX, mDownY, mCurrentX, mCurrentY, mUpX, mUpY;
	
	TouchGestureHolder()
	{
		mTouchGSId = mTouchGSType = TOUCH_INACTIVE;
		mDownTime = mUpTime = TOUCH_INACTIVE;
		mDownX = mDownY = mCurrentX = mCurrentY = mUpX = mUpY = TOUCH_INACTIVE;
	}

	void Clear()
	{
		TouchGestureHolder();
	}
};




#define NUM_POINTER_MAX		10

#define FLING_RANGE			100//pixel
#define FLING_TIME			100//milli second

enum FLING_TYPE
{
	FLING_NONE = 0,
	FLING_UP,
	FLING_DOWN,
	FLING_LEFT,
	FLING_RIGHT
};

class TouchGestureDetector
{
private:
	TouchGestureHolder mTouchGSList[NUM_POINTER_MAX];

public:
	void Update();
	bool isClick( float x, float y, float w, float h );
	bool isPress( float x, float y, float w, float h );
	int isFling( float x, float y, float w, float h );
};

#endif //__TOUCHGESTUREDETECTOR__