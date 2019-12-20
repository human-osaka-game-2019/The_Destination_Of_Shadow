#include "Player.h"

VOID Player::Attack()
{
	return VOID();
}

VOID Player::ShadowInstallation()
{
	return VOID();
}

/**
* @brief プレイヤー関するクラス
*/
Player::Player()
{
	m_hp;
	m_move_speed = 4.0f;
	m_save_direction;

	xy_coordinate.m_x = 0;
	xy_coordinate.m_y = 635.0f;
	xy_coordinate.m_width = 300.0f;
	xy_coordinate.m_height = 300.0f;

	texture.SetAlpha(255);
	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(1.0f/8.0f);
	texture.SetTvHeight(1.0f/16.0f);
	texture.SetTextureNum(PLAYER);
}

VOID Player::Move()
{
	/*switch (m_save_direction)
	{
	case RIGHT:
		xy_coordinate.m_x += m_move_speed;
		m_move_count += m_move_speed;
		break;
	case LEFT:
		xy_coordinate.m_x -= m_move_speed;
		break;
	}
	switch (m_save_direction)
	{
	case RIGHT:
		texture.SetTuWidth(-1.0f);
		break;
	case LEFT:
		texture.SetTuWidth(1.0f);
		break;
	default:
		break;
	}*/
}

VOID Player::JumpStart()
{
	m_is_jumping = TRUE;
	m_crrent_jump_power = JUMP_POWER;
}
VOID Player::Jump()
{
	if (m_is_jumping)
	{
		m_crrent_jump_power -= m_gravity;
		xy_coordinate.m_y -= m_crrent_jump_power;
		//仮
		if (xy_coordinate.m_y + xy_coordinate.m_height >= 970)
		{
			xy_coordinate.m_y = 635;
			JumpEnd();
		}
	}
}
VOID Player::JumpEnd()
{
	m_is_jumping = FALSE;
	m_crrent_jump_power = 0.0f;
}