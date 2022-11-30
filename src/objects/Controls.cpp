#include "Controls.h"

namespace Topo
{
	Controls::Controls()
	{
		title = new Text("Controls:", 60, GetScreenWidth() / 2, GetScreenHeight() / 2 - 100, GREEN);
		player1 = new Text("Player 1:", 50, GetScreenWidth() / 2, GetScreenHeight() / 2 - 50, BLUE);
		jump1 = new Text("    Jump - W", 30, GetScreenWidth() / 2, GetScreenHeight() / 2 - 10, BLUE);
		fire1 = new Text("    Fire - d", 30, GetScreenWidth() / 2, GetScreenHeight() / 2 + 30, BLUE);
		player2 = new Text("Player 2:", 50, GetScreenWidth() / 2, GetScreenHeight() / 2 + 80, RED);
		jump2 = new Text("    Jump - ^", 30, GetScreenWidth() / 2, GetScreenHeight() / 2 + 110, RED);
		fire2 = new Text("    Fire - <", 30, GetScreenWidth() / 2, GetScreenHeight() / 2 + 140, RED);
		back = new Button();
	}

	Controls::~Controls()
	{
		delete title;
		delete player1;
		delete jump1;
		delete fire1;
		delete player2;
		delete jump2;
		delete fire2;
		delete back;
	}

	void Controls::update(GameSettings* settings)
	{
		back->setPos({ static_cast<float>(GetScreenWidth()) / 4,
		static_cast<float>(GetScreenHeight()) - 100 });

		back->setTxt("Back");

		back->update();

		title->setPos(GetScreenWidth() / 2, GetScreenHeight() / 2 - 125);
		player1->setPos(GetScreenWidth() / 2, GetScreenHeight() / 2 - 50);
		jump1->setPos(GetScreenWidth() / 2, GetScreenHeight() / 2 + 0);
		fire1->setPos(GetScreenWidth() / 2, GetScreenHeight() / 2 + 40);
		player2->setPos(GetScreenWidth() / 2, GetScreenHeight() / 2 + 90);
		jump2->setPos(GetScreenWidth() / 2, GetScreenHeight() / 2 + 140);
		fire2->setPos(GetScreenWidth() / 2, GetScreenHeight() / 2 + 180);

		if (back->isPressed())
			settings->curScene = GameSettings::Menu;
	}

	void Controls::draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		title->draw();
		player1->draw();
		jump1->draw();
		fire1->draw();
		player2->draw();
		jump2->draw();
		fire2->draw();
		back->draw();

		EndDrawing();
	}

	void Controls::run(GameSettings* settings)
	{
		update(settings);

		draw();
	}
}