#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_

#include <vector>

#include "Cursor.h"
#include "Gimmick.h"
#include "Player.h"
#include "Xinput.h"

enum class PLAYER_MODE
{
	NO_CHANGE,
	NORMAL,
	SHADOW_BORROW,
	SHADOW_USE,
};

class GameManager
{
private:

	Xinput* xinput;
	Player* player;
	Cursor* cursor;
	std::vector<Gimmick>gimmick;

	PLAYER_MODE m_next_mode = PLAYER_MODE::NO_CHANGE;

	PLAYER_MODE m_current_mode = PLAYER_MODE::NORMAL;

	VOID NormalModeMove();
	VOID ShadowBorrowModeMove();
	VOID ShadowUseModeMove();

public:

	GameManager();
	virtual ~GameManager();
	VOID Load();
	VOID Draw();
	VOID ModeChange();
	VOID GimmickMove();
	VOID PlayerMove();

};

#endif // !GAME_MANAGER_H_
