#pragma once
#include "raylib.h"

#include "player.h"

const int maxBullets = 20;

struct Bullet
{
	float x;
	float y;
	float radius;
	bool isActive;
	Vector2 speed;
};

Bullet initBullet(Bullet bullet, Player player);

void drawBullets(Bullet bullets[]);

void bulletsMovement(Bullet bullets[]);