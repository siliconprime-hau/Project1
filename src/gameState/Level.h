#ifndef __LEVEL__
#define __LEVEL__

#include "Battle.h"
#include "GameState.h"



#define LEVEL_MENU_PANEL_WIDTH	0.3f//30% of screen height
#define LEVEL_MAP_PADDING		0.05f//5% of screen height




class Level: public GameState
{
public:
	Level();
	~Level();
	void Init();
	void Update();
	void Render();

private:
	Battle* mBattle;
};

#endif //__LEVEL__
