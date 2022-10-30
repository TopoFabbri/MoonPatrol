#pragma once
#include "raylib.h"



struct Player
{
	float x;
	float y;
	bool isAlive;
	Vector2 speed;

};

void initPlayer();

void drawPlayer();
