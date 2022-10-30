#pragma once
#include "raylib.h"

struct Enemy
{
	float x;
	float y;
	Vector2 speed;


};

void initEnemy();

void drawEnemy();

void enemyMovement();
