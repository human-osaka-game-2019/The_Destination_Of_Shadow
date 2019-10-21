﻿#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include <Windows.h>


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

	VOID Loading();
	VOID Process();
	VOID Release();


};
#endif