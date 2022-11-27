#pragma once
#include <raylib.h>

#include "MainMenu.h"
#include "GameSession.h"
#include "GameSettings.h"

class Game
{
private:
	GameSession* gameSession;
	MainMenu* mMenu;
	GameSettings* gSettings;

public:
	Game();
	~Game();

	void runGame();
};
