#include "KeyEventMng.h"




KeyHolder gKeyList[NUM_KEY_MAX];

namespace KeyEventMng
{
	void Update()
	{
		//reset processed key
		for( int i = 0; i < NUM_KEY_MAX; i++ )
		{
			if( gKeyList[i].mKeyType == KEY_UP )
			{
				gKeyList[i].Clear();
			}
		}

		for( int i = 0; i < gKeyQueueProgressing.size(); i++ )
		{
			KeyHolder key = gPopKey( gKeyQueueProgressing );
			if( key.mKeyType == KEY_DOWN )//add new key
			{
				for( int j = 0; j < NUM_KEY_MAX; j++ )
				{
					if( gKeyList[j].mKeyType == KEY_INACTIVE )
					{
						gKeyList[j].mKeyCode = key.mKeyCode;
						gKeyList[j].mKeyType = KEY_DOWN;
						break;
					}
				}
			}
			else//update exist key
			{
				for( int j = 0; j < NUM_KEY_MAX; j++ )
				{
					if( gKeyList[j].mKeyCode == key.mKeyCode )
					{					
						gKeyList[j].mKeyType = key.mKeyType;
						break;
					}
				}
			}
		}
	}

	int GetKeyAction( int keyCode )
	{
		for( int i = 0; i < NUM_KEY_MAX; i++ )
		{
			if( gKeyList[i].mKeyCode == keyCode )
			{
				return gKeyList[i].mKeyType;
			}
		}
		
		return KEY_INACTIVE;
	}
}
