#ifndef HELP_SCENE_H
#define HELP_SCENE_H
#include "DirectX.h"
#include "Main.h"
#include "Draw.h"
class HELP
{
public:

	VOID Help_Scene();
	enum SCENE_PAHSE
	{
		LOAD,
		PROCESSING,
		RELEASES
	};
	HELP::SCENE_PAHSE phase = HELP::LOAD;
private:
	VOID Loading();
	VOID Process();
	VOID Release();
};
#endif
