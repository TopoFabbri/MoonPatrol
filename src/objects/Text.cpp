#include "Text.h"

Text::Text(const char* newText, int newSize, int x, int y, Color color)
{
	text = newText;
	size = newSize;
	this->x = x;
	this->y = y;
	this->color = color;
}

Text::~Text()
{
}

void Text::setPos(int newX, int newY)
{
	x = newX;
	y = newY;
}

int Text::measure()
{
	return MeasureText(text, size);
}

int Text::textSize()
{
	return MeasureText(text, size);
}

void Text::draw()
{
	x = x - (textSize() / 2);

	DrawText(text, x, y, size, color);
}