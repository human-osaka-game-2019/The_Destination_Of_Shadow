#include "GameManager.h"

namespace
{
	const INT MAX_ITEMS = 5;
}

GameManager::GameManager()
{
	cursor = nullptr;
	player = new Player();
	InitGimmick();
	xinput = Xinput::GetInstance();
}

GameManager::~GameManager()
{
	delete player;
}

VOID GameManager::InitGimmick()
{
	gimmick.push_back(Gimmick(100, -100, GIMMICK_ID::BUILDING));
	gimmick.push_back(Gimmick(900, -100, GIMMICK_ID::BUILDING));
}

VOID GameManager::Load()
{
	cursor->LoadTexture("../Texture/kari.png", KARI);
	gimmick[0].LoadTexture("../Texture/kari.png", KARI);
	player->LoadTexture("../Texture/player.png", PLAYER);
	//shadow_pouch->LoadTexture();
}

VOID GameManager::Draw()
{
	for (INT i = 0; i < gimmick.size(); i++)
	{
		gimmick[i].Draw(gimmick[i].texture.GetUvCoordinate(), KARI, gimmick[i].texture.GetAlpha());
	}

	player->Draw(player->texture.GetUvCoordinate(), PLAYER, player->texture.GetAlpha());

	if (shadow.empty() == FALSE)
	{
		for (INT i = 0; i < shadow.size(); i++)
		{
			shadow[i].Draw(gimmick[i].texture.GetUvCoordinate(), KARI);
		}
	}

	switch (m_current_mode)
	{
	case PLAYER_MODE::NORMAL:
		break;
	case PLAYER_MODE::SHADOW_BORROW:
		cursor->Draw(cursor->texture.GetUvCoordinate(), KARI);
		break;
	case PLAYER_MODE::SHADOW_USE:
		cursor->Draw(cursor->texture.GetUvCoordinate(), KARI);
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
		SelectShadow();
		cursor = new Cursor(player->GetXyCoordinate(), m_select_shadow.GetXyCoordinate());
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

	if (xinput->IsKeyStrokePushed(VK_PAD_RSHOULDER))
	{

	}

	if (xinput->IsKeyStrokePushed(VK_PAD_RSHOULDER))
	{

	}

	if (xinput->IsKeyStrokePushed(VK_PAD_RTRIGGER))
	{
		m_next_mode = PLAYER_MODE::SHADOW_BORROW;
	}

	//仮キーコンフィグ
	if (xinput->IsKeyStrokePushed(VK_PAD_LTRIGGER))
	{
		if(IsExistShadow())
		m_next_mode = PLAYER_MODE::SHADOW_USE;
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
		ShadowBorrowChacek(gimmick);
		m_next_mode = PLAYER_MODE::NORMAL;
	}
}

VOID GameManager::ShadowUseModeMove()
{
	m_next_mode = PLAYER_MODE::NO_CHANGE;

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

	if (xinput->IsKeyStrokePushed(VK_PAD_RTRIGGER))
	{
		shadow.push_back(Shadow(shadow_items[0].GetXyCoordinate(),cursor->GetXyCoordinate()));
		m_next_mode = PLAYER_MODE::NORMAL;
	}
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

BOOL GameManager::IsHitGimmick(Gimmick gimmick)
{
	FLOAT cursor_width = cursor->GetX() + cursor->GetXWidth();
	FLOAT cursor_height = cursor->GetY() + cursor->GetYHeight();
	FLOAT gimmick_width = gimmick.GetX() + gimmick.GetXWidth();
	FLOAT gimmick_height = gimmick.GetY() + gimmick.GetYHeight();

	if (cursor->GetX() <= gimmick_width && gimmick.GetX() <= cursor_width
		&& cursor->GetY() <= gimmick_height && gimmick.GetY() <= cursor_height)
	{
		return TRUE;
	}

	return FALSE;
}

VOID GameManager::ShadowBorrowChacek(std::vector<Gimmick>&gimmick)
{
	if (shadow_items.size() < MAX_ITEMS)
	{
		for (INT i = 0; i < gimmick.size(); i++)
		{
			if (IsHitGimmick(gimmick[i]))
			{
				if (gimmick[i].GetShadow())
					GetShadow(&gimmick[i]);
			}
		}
	}
}

VOID GameManager::SelectShadow()
{
	if (shadow_items.empty() == FALSE)
	{
		auto itr = shadow_items.begin();
		m_select_shadow = shadow_items[0];
		shadow_items.pop_back();
	}
}

VOID GameManager::GetShadow(Gimmick* gimmick)
{
	gimmick->ChangeShadow();
	ShadowStore(*gimmick);
}

BOOL GameManager::IsExistShadow()
{
	return shadow_items.empty() ? FALSE : TRUE;
}

VOID GameManager::ShadowStore(Gimmick gimmick)
{
	shadow_items.push_back(gimmick);

}
