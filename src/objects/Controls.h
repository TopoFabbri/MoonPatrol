#pragma once
#include "Button.h"
#include "GameSettings.h"
#include "Text.h"

namespace Topo
{
	class Controls
	{
	private:
		Text* title;
		Text* player1;
		Text* jump1;
		Text* fire1;
		Text* player2;
		Text* jump2;
		Text* fire2;
		Button* back;

	public:
		Controls();
		~Controls();

		void update(GameSettings* settings);
		void draw();

		void run(GameSettings* settings);
	};
}