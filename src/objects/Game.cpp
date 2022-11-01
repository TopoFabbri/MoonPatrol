#include "game.h"

#include "raylib.h"

#include "player.h"
#include "enemy.h"


extern Player player;
extern Enemy enemy;

static void initGame();
static void drawGame();
static void input();
static void checkCollisions();
static void drawMenu();
static void drawCredits();


void runGame()
{

	initGame();

	int currentScreen = Credits;

	while (!WindowShouldClose())
	{
		if (currentScreen == Gameplay)
		{
			input();

			enemyMovement();

			checkCollisions();
		}


		if (currentScreen == Menu && IsKeyPressed(KEY_E))
			currentScreen = Gameplay;

		BeginDrawing();
		ClearBackground(BLACK);

		switch (currentScreen)
		{
		case Menu:
			drawMenu();
			break;
		case Gameplay:
			drawGame();
			break;
		case Credits:
			drawCredits();
			break;
		default:
			break;
		}


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

void initGame()
{

	int screenWidth = 1024;
	int screenHeight = 768;

	InitWindow(screenWidth, screenHeight, "Moon Patrol v0.2");
	SetWindowState(FLAG_VSYNC_HINT);

	initPlayer();
	initEnemy();

}

void drawMenu()
{
	int titleLength = MeasureText("Moon Patrol", 50);



	DrawText("Moon Patrol", GetScreenWidth() / 2 - titleLength / 2, GetScreenHeight() / 6, 50, RED);
	DrawText("Press E to start...", GetScreenWidth() / 2 - titleLength / 2 - 80, GetScreenHeight() / 2, 50, RED);
}

void drawCredits()
{
	DrawText("Made by Godoy Tobias", GetScreenWidth() / 2 - 250, GetScreenHeight() / 6, 50, RED);

}