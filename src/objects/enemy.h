#pragma once
#include "raylib.h"

namespace Topo
{
	const int maxAirEnemies = 5;

	struct Enemy
	{
		float x;
		float y;
		bool isActive;
		Vector2 speed;
	};

	void initEnemy(Enemy& enemy);

	Enemy initAirEnemy(Enemy enemies, float x);

	void drawEnemy(Enemy& enemy, Enemy airEnemies[]);

	void enemyMovement(bool& scoreOnce, Enemy& enemy, Enemy airEnemies[]);

	void enemyTeleportation(bool& scoreOnce, Enemy& enemy, Enemy airEnemies[]);

}