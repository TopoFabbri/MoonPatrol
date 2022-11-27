#pragma once

#include "Button.h"
#include "CheckBox.h"
#include "GameSettings.h"
#include "Topo.h"
#include "Text.h"

class MainMenu
{
private:
	bool isActive;

	Text* title;
	Button* play;
	Button* credits;
	CheckBox* multiplayer;

public:
	MainMenu();
	~MainMenu();

	void run(GameSettings* settings);
	void start();
	void update(GameSettings* settings);
	void draw();
};
