#pragma once
#include "raylib.h"

const int maxBullets = 20;

struct Bullet
{
	float x;
	float y;
	float radius;
	float rotation;
	bool isActive;
	Vector2 speed;
};

Bullet initBullet(Bullet bullet, Player player);