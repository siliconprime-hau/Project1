#ifndef __GAMESTATE__
#define __GAMESTATE__

class GameState
{
public:	
	GameState();
	virtual ~GameState();

	virtual void Init();
	virtual void Update();
	virtual void Render();
};

#endif //__GAMESTATE__