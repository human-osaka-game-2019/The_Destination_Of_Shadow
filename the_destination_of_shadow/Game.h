/**
* @file Game.h
*/

#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <Windows.h>

#include "Background.h"
#include "Main.h"
#include "GameManager.h"

class Game
{
private:

	/**
	* @brief 影の世界と現実世界を切り替える関数
	*/
	VOID ChangeStage();

	enum SCENE_PAHSE
	{
		LOAD,
		PROCESSING,
		RELEASES
	};
	
	/**
	* @enum CurrentStage
	* 現在どのステージにいるかの判定
	*/
	enum CurrentStage
	{
		SHADOW,
		REAL
	};
	CurrentStage current_stage;

	//! 遷移のクールタイム
	INT fc_cooldown = 30;

	GameManager game_manager;
	RealBackground real_background;
	ShadowBackground shadow_background;

	VOID Load();
	VOID Process();
	VOID Release();

public:

	VOID Game_Scene();
	Game::SCENE_PAHSE phase = Game::LOAD;
};
#endif
