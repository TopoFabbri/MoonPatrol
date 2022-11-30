#pragma once
#include <raylib.h>

#include "GameSettings.h"
#include "objects/bullets.h"
#include "objects/enemy.h"
#include "objects/Text.h"

namespace Topo
{
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
		Player player2;
		Enemy enemy;
		Bullet bullets[maxBullets];
		Enemy airEnemies[maxAirEnemies];

		GameSettings* gSettings;

	public:
		GameSession(GameSettings* gSettings);
		~GameSession();

		void start(GameSettings* settings);
		void update();
		void play(GameSettings* settings);

		void drawGame();
		void input();
		void checkCollisions();
		void initGame();
		void jumpLogic(Player& pj);
	};
}