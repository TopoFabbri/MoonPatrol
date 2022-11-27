#include "MainMenu.h"

MainMenu::MainMenu()
{
	isActive = false;

	title = new Text("Main Menu", 50, GetScreenWidth() / 2, GetScreenHeight() / 8, WHITE);
	version = new Text("0.4", 30, 0, 5, RED);
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
	multiplayer->txt = "Multiplayer mode";
	multiplayer->rec.x = static_cast<float>(GetScreenWidth()) / 4;
	multiplayer->rec.y = (static_cast<float>(GetScreenHeight()) / 8) * 4;

	play->setTxt("Play");
	play->setPos({ static_cast<float>(GetScreenWidth()) / 4,
		(static_cast<float>(GetScreenHeight()) / 8) * 2 });
	play->update();

	credits->setTxt("Credits");
	credits->setPos({ static_cast<float>(GetScreenWidth()) / 4,
		(static_cast<float>(GetScreenHeight()) / 8) * 3 });
	credits->update();

	version->setPos(GetScreenWidth() - version->measure(), 5);
	title->setPos(GetScreenWidth() / 2, GetScreenHeight() / 8);

	settings->multiplayer = multiplayer->checked;

	if (play->isPressed() || IsKeyPressed(KEY_SPACE))
		settings->curScene = GameSettings::Gameplay;

	if (credits->isPressed())
		settings->curScene = GameSettings::Credits;
}

void MainMenu::draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	title->draw();
	version->draw();
	play->draw();
	credits->draw();
	multiplayer->draw();

	EndDrawing();
}