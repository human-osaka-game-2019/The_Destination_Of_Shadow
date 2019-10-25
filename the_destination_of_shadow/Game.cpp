#include "Game.h"

#include <stdlib.h>
#include <time.h>

#include "Main.h"
#include "Player.h"

Game::SCENE_PAHSE phase = Game::LOAD;

extern Player player;

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
	draw_tex.LoadTexture("../Texture/sky.png", SKY);
	draw_tex.LoadTexture("../Texture/cloud.png", CLOUD);
	draw_tex.LoadTexture("../Texture/cloud02.png", CLOUD02);
	draw_tex.LoadTexture("../Texture/cloud03.png", CLOUD03);
	draw_tex.LoadTexture("../Texture/player.png", PLAYER);

	phase = PROCESSING;
}

PlayerInfo player_info
{
	PLAYER,0,780,300,300,0.0f,0.0f,1.0f,1.0f
};

VOID Game::Process()
{
	directx.UpdateControllerState();

	draw_tex.Draw(0, 0, 0xffffffff, 0.0f, 0.0f, 1920, 1080, 1.0f, 1.0f, SKY);
	draw_tex.Draw(0, 0, 0xffffffff, 0.0f, 0.0f, 600, 300, 1.0f, 1.0f, CLOUD);
	draw_tex.Draw(600, 0, 0xffffffff, 0.0f, 0.0f, 600, 300, 1.0f, 1.0f, CLOUD02);
	draw_tex.Draw(1200, 0, 0xffffffff, 0.0f, 0.0f, 600, 300, 1.0f, 1.0f, CLOUD03);
	draw_tex.Draw(player_info.x, player_info.y, 0xffffffff, player_info.tu, player_info.tv, player_info.x_width, player_info.y_height, player_info.tu_width, player_info.tv_height, player_info.TEX);

	player.Move(&player_info.x,&player);




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