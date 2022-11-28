#pragma once
class GameSettings
{
private:
public:
	enum Scenes
	{
		Menu,
		Gameplay,
		Credits,
		Controls,
	};

	Scenes curScene;
	bool multiplayer;

	GameSettings();
	~GameSettings();
};