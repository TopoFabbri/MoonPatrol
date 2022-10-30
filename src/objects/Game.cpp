#include "game.h"

#include "raylib.h"

#include "player.h"
#include "enemy.h"


extern Player player;
extern Enemy enemy;

void drawGame();
void input();
void checkCollisions();


void runGame()
{

	int screenWidth = 1024;
	int screenHeight = 768;

	InitWindow(screenWidth, screenHeight, "Moon Patrol v0.1");
	SetWindowState(FLAG_VSYNC_HINT);

	initPlayer();
	initEnemy();

	while (!WindowShouldClose())
	{

		input();

		enemyMovement();

		checkCollisions();

		BeginDrawing();
		ClearBackground(BLACK);

		drawGame();

		DrawFPS(10, 10);
		EndDrawing();

	}
	CloseWindow();
}

void drawGame()
{
	drawPlayer();
	drawEnemy();

	DrawRectangle(0, static_cast<int>(GetScreenHeight() / 1.25f), GetScreenWidth(), static_cast<int>(GetScreenHeight() / 1.25f), GREEN);

}

void input()
{
	if (player.isAlive)
	{
		if (IsKeyPressed(KEY_W))
		{
			player.y = static_cast<float>(GetScreenHeight() / 1.5);
		}
		else if (IsKeyPressed(KEY_S))
		{
			player.y = static_cast<float>(GetScreenHeight() / 1.3);
		}
	}
	
}

void checkCollisions()
{
	if (CheckCollisionRecs(Rectangle{ player.x, player.y, 50, 20 }, Rectangle{ enemy.x, enemy.y, 40, 40 }))
	{
		player.isAlive = false;
		enemy.isActive = false;
	}
}
