#pragma once
#include "Button.h"
#include "GameSettings.h"
#include "Text.h"

class Credits
{
private:
	Text* title;
	Text* dev1;
	Text* dev2;
	Text* version;
	Button* back;

public:
	Credits();
	~Credits();

	void update(GameSettings* settings);
	void draw();

	void run(GameSettings* settings);
};