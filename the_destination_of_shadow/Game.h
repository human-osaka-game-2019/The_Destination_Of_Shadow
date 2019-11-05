#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <Windows.h>

#include "Player.h"

class Game
{
public:

	VOID Game_Scene();

	enum SCENE_PAHSE
	{
		LOAD,
		PROCESSING,
		RELEASES
	};

	Player player;

	Game::SCENE_PAHSE phase = Game::LOAD;

private:

	VOID Loading();
	VOID Process();
	VOID Release();

};
#endif
