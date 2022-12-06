#include "bullets.h"

namespace Topo
{
	Bullet initBullet(Bullet bullet, Player player)
	{
		bullet.radius = 5;
		bullet.x = player.x;
		bullet.y = player.y;
		bullet.isActive = true;


		bullet.speed.x = 50;
		bullet.speed.y = 200;


		return bullet;
	}

	void drawBullets(Bullet bullets[])
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (bullets[i].isActive)
			{
				DrawCircle(static_cast<int>(bullets[i].x), static_cast<int>(bullets[i].y), bullets[i].radius, WHITE);
			}
		}
	}

	void bulletsMovement(Bullet bullets[])
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (bullets[i].isActive)
			{
				bullets[i].x += bullets[i].speed.x * GetFrameTime();
				bullets[i].y -= bullets[i].speed.y * GetFrameTime();
			}
		}
	}

}