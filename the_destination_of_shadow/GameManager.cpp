#include "GameManager.h"

GameManager::GameManager()
{
	xinput = Xinput::GetInstance();
	player = new Player();
	cursor = nullptr;
	gimmick.push_back(Gimmick(100, 500, GIMMICK_ID::BUILDING));
}

GameManager::~GameManager()
{
	delete player;
}

VOID GameManager::Load()
{
	player->LoadTexture("../Texture/player.png", PLAYER);
	cursor->LoadTexture("../Texture/kari.png", KARI);
	gimmick[0].LoadTexture("../Texture/kari.png", KARI);
}

VOID GameManager::Draw()
{
	for (INT i = 0; i < gimmick.size(); i++)
	{
		gimmick[i].Draw(gimmick[i].texture.GetUvCoordinate(), KARI, gimmick[i].texture.GetAlpha());
	}

	player->Draw(player->texture.GetUvCoordinate(), PLAYER, player->texture.GetAlpha());

	switch (m_current_mode)
	{
	case PLAYER_MODE::NORMAL:
		break;
	case PLAYER_MODE::SHADOW_BORROW:
		cursor->Draw(cursor->texture.GetUvCoordinate(), KARI);
		break;
	case PLAYER_MODE::SHADOW_USE:
		break;
	default:
		break;
	}

}

VOID GameManager::ModeChange()
{

	switch (m_next_mode)
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

VOID GameManager::NormalModeMove()
{
	m_next_mode = PLAYER_MODE::NO_CHANGE;

	if (xinput->GetStick(STICK::LEFT_X) >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		player->SetSaveDirection(RIGHT);
		player->Move();
	}

	if (xinput->GetStick(STICK::LEFT_X) <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		player->SetSaveDirection(LEFT);
		player->Move();
	}

	if (xinput->IsKeyStrokePushed(VK_PAD_RTRIGGER))
	{
		m_next_mode = PLAYER_MODE::SHADOW_BORROW;
	}
}

VOID GameManager::ShadowBorrowModeMove()
{
	m_next_mode = PLAYER_MODE::NO_CHANGE;

	if (xinput->GetStick(STICK::LEFT_Y) >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		cursor->SetSaveDirection(CURSOR_DIRECTION::UP);
		cursor->Move();
	}

	if (xinput->GetStick(STICK::LEFT_X) >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		cursor->SetSaveDirection(CURSOR_DIRECTION::RIGHT);
		cursor->Move();
	}

	if (xinput->GetStick(STICK::LEFT_X) <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		cursor->SetSaveDirection(CURSOR_DIRECTION::LEFT);
		cursor->Move();
	}

	if (xinput->GetStick(STICK::LEFT_Y) <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		cursor->SetSaveDirection(CURSOR_DIRECTION::DOWN);
		cursor->Move();
	}

	if (xinput->IsKeyStrokePushed(VK_PAD_RTRIGGER))
	{
		player->ShadowBorrow();
		m_next_mode = PLAYER_MODE::NORMAL;
	}
}

VOID GameManager::ShadowUseModeMove()
{
	m_next_mode = PLAYER_MODE::NO_CHANGE;
}

VOID GameManager::GimmickMove()
{
	for (INT i = 0; i < gimmick.size(); i++)
		gimmick[i].MakeTransparent();
}

VOID GameManager::PlayerMove()
{
	switch (m_current_mode)
	{
	case PLAYER_MODE::NORMAL:
		NormalModeMove();
		break;
	case PLAYER_MODE::SHADOW_BORROW:
		ShadowBorrowModeMove();
		break;
	case PLAYER_MODE::SHADOW_USE:
		ShadowUseModeMove();
		break;
	default:
		break;
	}

	ModeChange();

}
