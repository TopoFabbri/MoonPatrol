//Tobias Godoy / Moon Patrol
#include "objects/game.h"

using namespace Topo;

int main()
{
	Game* game = new Game();

	game->runGame();

	delete game;

	return 0;
}