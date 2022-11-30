#include "CheckBox.h"

namespace Topo
{
	CheckBox::CheckBox()
	{
		rec = { 0, 0, 25, 25 };
		checked = false;
		out = LIGHTGRAY;
		empty = RAYWHITE;
		fill = DARKGRAY;
		txt = "Checkbox";
	}

	CheckBox::~CheckBox()
	{
	}

	void CheckBox::draw()
	{
		float shadowOffset = (float)GetScreenWidth() * (1.f / 480.f);
		rec.width = (float)GetScreenWidth() * (5.f / 128.f);
		rec.height = (float)GetScreenWidth() * (5.f / 128.f);

		if (checked)
			DrawRectangleRec(rec, fill);
		else
			DrawRectangleRec(rec, empty);

		DrawRectangleLinesEx(rec, 3, out);
		DrawText(txt, (int)(rec.x + rec.width + 10 + shadowOffset),
			(int)(rec.y + shadowOffset),
			(int)((float)GetScreenHeight() * (1.f / 32.f)), BLACK);
		DrawText(txt, (int)(rec.x + rec.width + 10), (int)rec.y, (int)((float)GetScreenWidth() * (1.f / 32.f)), WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), rec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			checked = !checked;
		}
	}
}