#pragma once
#include "raylib.h"



struct Player
{
	float x;
	float y;
	float gravity;
	int score;
	int weight;
	bool isAlive;
	bool isJumping;
	Vector2 speed;

};

void initPlayer(Player& player);

void drawPlayer(Player& player);