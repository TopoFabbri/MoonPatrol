#include "GameSession.h"

GameSession::GameSession(GameSettings* gSettings)
{
	isActive = false;

	background = LoadTexture("../res/parallax-mountain-bg.png");
	backgroundFarMount = LoadTexture("../res/parallax-mountain-montain-far.png");
	backgroundMountains = LoadTexture("../res/parallax-mountain-mountains.png");
	backgroundTrees = LoadTexture("../res/parallax-mountain-trees.png");
	backgroundForest = LoadTexture("../res/parallaxForest.png");
	ground = LoadTexture("../res/ground.png");

	scrollingBack = 0.0f;
	scrollingFarMount = 0.0f;
	scrollingMountains = 0.0f;
	scrollingTrees = 0.0f;
	scrollingForest = 0.0f;
	scrollingGround = 0.0f;

	curBullets = 0;
	scoreOnce = false;

	initEnemy(enemy);

	for (int i = 0; i < maxAirEnemies; i++)
	{
		airEnemies[i] = initAirEnemy(airEnemies[i], static_cast<float>(i) * 100.0f);
	}

	for (int i = 0; i < maxBullets; i++)
	{
		bullets[i] = initBullet(bullets[i], player);
	}

	this->gSettings = gSettings;
}

GameSession::~GameSession()
{
}

void GameSession::start(GameSettings* settings)
{
	isActive = true;

	gSettings = settings;

	initGame();

	scrollingBack = 0.0f;
	scrollingFarMount = 0.0f;
	scrollingMountains = 0.0f;
	scrollingTrees = 0.0f;
	scrollingForest = 0.0f;
	scrollingGround = 0.0f;

	curBullets = 0;
	scoreOnce = false;

	initEnemy(enemy);

	for (int i = 0; i < maxAirEnemies; i++)
	{
		airEnemies[i] = initAirEnemy(airEnemies[i], static_cast<float>(i) * 100.0f);
	}

	for (int i = 0; i < maxBullets; i++)
	{
		bullets[i] = initBullet(bullets[i], player);
	}
}

void GameSession::update()
{
	scrollingBack -= 0.1f;
	scrollingFarMount -= 0.25f;
	scrollingMountains -= 0.35f;
	scrollingTrees -= 0.45f;
	scrollingForest -= 0.55f;
	scrollingGround -= 0.75f;

	if (scrollingBack <= static_cast<float>(-background.width)) scrollingBack = 0;
	if (scrollingFarMount <= static_cast<float>(-backgroundFarMount.width) * 2) scrollingFarMount = 0;
	if (scrollingMountains <= static_cast<float>(-backgroundMountains.width) * 2) scrollingMountains = 0;
	if (scrollingTrees <= static_cast<float>(-backgroundTrees.width) * 2) scrollingTrees = 0;
	if (scrollingForest <= static_cast<float>(-backgroundForest.width) * 2) scrollingForest = 0;
	if (scrollingGround <= static_cast<float>(-ground.width)) scrollingGround = 0;

	input();

	enemyMovement(scoreOnce, enemy, airEnemies);

	bulletsMovement(bullets);

	checkCollisions();

	if (player.isAlive && (player2.isAlive || !gSettings->multiplayer))
	{
		if (IsKeyPressed(KEY_D))
		{
			if (curBullets >= maxBullets)
				curBullets = 0;

			bullets[curBullets] = initBullet(bullets[curBullets], player);
			curBullets++;
		}

		if (IsKeyPressed(KEY_LEFT))
		{
			if (curBullets >= maxBullets)
				curBullets = 0;

			bullets[curBullets] = initBullet(bullets[curBullets], player2);
			curBullets++;
		}

		if (enemy.x < player.x && !scoreOnce)
		{
			player.score += 5;
			scoreOnce = true;
		}

	}
	else if (IsKeyPressed(KEY_SPACE))
	{
		gSettings->curScene = GameSettings::Menu;
		isActive = false;
	}
}

void GameSession::play(GameSettings* settings)
{
	if (!isActive)
		start(settings);

	update();

	drawGame();
}

void GameSession::drawGame()
{
	BeginDrawing();
	ClearBackground(BLACK);

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

	DrawText((gSettings->multiplayer ? "multiplayer" : "singleplayer"), 5, 5, 20, WHITE);

	drawPlayer(player);

	if (gSettings->multiplayer)
		drawPlayer(player2);

	drawEnemy(enemy, airEnemies);
	drawBullets(bullets);

	if (!player.isAlive || (gSettings->multiplayer && !player2.isAlive))
	{
		Text* gameOver = new Text("Game Over", 60, GetScreenWidth() / 2, GetScreenHeight() / 2 - 20, RED);
		Text* score = new Text(TextFormat("Score: %i", player.score), 30,
			GetScreenWidth() / 2, GetScreenHeight() / 2 + 50, RED);
		Text* next = new Text("Press 'space' to continue", 30, GetScreenWidth() / 2, GetScreenHeight() / 2 + 80, WHITE);

		DrawRectangle(GetScreenWidth() / 2 - 225, GetScreenHeight() / 2 - 125, 450, 250, BLACK);

		gameOver->draw();
		score->draw();
		next->draw();
	}

	EndDrawing();
}

void GameSession::input()
{
	if (player.isAlive)
	{
		if (IsKeyPressed(KEY_W) && !player.isJumping)
		{
			jumpLogic(player);
		}

		if (player.isJumping == true)
		{
			player.gravity = player.gravity + player.weight * GetFrameTime();
			player.y = player.y + player.gravity * GetFrameTime();
		}
	}

	if (player2.isAlive)
	{
		if (IsKeyPressed(KEY_UP) && !player2.isJumping)
		{
			jumpLogic(player2);
		}

		if (player2.isJumping == true)
		{
			player2.gravity = player2.gravity + player2.weight * GetFrameTime();
			player2.y = player2.y + player2.gravity * GetFrameTime();
		}
	}
}

void GameSession::checkCollisions()
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

	if (gSettings->multiplayer)
	{
		if (CheckCollisionRecs(Rectangle{ player2.x, player2.y, 50, 20 }, Rectangle{ enemy.x, enemy.y, 40, 40 }))
		{
			player2.isAlive = false;
			enemy.isActive = false;
			for (int i = 0; i < maxAirEnemies; i++)
			{
				airEnemies[i].isActive = false;
			}
		}

		if (CheckCollisionRecs(Rectangle{ player2.x, player2.y, 50, 20 }, Rectangle{ 0, GetScreenHeight() / 1.27f, static_cast<float>(GetScreenWidth()), GetScreenHeight() / 1.25f }))
		{
			player2.isJumping = false;
			player2.gravity = 0;
		}
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

void GameSession::initGame()
{
	initPlayer(player, static_cast<float>(GetScreenWidth()) / 4.2f);
	initPlayer(player2, static_cast<float>(GetScreenWidth()) / 4.2f + 60);
	initEnemy(enemy);
}

void GameSession::jumpLogic(Player& pj)
{
	pj.gravity = -320;
	pj.y = pj.y + pj.gravity * GetFrameTime();

	if (pj.y > 440)
		pj.isJumping = true;
}