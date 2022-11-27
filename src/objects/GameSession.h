#pragma once
#include <raylib.h>

#include "GameSettings.h"
#include "objects/bullets.h"
#include "objects/enemy.h"
#include "objects/Text.h"

class GameSession
{
private:
	bool isActive;
	float scrollingBack;
	float scrollingFarMount;
	float scrollingMountains;
	float scrollingTrees;
	float scrollingForest;
	float scrollingGround;

	int curBullets;
	bool scoreOnce;

	Texture2D background;
	Texture2D backgroundFarMount;
	Texture2D backgroundMountains;
	Texture2D backgroundTrees;
	Texture2D backgroundForest;
	Texture2D ground;

	Player player;
	Enemy enemy;
	Bullet bullets[maxBullets];
	Enemy airEnemies[maxAirEnemies];

	GameSettings* gSettings;

public:
	GameSession(GameSettings* gSettings);
	~GameSession();

	void start();
	void update();
	void play();

	void drawGame();
	void input();
	void checkCollisions();
	void initGame();
	void jumpLogic();
};