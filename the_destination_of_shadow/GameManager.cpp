#include "GameManager.h"

GameManager::GameManager()
{
	xinput = Xinput::GetInstance();
	player = new Player();
	cursor = nullptr;
	stage = new Stage();
	gimmick.push_back(Gimmick(600, 330, GIMMICK_ID::BUILDING));
}

GameManager::~GameManager()
{
	delete player;
}

VOID GameManager::Load()
{
	player->LoadTexture("../Texture/player.png", PLAYER);
	cursor->LoadTexture("../Texture/cursor.png", CURSOR);
	gimmick[0].LoadTexture("../Texture/kari.png", KARI);

	stage->real_background.LoadTexture("../Texture/real_background.jpg", REAL_BACKGROUND);
	stage->shadow_background.LoadTexture("../Texture/shadow_background.jpg", SHADOW_BACKGROUND);
	stage->mountain->LoadTexture("../Texture/mountain.png", MOUNTAIN);
	stage->cloud->LoadTexture("../Texture/cloud.png", CLOUD);
	stage->real_ground->LoadTexture("../Texture/real_ground.png", REAL_GROUND);
	stage->shadow_ground->LoadTexture("../Texture/shadow_ground.png", SHADOW_GROUND);
}

VOID GameManager::Draw()
{
	switch (stage->current_stage)
	{
	case Stage::CurrentStage::SHADOW:
		stage->real_background.Draw(stage->real_background.texture.GetUvCoordinate(), REAL_BACKGROUND);
		stage->mountain->Draw(stage->mountain->texture.GetUvCoordinate(), MOUNTAIN);
		stage->cloud->Draw(stage->cloud->texture.GetUvCoordinate(), CLOUD);
		stage->real_ground->Draw(stage->real_ground->texture.GetUvCoordinate(), REAL_GROUND);

		if (xinput->IsKeyStrokePushed(VK_PAD_Y))
		{
			stage->current_stage = Stage::CurrentStage::REAL;
		}

		break;
	case Stage::CurrentStage::REAL:
		stage->shadow_background.Draw(stage->shadow_background.texture.GetUvCoordinate(), SHADOW_BACKGROUND);
		stage->shadow_ground->Draw(stage->real_ground->texture.GetUvCoordinate(), SHADOW_GROUND);

		if (xinput->IsKeyStrokePushed(VK_PAD_Y))
		{
			stage->current_stage = Stage::CurrentStage::SHADOW;
		}

	default:
		break;
	}
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
		cursor->Draw(cursor->texture.GetUvCoordinate(), CURSOR);
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
	player->Animetion(&player->Idle_count->fc_animetion_type, player->Idle_count->m_count, &player->texture.GetUvCoordinate(), player->Idle_tu->m_start, player->Idle_tv->m_start, player->Idle_tu->m_finish, player->Idle_tv->m_finish);
	m_next_mode = PLAYER_MODE::NO_CHANGE;

	if (xinput->IsKeyStrokePushed(VK_PAD_A))
	{
		player->JumpStart();
	}

	if (xinput->GetStick(STICK::LEFT_X) >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		player->SetSaveDirection(LR_Direction::RIGHT);
		player->Move();
		Scroll(player->GetSaveDirection());
	}

	if (xinput->GetStick(STICK::LEFT_X) <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		player->SetSaveDirection(LR_Direction::LEFT);
		player->Move();
		Scroll(player->GetSaveDirection());
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
		ShadowBorrowChacek(gimmick);
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

	player->Jump();

	CameraMove(player->GetSaveDirection());

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
	for (INT i = 0; i < gimmick.size(); i++)
	{
		if (IsHitGimmick(gimmick[i]))
		{
			if (gimmick[i].GetShadow())
			{
				GetShadow(&gimmick[i]);
			}
		}
	}
}

VOID GameManager::GetShadow(Gimmick* gimmick)
{
	gimmick->ChangeShadow();
}

VOID GameManager::Scroll(LR_Direction direction)
{
	stage->MountainScroll(direction);
	stage->CloudScroll(direction);
	stage->RealGroundScroll(direction);

	for (INT i = 0; i < gimmick.size(); i++)
	{
		gimmick[i].ObjScroll(direction);
	}

	//if (shadow.empty() == FALSE)
	//{
	//	for (INT i = 0; i < shadow.size(); i++)
	//	{
	//		shadow[i].ObjScroll(direction);
	//	}
	//}
}

VOID GameManager::CameraMove(LR_Direction direction)
{
	for (INT i = 0; i < gimmick.size(); i++)
	{
		gimmick[i].CameraScroll(direction);
	}

	//if (shadow.empty() == FALSE)
	//{
	//	for (INT i = 0; i < shadow.size(); i++)
	//	{
	//		shadow[i].CameraScroll(direction);
	//	}
	//}

	player->CameraScroll(direction);
}
