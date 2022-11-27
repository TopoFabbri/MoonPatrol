#include "game.h"

#include "Credits.h"

Game::Game()
{
	mMenu = new MainMenu();
	gSettings = new GameSettings();
	gameSession = new GameSession(gSettings);
	creds = new Credits();
}

Game::~Game()
{
	delete gameSession;
	delete mMenu;
}

void Game::runGame()
{
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

		default:;
		}
	}
}