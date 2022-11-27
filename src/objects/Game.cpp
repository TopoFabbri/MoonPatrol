#include "game.h"

Game::Game()
{
	mMenu = new MainMenu();
	gSettings = new GameSettings();
	gameSession = new GameSession(gSettings);
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
			gameSession->play();
			break;

		case GameSettings::Credits:
			break;

		default:;
		}
	}
}