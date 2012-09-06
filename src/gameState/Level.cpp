#include "Level.h"

Level::Level()
{
}

Level::~Level()
{
	delete mBattle;
}

void Level::Init()
{
	mBattle = new Battle();
	mBattle->Init( 0, 0 );
}

void Level::Update()
{
	mBattle->Update();
}

void Level::Render()
{
	mBattle->Render();
}
