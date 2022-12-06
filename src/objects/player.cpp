#include "player.h"

namespace Topo
{
	void initPlayer(Player& player, float x)
	{
		player.x = x;
		player.y = static_cast<float>(GetScreenHeight() / 1.4);

		player.score = 0;

		player.isAlive = true;

		player.gravity = 0;

		player.isJumping = true;

		player.weight = 600;

		player.speed = { 200,200 };
	}

	void drawPlayer(Player& player, Color color)
	{
		if (player.isAlive)
		{
			DrawRectangle(static_cast<int>(player.x), static_cast<int>(player.y), 50, 20, color);
		}
	}
}