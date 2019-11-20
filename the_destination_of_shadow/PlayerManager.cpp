#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
	player = new Player();
}

VOID PlayerManager::Move()
{
	switch (player->GetCurrentMode())
	{
	case PLAYER_MODE::NORMAL:
		player->BaseMove();
		break;
	case PLAYER_MODE::SHADOW_BORROW:
		cursor->CursorMove();
		break;
	case PLAYER_MODE::SHADOW_USE:
		break;
	default:
		break;
	}


}
