#include "Title.h"

//タイトルのフェーズの宣言
Title::SCENE_PHASE phase = Title::LOAD;

//タイトルのフェーズの移動
VOID Title::Title_Scene()
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

//タイトルのテクスチャの読み込み
VOID Title::Loading()
{
	draw_tex.LoadTexture("../Texture/bird.png", PYON);
	phase = PROCESSING;


}

//タイトルの描画処理
VOID Title::Process()
{
	draw_tex.Draw(0, 0, 0xffffffff, 0.0f, 0.0f, 1920, 1080, 1.0f, 1.0f, PYON);

	//phase = RELEASES;

}

//タイトルのテクスチャの解放
VOID Title::Release()
{

	for (INT i = 0; i < MAX_TEX; i++)
	{
		if (directx.pTexture[i] != nullptr)
		{
			directx.pTexture[i]->Release();
			directx.pTexture[i] = nullptr;
		}
	}
	scene = GAME_SCENE;
}