#include <stdlib.h>
#include <time.h>

#include "Game.h"
#include "Main.h"

//ゲームのフェーズの移動
VOID Game::Game_Scene()
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

//ゲームのテクスチャの読み込み
VOID Game::Load()
{

	player.LoadTexture("../Texture/player.png", PLAYER);

	phase = PROCESSING;
}


VOID Game::Process()
{
	directx.UpdateControllerState();

	player.Draw(player.texture.GetUvCoordinate(),PLAYER);

	player.Move();

	if (directx.XinputState.Gamepad.wButtons & XINPUT_GAMEPAD_A)
	{
		phase = RELEASES;
	}
}

//ゲームのテクスチャの解放
VOID Game::Release() {

	//テクスチャの開放
	for (INT i = 0; i < MAX_TEX; i++)
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