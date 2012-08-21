#include "Level.h"

Level::Level()
{
}

Level::~Level()
{
}

void Level::Init()
{
	mBattle = new Battle();
	mBattle->Init( 0, 0 );
}

void Level::Render()
{
	mBattle->Render();
}

void Level::Update( unsigned long timeMillis )
{
}