#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include <Windows.h>

#include "Main.h"

class Title
{
public:

	VOID Title_Scene();

	enum SCENE_PHASE
	{
		LOAD,
		PROCESSING,
		RELEASES
	};

private:

	SCENE nextscene = GAME_SCENE;

	//プロトタイプ宣言
	VOID Load();
	VOID Process();
	VOID Release();

};

#endif