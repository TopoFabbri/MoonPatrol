#include "game.h"

#include "Credits.h"

Game::Game()
{
}

Game::~Game()
{
	delete gameSession;
	delete mMenu;
}

void Game::runGame()
{
	InitWindow(1024, 768, "Moon Patrol");
	SetWindowState(FLAG_VSYNC_HINT);

	mMenu = new MainMenu();
	gSettings = new GameSettings();
	gameSession = new GameSession(gSettings);
	creds = new Credits();
	controls = new Controls();


	while (!WindowShouldClose())
	{
		switch (gSettings->curScene)
		{
		case GameSettings::Menu:
			mMenu->run(gSettings);
			break;

		case GameSettings::Gameplay:
			gameSession->play(gSettings);
			break;

		case GameSettings::Credits:
			creds->run(gSettings);
			break;

		case GameSettings::Controls:
			controls->run(gSettings);
			break;

		default:;
		}
	}

	CloseWindow();
}