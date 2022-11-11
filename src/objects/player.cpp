#include "player.h"

Player player;

void initPlayer()
{
	player.x = static_cast<float>(GetScreenWidth() / 4.2);
	player.y = static_cast<float>(GetScreenHeight() / 1.3);

	player.isAlive = true;

	player.gravity = 0;

	player.isJumping = false;

	player.weight = 600;

	player.speed = { 200,200 };
}

void drawPlayer()
{
	if (player.isAlive)
	{
		DrawRectangle(static_cast<int>(player.x), static_cast<int>(player.y), 50, 20, RED);
	}

}