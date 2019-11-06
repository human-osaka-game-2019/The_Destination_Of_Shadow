#include "Result.h"

#include "Main.h"
#include"Game.h"



//リザルトのフェーズの移動
VOID Result::Result_Scene()
{

	switch (phase)
	{
	case LOAD:
		Load();
		break;
	case PROCESSING:
		Process();
		break;
	case RELEASES:
		Release();
		phase = LOAD;

		break;
	}
}

//リザルトのテクスチャの読み込み
VOID Result::Load()
{

	phase = PROCESSING;
}

//リザルトの描画処理
VOID Result::Process()
{
	phase = RELEASES;
}


//リザルトのテクスチャの解放
VOID Result::Release()
{

	for (INT i = 0; i < MAX_TEX; i++)
	{
		if (directx.pTexture[i] != nullptr)
		{
			directx.pTexture[i]->Release();
			directx.pTexture[i] = nullptr;
		}
	}
	scene = TITLE_SCENE;
}

