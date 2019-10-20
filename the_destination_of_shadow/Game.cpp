#include "Game.h"

#include <stdlib.h>
#include <time.h>

#include "Main.h"

Game::SCENE_PAHSE phase = Game::LOAD;


//ゲームのフェーズの移動
VOID Game::Game_Scene()
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

//ゲームのテクスチャの読み込み
VOID Game::Loading()
{


	phase = PROCESSING;
}

VOID Game::Process()
{

	phase = RELEASES;
}

//ゲームのテクスチャの解放
VOID Game::Release() {

	//テクスチャの開放
	for (INT i = 0; i < TEX_MAX; i++)
	{
		if (directx.pTexture[i] != nullptr)
		{
			directx.pTexture[i]->Release();
			directx.pTexture[i] = nullptr;
		}
	}
	//リザルトシーンへ
	scene = RESULT_SCENE;
}