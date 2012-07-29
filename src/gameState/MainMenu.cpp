#include "MainMenu.h"
#include "Geometry.h"
#include "Globals.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Render()
{
	DrawRect( gScreenWidth/2 - gScreenWidth*0.1, gScreenHeight/2 - gScreenHeight*0.1, gScreenWidth*0.2, gScreenHeight*0.2, 0xffff00ff ); 
}