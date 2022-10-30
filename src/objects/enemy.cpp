#include "enemy.h"

Enemy enemy;

void initEnemy()
{
	enemy.x = static_cast<float>(GetScreenWidth() - GetScreenWidth() / 10);
	enemy.y = static_cast<float>(GetScreenHeight() / 1.35);

	enemy.speed = { 200,200 };
}

void drawEnemy()
{
	DrawRectangle(static_cast<int>(enemy.x), static_cast<int>(enemy.y), 40, 40, RED);

}

void enemyMovement()
{
	enemy.x -= enemy.speed.x * GetFrameTime();
}