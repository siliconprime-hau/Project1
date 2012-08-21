#ifndef __LEVEL__
#define __LEVEL__

#include "Battle.h"

class Level
{
public:
	Level();
	~Level();
	void Init();
	void Render();
	void Update( unsigned long timeMillis );

private:
	Battle* mBattle;
};

#endif //__LEVEL__