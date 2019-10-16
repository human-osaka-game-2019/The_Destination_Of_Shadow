#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <Windows.h>

class GAME
{
public:


	VOID Game_Scene();

	VOID Loading();
	VOID Process();
	VOID Release();

	enum SCENE_PAHSE
	{
		LOAD,
		PROCESSING,
		RELEASES
	};

};
#endif
