#include "Help.h"
#include <time.h>
//リザルトのフェーズの移動
VOID Help::Help_Scene()
{
	switch (phase)
	{
	case LOAD:
		Loading();
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
VOID Help::Loading()
{
	phase = PROCESSING;
}
//リザルトの描画処理
VOID Help::Process()
{
	phase = RELEASES;

}
//リザルトのテクスチャの解放
VOID Help::Release()
{
	for (INT i = 0; i < MAX_TEX; i++)
	{
		if (directx.pTexture[i] != nullptr)
		{
			directx.pTexture[i]->Release();
			directx.pTexture[i] = nullptr;
		}
	}
	phase = LOAD;
	scene = TITLE_SCENE;
}