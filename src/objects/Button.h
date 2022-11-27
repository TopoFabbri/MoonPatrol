#pragma once

#include <raylib.h>

class Button
{
private:
	Rectangle rec;
	Color normal;
	Color hovered;
	Color txtColor;
	Texture2D sprite;
	float size;
	float txtSpacing;
	const char* text;
	float indent;
	Font font;

public:
	Button();

	void update();
	void draw();

	bool isPressed();
	void setTxt(const char* txt);
	void setPos(Vector2 newPos);
};