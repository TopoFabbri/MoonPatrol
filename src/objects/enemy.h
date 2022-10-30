#pragma once
#include "raylib.h"

struct Enemy
{
	float x;
	float y;
	bool isActive;
	Vector2 speed;


};

void initEnemy();

void drawEnemy();

void enemyMovement();
