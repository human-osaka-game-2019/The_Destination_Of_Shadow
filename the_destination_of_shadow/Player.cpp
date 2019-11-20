#include "Player.h"

Player::Player()
{
	xinput = Xinput::GetInstance();

	m_hp;
	m_move_speed =4.0f;
	m_save_direction;
	
	xy_coordinate.m_x = 0;
	xy_coordinate.m_y = 780.0f;
	xy_coordinate.m_width = 300.0f;
	xy_coordinate.m_height = 300.0f;

	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(1.0f);
	texture.SetTvHeight(1.0f);
	texture.SetTextureNum(PLAYER);

}

VOID Player::ModeChange()
{
	switch (m_current_mode)
	{
	case PLAYER_MODE::NORMAL:
		break;
	case PLAYER_MODE::SHADOW_BORROW:
		m_current_mode = PLAYER_MODE::NORMAL;
		break;
	case PLAYER_MODE::SHADOW_USE:
		m_current_mode = PLAYER_MODE::NORMAL;
		break;
	default:
		break;
	}
}

VOID Player::Attack()
{
	return VOID();
}

VOID Player::ShadowInstallation()
{
	return VOID();
}

VOID Player::BaseMove()
{
	if (xinput->GetStick(STICK::LEFT_X)>= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		m_save_direction = Right;
		xy_coordinate.m_x += m_move_speed;

	}

	if (xinput->GetStick(STICK::LEFT_X) <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		m_save_direction = Left;
		xy_coordinate.m_x -= m_move_speed;

	}

	if (xinput->IsKeyStrokePushed(VK_PAD_RTRIGGER))
	{
		ModeChange();
	}

	switch (m_save_direction)
	{
	case Right:
		texture.SetTuWidth(-1.0f);
		break;
	case Left:
		texture.SetTuWidth(1.0f);
		break;
	default:
		break;
	}
}

VOID Player::ShadowBorrow()
{
	if (xinput->IsKeyStrokePushed(VK_PAD_RTRIGGER))
	{
		m_current_mode = PLAYER_MODE::NORMAL;
	}
}
