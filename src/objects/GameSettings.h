#pragma once
class GameSettings
{
private:
public:
	enum Scenes
	{
		Menu,
		Gameplay,
		Credits
	};

	Scenes curScene;
	bool multiplayer;

	GameSettings();
	~GameSettings();
};