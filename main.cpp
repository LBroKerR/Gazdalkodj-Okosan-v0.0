#include <stdexcept>
#include <unordered_map>
#include <malloc.h>
#include <string>
#include<iostream>

using namespace std;
#include "Players.h"
#include "Game.h"

#define ID 6

int main()
{
	Players *players=new Players(ID);
	Game *game=new Game();
	game->init(players);
	while (game->menu(players));
	delete players;
	delete game;
	_CrtDumpMemoryLeaks();
	return 0;
}


