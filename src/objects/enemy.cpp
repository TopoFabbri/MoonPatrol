#include "enemy.h"

Enemy enemy;
Enemy airEnemies[maxAirEnemies];

void initEnemy()
{
	enemy.x = static_cast<float>(GetScreenWidth() - GetScreenWidth() / 10);
	enemy.y = static_cast<float>(GetScreenHeight() / 1.35);

	enemy.isActive = true;

	enemy.speed = { 200,200 };
}

Enemy initAirEnemy(Enemy enemys, float x)
{
	enemys.x = -x;
	enemys.y = static_cast<float>(GetScreenHeight() / 2.5);

	enemys.isActive = true;

	enemys.speed = { 200,200 };

	return enemys;
}

void drawEnemy()
{
	DrawRectangle(static_cast<int>(enemy.x), static_cast<int>(enemy.y), 40, 40, RED);

	for (int i = 0; i < maxAirEnemies; i++)
	{
		DrawRectangle(static_cast<int>(airEnemies[i].x), static_cast<int>(airEnemies[i].y), 40, 40, RED);
	}


}

void enemyMovement()
{
	if (enemy.isActive)
	{
		enemy.x -= enemy.speed.x * GetFrameTime();
	}

	for (int i = 0; i < maxAirEnemies; i++)
	{
		if (airEnemies[i].isActive)
		{
			airEnemies[i].x += airEnemies[i].speed.x * GetFrameTime();
			airEnemies[i].y = airEnemies[i].y + airEnemies[i].speed.y * GetFrameTime();

			if (airEnemies[i].y < 200)
			{
				 airEnemies[i].speed.y *= - 1;
			}
			else if (airEnemies[i].y >= 400)
			{
				airEnemies[i].speed.y *= -1;
			}

		}

	}


	enemyTeleportation();
}

void enemyTeleportation()
{
	if (enemy.x < -40)
	{
		enemy.x = static_cast<float>(GetScreenWidth());
	}

	for (int i = 0; i < maxAirEnemies; i++)
	{
		if (airEnemies[i].x > GetScreenWidth())
		{
			airEnemies[i].x = -20;
		}

	}
}