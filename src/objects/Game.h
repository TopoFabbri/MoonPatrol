#pragma once
#include <raylib.h>

#include "MainMenu.h"
#include "GameSession.h"
#include "GameSettings.h"

class Credits;

class Game
{
private:
	GameSession* gameSession;
	MainMenu* mMenu;
	GameSettings* gSettings;
	Credits* creds;

public:
	Game();
	~Game();

	void runGame();
};
