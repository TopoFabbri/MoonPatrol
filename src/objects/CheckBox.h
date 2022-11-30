#pragma once

#include <raylib.h>

namespace Topo
{
	class CheckBox
	{
	public:
		const char* txt;
		Rectangle rec;
		bool checked;
		Color out;
		Color empty;
		Color fill;

		CheckBox();
		~CheckBox();

		void draw();
	};
}