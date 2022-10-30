#include "game.h"

#include "raylib.h"

#include "player.h"


extern Player player;

void drawGame();




void runGame()
{

	int screenWidth = 1024;
	int screenHeight = 768;

	InitWindow(screenWidth, screenHeight, "Moon Patrol v0.1");
	SetWindowState(FLAG_VSYNC_HINT);

	initPlayer();

	while (!WindowShouldClose())
	{
  


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

	DrawRectangle(0, static_cast<int>(GetScreenHeight() / 1.25f), GetScreenWidth(), static_cast<int>(GetScreenHeight() / 1.25f), GREEN);

}

