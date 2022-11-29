//Tobias Godoy / Moon Patrol
#include "objects/game.h"

int main()
{
	Game* game = new Game();

	game->runGame();

	delete game;

	return 0;
}