#include "player.h"

Player player;

void initPlayer()
{
	player.x = static_cast<float>(GetScreenWidth() / 4.2);
	player.y = static_cast<float>(GetScreenHeight() / 1.3);

	player.speed = { 200,200 };
}