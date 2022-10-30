#include "enemy.h"

Enemy enemy;

void initEnemy()
{
	enemy.x = static_cast<float>(GetScreenWidth() - GetScreenWidth() / 10);
	enemy.y = static_cast<float>(GetScreenHeight() / 1.35);

	enemy.isActive = true;

	enemy.speed = { 200,200 };
}

void drawEnemy()
{
	DrawRectangle(static_cast<int>(enemy.x), static_cast<int>(enemy.y), 40, 40, RED);

}

void enemyMovement()
{
	if (enemy.isActive)
	{
		enemy.x -= enemy.speed.x * GetFrameTime();
	}

	enemyTeleportation();
}

void enemyTeleportation()
{
	if (enemy.x < -40)
	{
		enemy.x = static_cast<float>(GetScreenWidth());
	}
}