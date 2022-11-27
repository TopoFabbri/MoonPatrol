#include "enemy.h"

void initEnemy(Enemy& enemy)
{
	enemy.x = static_cast<float>(static_cast<float>(GetScreenWidth()) - static_cast<float>(GetScreenWidth()) / 10);
	enemy.y = static_cast<float>(GetScreenHeight() / 1.35);

	enemy.isActive = true;

	enemy.speed = { 200,200 };
}

Enemy initAirEnemy(Enemy enemies, float x)
{
	enemies.x = -x;
	enemies.y = static_cast<float>(GetScreenHeight() / 2.5);

	enemies.isActive = true;

	enemies.speed = { 200,200 };

	return enemies;
}

void drawEnemy(Enemy& enemy, Enemy airEnemies[])
{
	DrawRectangle(static_cast<int>(enemy.x), static_cast<int>(enemy.y), 40, 40, RED);

	for (int i = 0; i < maxAirEnemies; i++)
	{
		DrawRectangle(static_cast<int>(airEnemies[i].x), static_cast<int>(airEnemies[i].y), 40, 40, RED);
	}


}

void enemyMovement(bool& scoreOnce, Enemy& enemy, Enemy airEnemies[])
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

			if (airEnemies[i].y <= 200)
			{
				 airEnemies[i].speed.y *= - 1;
			}
			else if (airEnemies[i].y >= 400)
			{
				airEnemies[i].speed.y *= -1;
			}

		}

	}

	enemyTeleportation(scoreOnce, enemy, airEnemies);
}

void enemyTeleportation(bool& scoreOnce, Enemy& enemy, Enemy airEnemies[])
{
	if (enemy.x < -40)
	{
		enemy.x = static_cast<float>(GetScreenWidth());
		scoreOnce = false;
	}

	for (int i = 0; i < maxAirEnemies; i++)
	{
		if (airEnemies[i].x > GetScreenWidth())
		{
			airEnemies[i].x = -20;
		}

	}
}