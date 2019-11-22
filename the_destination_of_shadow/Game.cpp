#include "Game.h"

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
	player_manager.Load();
	real_background.LoadTexture("../Texture/real_background.png", REAL_BACKGROUND);
	shadow_background.LoadTexture("../Texture/shadow_background.png", SHADOW_BACKGROUND);

	phase = PROCESSING;
}

VOID Game::ChangeStage()
{
	switch (current_stage)
	{
	case SHADOW:
		current_stage = REAL;
		break;
	case REAL:
		current_stage = SHADOW;
		break;
	default:
			break;
	}

}

VOID Game::Process()
{
	//一応残してます
	//	player.m_uses_mirror = TRUE;
	//if (fc_cooldown >= 30)
	//{
	//	ChangeStage();
	//	fc_cooldown = 0;
	//}
	//else
	//{
	//	if (fc_cooldown <= 30)
	//	{
	//		fc_cooldown++;
	//	}
	//}

	switch (current_stage)
	{
	case SHADOW:
		real_background.Draw(real_background.texture.GetUvCoordinate(), REAL_BACKGROUND);
		break;
	case REAL:
		shadow_background.Draw(shadow_background.texture.GetUvCoordinate(), SHADOW_BACKGROUND);
		break;
	default:
		break;
	}

	player_manager.Draw();

	player_manager.ModeChange();

	player_manager.Move();

	//仮コード
	if (Xinput::GetInstance()->GetBotton() & XINPUT_GAMEPAD_A)
	{
		phase = RELEASES;
	}
}

//ゲームのテクスチャの解放
VOID Game::Release() 
{
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
