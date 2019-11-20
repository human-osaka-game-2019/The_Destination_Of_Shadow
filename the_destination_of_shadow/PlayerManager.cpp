#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
	player = new Player();
}

PlayerManager::~PlayerManager()
{
	delete player;
}

VOID PlayerManager::Load()
{
	player->LoadTexture("../Texture/player.png", PLAYER);
}

VOID PlayerManager::Draw()
{
	player->Draw(player->texture.GetUvCoordinate(), PLAYER);

	switch (m_current_mode)
	{
	case PLAYER_MODE::NORMAL:
		break;
	case PLAYER_MODE::SHADOW_BORROW:
		break;
	case PLAYER_MODE::SHADOW_USE:
		break;
	}
}

VOID PlayerManager::ModeChange()
{
	switch (player->GetNextMode())
	{
	case PLAYER_MODE::NO_CHANGE:
		break;
	case PLAYER_MODE::NORMAL:
		delete cursor;
		m_current_mode = PLAYER_MODE::NORMAL;
		break;
	case PLAYER_MODE::SHADOW_BORROW:
		cursor = new Cursor(player->GetXyCoordinate());
		m_current_mode = PLAYER_MODE::SHADOW_BORROW;
		break;
	case PLAYER_MODE::SHADOW_USE:
		m_current_mode = PLAYER_MODE::SHADOW_USE;
		break;
	default:
		break;
	}
}

VOID PlayerManager::Move()
{
	switch (m_current_mode)
	{
	case PLAYER_MODE::NORMAL:
		player->Move();
		break;
	case PLAYER_MODE::SHADOW_BORROW:
		player->ShadowBorrow();
		cursor->Move();
		break;
	case PLAYER_MODE::SHADOW_USE:
		break;
	default:
		break;
	}
}
