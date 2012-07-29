#ifndef __SPLASH__
#define __SPLASH__

#include "GameState.h"

class Splash: public GameState
{
public:
	Splash();
	~Splash();

	void Render();
};

#endif //__SPLASH__