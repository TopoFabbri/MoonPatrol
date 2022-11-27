//Tobias Godoy / Moon Patrol
#include "objects/game.h"

int main()
{
	InitWindow(1024, 768, "Moon Patrol v0.3");
	SetWindowState(FLAG_VSYNC_HINT);

	Game* game = new Game();

	game->runGame();

	delete game;

	return 0;
}