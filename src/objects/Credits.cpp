#include "Credits.h"

Credits::Credits()
{
	title = new Text("Credits:", 60, GetScreenWidth() / 2, GetScreenHeight() / 2 - 100, GREEN);
	dev1 = new Text("Tobias Godoy", 30, GetScreenWidth() / 2, GetScreenHeight() / 2 - 50, WHITE);
	dev2 = new Text("Mateo Fabbri", 30, GetScreenWidth() / 2, GetScreenHeight() / 2, WHITE);
	version = new Text("0.4", 30, 0, 5, RED);
	back = new Button();
}

Credits::~Credits()
{
	delete title;
	delete dev1;
	delete dev2;
}

void Credits::update(GameSettings* settings)
{
	back->setPos({ static_cast<float>(GetScreenWidth()) / 4,
		static_cast<float>(GetScreenHeight()) - 100 });

	back->setTxt("Back");

	back->update();

	version->setPos(GetScreenWidth() - version->measure(), 5);
	title->setPos(GetScreenWidth() / 2, GetScreenHeight() / 2 - 100);
	dev1->setPos(GetScreenWidth() / 2, GetScreenHeight() / 2 - 25);
	dev2->setPos(GetScreenWidth() / 2, GetScreenHeight() / 2 + 25);

	if (back->isPressed())
		settings->curScene = GameSettings::Menu;
}

void Credits::draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	title->draw();
	dev1->draw();
	dev2->draw();
	version->draw();

	back->draw();

	EndDrawing();
}

void Credits::run(GameSettings* settings)
{
	update(settings);
	draw();
}