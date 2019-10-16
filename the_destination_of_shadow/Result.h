#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include <Windows.h>


class RESULT
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
	RESULT::SCENE_PHASE phase = RESULT::LOAD;




private:

	VOID Loading();
	VOID Process();
	VOID Release();


};
#endif
