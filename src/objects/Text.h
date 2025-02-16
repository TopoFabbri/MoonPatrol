#pragma once

#include "Topo.h"

namespace Topo
{
	class Text
	{
	public:
		const char* text;
		int size;
		int x;
		int y;

		Color color;

		Text(const char* newText, int newSize, int x, int y, Color color);
		~Text();

		void setPos(int x, int y);
		int measure();
		int textSize();
		void draw();
	};
}