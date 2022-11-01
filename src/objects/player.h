#pragma once
#include "raylib.h"



struct Player
{
	float x;
	float y;
	float gravity;
	int weight;
	bool isAlive;
	bool isJumping;
	Vector2 speed;

};

void initPlayer();

void drawPlayer();
