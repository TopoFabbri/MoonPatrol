#include "MainMenu.h"

MainMenu::MainMenu()
{
	isActive = false;

	title = new Text("Main Menu", 50, GetScreenWidth() / 2, GetScreenHeight() / 8, WHITE);
	play = new Button();
	credits = new Button();
	multiplayer = new CheckBox();
}

MainMenu::~MainMenu()
{
}

void MainMenu::run(GameSettings* settings)
{
	if (!isActive)
		start();

	update(settings);

	draw();
}

void MainMenu::start()
{
	isActive = true;
}

void MainMenu::update(GameSettings* settings)
{
	play->setTxt("Play");
	play->setPos({ static_cast<float>(GetScreenWidth()) / 4,
		(static_cast<float>(GetScreenHeight()) / 8) * 2 });
	play->update();

	credits->setTxt("Credits");
	credits->setPos({ static_cast<float>(GetScreenWidth()) / 4,
		(static_cast<float>(GetScreenHeight()) / 8) * 3 });
	credits->update();

	title->setPos(GetScreenWidth() / 2, GetScreenHeight() / 8);

	if (play->isPressed())
		settings->curScene = GameSettings::Gameplay;
}

void MainMenu::draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	title->draw();
	play->draw();
	credits->draw();

	EndDrawing();
}