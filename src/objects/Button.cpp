#include "Button.h"

Button::Button()
{
	rec = { 0, 0, 200, 50 };
	normal = BLUE;
	hovered = GREEN;
	txtColor = WHITE;
	sprite = LoadTexture("res/ui/Button.png");
	size = 60;
	txtSpacing = 1;
	text = "Button";
	indent = 10;
	font = GetFontDefault();
}

void Button::update()
{
	size = (float)GetScreenWidth() * (1.f / 32.f);

	const Vector2 txtSize = MeasureTextEx(font, text, size, txtSpacing);

	rec.width = txtSize.x + 2 * indent;
	rec.height = txtSize.y + 2 * indent;
}

void Button::draw()
{
	const Rectangle source{ 0, 0, (float)sprite.width, (float)sprite.height };
	const float rot = 10;

	if (CheckCollisionPointRec(GetMousePosition(), rec))
	{
		DrawRectanglePro(rec, { 0, 0 }, rot, hovered);
		DrawTextPro(font, text, { rec.x + indent,rec.y + indent },
			{ 0, 0 }, rot, size, txtSpacing, txtColor);
	}
	else
	{
		DrawRectanglePro(rec, { 0, 0 }, 0, normal);
		DrawTextPro(font, text, { rec.x + indent,rec.y + indent },
			{ 0, 0 }, 0, size, txtSpacing, txtColor);
	}

}

bool Button::isPressed()
{
	return (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) &&
		CheckCollisionPointRec(GetMousePosition(), rec));
}

void Button::setTxt(const char* txt)
{
	text = txt;
}

void Button::setPos(Vector2 newPos)
{
	rec.x = newPos.x;
	rec.y = newPos.y;
}