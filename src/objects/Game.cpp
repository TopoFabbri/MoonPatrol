#include "game.h"

#include "raylib.h"

#include "player.h"
#include "enemy.h"
#include "bullets.h"


extern Player player;
extern Enemy enemy;

extern Bullet bullets[maxBullets];
extern Enemy airEnemies[maxAirEnemies];

static void initGame();
static void drawGame(Texture2D background, float scrollingBack, Texture2D backgroundFarMount, float scrollingFarMount, Texture2D backgroundMountains, float scrollingMountains, Texture2D backgroundTrees, float scrollingTrees, Texture2D backgroundForest, float scrollingForest, Texture2D ground, float scrollingGround);
static void input();
static void checkCollisions();
static void drawMenu();
static void drawCredits();
static void jumpLogic();


void runGame()
{
	initGame();

	Texture2D background = LoadTexture("../res/parallax-mountain-bg.png");
	Texture2D backgroundFarMount = LoadTexture("../res/parallax-mountain-montain-far.png");
	Texture2D backgroundMountains = LoadTexture("../res/parallax-mountain-mountains.png");
	Texture2D backgroundTrees = LoadTexture("../res/parallax-mountain-trees.png");
	Texture2D backgroundForest = LoadTexture("../res/parallaxForest.png");
	Texture2D ground = LoadTexture("../res/ground.png");


	float scrollingBack = 0.0f;
	float scrollingFarMount = 0.0f;
	float scrollingMountains = 0.0f;
	float scrollingTrees = 0.0f;
	float scrollingForest = 0.0f;
	float scrollingGround = 0.0f;

	int currentBullets = 0;
	bool scoreOnce = false;

	int currentScreen = Menu;


	for (int i = 0; i < maxAirEnemies; i++)
	{
		airEnemies[i] = initAirEnemy(airEnemies[i], i * 100.0f);
	}

	while (!WindowShouldClose())
	{
		scrollingBack -= 0.1f;
		scrollingFarMount -= 0.25f;
		scrollingMountains -= 0.35f;
		scrollingTrees -= 0.45f;
		scrollingForest -= 0.55f;
		scrollingGround -= 0.75f;

		if (scrollingBack <= -background.width) scrollingBack = 0;
		if (scrollingFarMount <= -backgroundFarMount.width * 2) scrollingFarMount = 0;
		if (scrollingMountains <= -backgroundMountains.width * 2) scrollingMountains = 0;
		if (scrollingTrees <= -backgroundTrees.width * 2) scrollingTrees = 0;
		if (scrollingForest <= -backgroundForest.width * 2) scrollingForest = 0;
		if (scrollingGround <= -ground.width) scrollingGround = 0;

		if (currentScreen == Gameplay)
		{
			input();

			enemyMovement(scoreOnce);

			bulletsMovement();

			checkCollisions();

			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && player.isAlive)
			{
				if (currentBullets >= maxBullets)
					currentBullets = 0;

				bullets[currentBullets] = initBullet(bullets[currentBullets], player);
				currentBullets++;
			}
		}

		if (enemy.x < player.x && !scoreOnce)
		{
			player.score += 5;
			scoreOnce = true;
		}

		if (currentScreen == Menu && IsKeyPressed(KEY_E))
			currentScreen = Gameplay;
		if (currentScreen == Menu && IsKeyPressed(KEY_C))
			currentScreen = Credits;

		BeginDrawing();
		ClearBackground(BLACK);

		switch (currentScreen)
		{
		case Menu:
			drawMenu();
			break;
		case Gameplay:
			drawGame(background, scrollingBack, backgroundFarMount, scrollingFarMount, backgroundMountains, scrollingMountains, backgroundTrees, scrollingTrees, backgroundForest, scrollingForest, ground, scrollingGround);
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

void drawGame(Texture2D background, float scrollingBack, Texture2D backgroundFarMount, float scrollingFarMount, Texture2D backgroundMountains, float scrollingMountains, Texture2D backgroundTrees, float scrollingTrees, Texture2D backgroundForest, float scrollingForest, Texture2D ground, float scrollingGround)
{
	DrawTextureEx(background, Vector2{ scrollingBack, 0 }, 0.0f, 1.0f, WHITE);
	DrawTextureEx(background, Vector2{ background.width + scrollingBack, 0 }, 0.0f, 1.0f, WHITE);

	DrawTextureEx(backgroundFarMount, Vector2{ scrollingFarMount, 220 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(backgroundFarMount, Vector2{ backgroundFarMount.width * 2 + scrollingFarMount, 220 }, 0.0f, 2.0f, WHITE);

	DrawTextureEx(backgroundMountains, Vector2{ scrollingMountains, 220 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(backgroundMountains, Vector2{ backgroundMountains.width * 2 + scrollingMountains, 220 }, 0.0f, 2.0f, WHITE);

	DrawTextureEx(backgroundTrees, Vector2{ scrollingTrees, 250 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(backgroundTrees, Vector2{ backgroundTrees.width * 2 + scrollingTrees, 250 }, 0.0f, 2.0f, WHITE);

	DrawTextureEx(backgroundForest, Vector2{ scrollingForest, 250 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(backgroundForest, Vector2{ backgroundForest.width * 2 + scrollingForest, 250 }, 0.0f, 2.0f, WHITE);

	DrawRectangle(0, static_cast<int>(GetScreenHeight() / 1.27f), GetScreenWidth(), static_cast<int>(GetScreenHeight() / 1.25f), BLACK);

	DrawTextureEx(ground, Vector2{ scrollingGround, 130 }, 0.0f, 1.0f, WHITE);
	DrawTextureEx(ground, Vector2{ ground.width + scrollingGround, 130 }, 0.0f, 1.0f, WHITE);

	DrawText(TextFormat("Score: %i", player.score), 700, 10, 30, WHITE);

	drawPlayer();
	drawEnemy();
	drawBullets();

	if (!player.isAlive)
	{
		DrawRectangle(GetScreenWidth() / 2 - 225, GetScreenHeight() / 2 - 125, 450, 250, BLACK);
		
		DrawText("Game Over", GetScreenWidth() / 2 - 140, GetScreenHeight() / 2 - 20, 60, RED);
		DrawText(TextFormat("Score: %i", player.score), GetScreenWidth() / 2 - 140, GetScreenHeight() / 2 + 50, 30, RED);
	}

}

void input()
{
	if (player.isAlive)
	{

		if (IsKeyPressed(KEY_SPACE) && !player.isJumping)
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
		for (int i = 0; i < maxAirEnemies; i++)
		{
			airEnemies[i].isActive = false;
		}
		
	}

	if (CheckCollisionRecs(Rectangle{ player.x, player.y, 50, 20 }, Rectangle{ 0, GetScreenHeight() / 1.27f, static_cast<float>(GetScreenWidth()), GetScreenHeight() / 1.25f }))
	{
		player.isJumping = false;
		player.gravity = 0;
	}

	for (int i = 0; i < maxBullets; i++)
	{
		for (int j = 0; j < maxAirEnemies; j++)
		{
			if (CheckCollisionCircleRec(Vector2{ bullets[i].x, bullets[i].y }, bullets[i].radius, Rectangle{ airEnemies[j].x, airEnemies[j].y, 40, 40 }) && bullets[i].isActive)
			{
				airEnemies[j].x = -50;
				bullets[i].isActive = false;
				player.score += 10;

			}
		}
	}

}

void initGame()
{

	int screenWidth = 1024;
	int screenHeight = 768;

	InitWindow(screenWidth, screenHeight, "Moon Patrol v0.3");
	SetWindowState(FLAG_VSYNC_HINT);

	initPlayer();
	initEnemy();

}

void drawMenu()
{
	int titleLength = MeasureText("Moon Patrol", 50);


	DrawText("Moon Patrol", GetScreenWidth() / 2 - titleLength / 2, GetScreenHeight() / 6, 50, RED);
	DrawText("Press E to start...", GetScreenWidth() / 2 - titleLength / 2 - 80, GetScreenHeight() / 2, 50, RED);
	DrawText("Press C to see credits...", GetScreenWidth() / 2 - titleLength / 2 - 80, 500, 50, RED);
}

void drawCredits()
{
	DrawText("Made by Godoy Tobias", GetScreenWidth() / 2 - 250, GetScreenHeight() / 6, 50, RED);

}

void jumpLogic()
{

	player.gravity = -320;
	player.y = player.y + player.gravity * GetFrameTime();

	if (player.y > 440)
	{
		player.isJumping = true;
	}


}
