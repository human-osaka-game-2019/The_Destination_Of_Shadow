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
	game_manager.Load();
	/*stage.real_background.LoadTexture("../Texture/real_background.png", REAL_BACKGROUND);
	stage.shadow_background.LoadTexture("../Texture/shadow_background.png", SHADOW_BACKGROUND);
	stage.mountain.LoadTexture("../Texture/mountain.png", MOUNTAIN);*/

	phase = PROCESSING;
}

//VOID Game::ChangeStage()
//{
//	switch (stage.current_stage)
//	{
//	case Stage::CurrentStage::SHADOW:
//		stage.current_stage = Stage::CurrentStage::REAL;
//		break;
//	case Stage::CurrentStage::REAL:
//		stage.current_stage = Stage::CurrentStage::SHADOW;
//		break;
//	default:
//			break;
//	}
//
//}

VOID Game::Process()
{

	game_manager.Draw();

	game_manager.PlayerMove();

	game_manager.GimmickMove();

	//仮コード
	if (Xinput::GetInstance()->GetBotton() & XINPUT_GAMEPAD_Y)
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
