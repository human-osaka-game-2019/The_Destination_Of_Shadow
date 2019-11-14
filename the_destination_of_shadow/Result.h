#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include <Windows.h>

#include "Main.h"

class Result
{
public:

	VOID Result_Scene();

	enum SCENE_PHASE
	{
		LOAD,
		PROCESSING,
		RELEASES
	};

	//リザルトのフェーズの宣言
	Result::SCENE_PHASE phase = Result::LOAD;

private:

	VOID Load();
	VOID Process();
	VOID Release();


};
#endif
