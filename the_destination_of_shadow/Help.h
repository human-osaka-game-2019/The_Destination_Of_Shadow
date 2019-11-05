#ifndef HELP_SCENE_H
#define HELP_SCENE_H
#include "DirectX.h"
#include "Main.h"
#include "Draw.h"
class Help
{
public:

	VOID Help_Scene();
	enum SCENE_PAHSE
	{
		LOAD,
		PROCESSING,
		RELEASES
	};
	Help::SCENE_PAHSE phase = Help::LOAD;
private:

	VOID Loading();
	VOID Process();
	VOID Release();
};
#endif
