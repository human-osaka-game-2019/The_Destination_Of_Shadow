/**
* @file Game.h
*/

#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <Windows.h>

#include "Main.h"
#include "Stage.h"
#include "Player.h"

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

	Player player;
	Stage stage;

	VOID Load();
	VOID Process();
	VOID Release();

public:

	VOID Game_Scene();
	Game::SCENE_PAHSE phase = Game::LOAD;

	inline INT GetCoolDown() { return stage.fc_cooldown; }
	inline Stage::CurrentStage GetCurrentStage() { return stage.current_stage; }
};
#endif
