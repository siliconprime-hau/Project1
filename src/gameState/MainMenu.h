#ifndef __MAINMENU__
#define __MAINMENU__

#include "GameState.h"

class MainMenu: public GameState
{
public:
	MainMenu();
	~MainMenu();

	void Render();
};

#endif //__MAINMENU__