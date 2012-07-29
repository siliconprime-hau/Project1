#ifndef __GAMESTATE__
#define __GAMESTATE__

class GameState
{
public:	
	GameState();
	virtual ~GameState();

	virtual void Init();
	virtual void Update( unsigned long currentTime );
	virtual void Render();
	virtual void OnTouchEvent( int touchId, int touchType, int x, int y );
};

#endif //__GAMESTATE__