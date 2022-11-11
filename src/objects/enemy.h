#pragma once
#include "raylib.h"

const int maxAirEnemies = 5;

struct Enemy
{
	float x;
	float y;
	bool isActive;
	Vector2 speed;


};

void initEnemy();

Enemy initAirEnemy(Enemy enemys, float x);

void drawEnemy();

void enemyMovement();

void enemyTeleportation();
