#pragma once
class GameManager
{
public:
	enum GameState {
		RUNNING,
		GAMEOVER
	};
	GameState state;
	GameManager() = default;
};