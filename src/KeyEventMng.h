#ifndef __KEYEVENTMNG__
#define __KEYEVENTMNG__

#include "Globals.h"

#define NUM_KEY_MAX	10

extern KeyHolder gKeyList[NUM_KEY_MAX];

namespace KeyEventMng
{
	void Update();
	int GetKeyAction( int keyCode );
}

#endif //__KEYEVENTMNG__
