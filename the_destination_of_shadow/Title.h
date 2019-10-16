#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include <Windows.h>

#include "Main.h"

class TITLE
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
	VOID Loading();
	VOID Process();
	VOID Release();

};

#endif