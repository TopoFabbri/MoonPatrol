#pragma once
#include <raylib.h>

#include "Controls.h"
#include "Credits.h"
#include "MainMenu.h"
#include "GameSession.h"
#include "GameSettings.h"

class Game
{
private:
	GameSession* gameSession;
	MainMenu* mMenu;
	GameSettings* gSettings;
	Credits* creds;
	Controls* controls;

public:
	Game();
	~Game();

	void runGame();
};
