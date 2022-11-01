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
static void jumpLogic();


void runGame()
{

	initGame();

	int currentScreen = Gameplay;

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
		
		if (IsKeyPressed(KEY_SPACE))
		{
			jumpLogic();
		}

		if (player.isJumping == true)
		{
			player.gravity = player.gravity + player.weight * GetFrameTime();
			player.y = player.y + player.gravity * GetFrameTime();

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

	if (CheckCollisionRecs(Rectangle{ player.x, player.y, 50, 20 }, Rectangle{ 0, GetScreenHeight() / 1.25f, static_cast<float>(GetScreenWidth()), GetScreenHeight() / 1.25f }))
	{
		player.isJumping = false;
		player.gravity = 0;
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

void jumpLogic()
{

	player.gravity = -250;
	player.y = player.y + player.gravity * GetFrameTime();

	if (player.y > 440)
	{
		player.isJumping = true;
	}
	
	
		
}