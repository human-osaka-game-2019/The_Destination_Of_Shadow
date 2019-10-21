#include "Main.h"
#include "Player.h"


namespace
{
	//! Xboxコントローラー左スティックのデットゾーン
	const FLOAT DEAD_ZONE_LEFT = 7849;

	//! Xboxコントローラー右スティックのデットゾーン
	const FLOAT DEAD_ZONE_RIGHT = 8689;
}

VOID Player::Attack()
{
	return VOID();
}

VOID Player::ShadowInstallation()
{
	return VOID();
}

Player::Player()
{

	m_hp;
	m_move_speed = 4.0f;
	m_save_direction;

	m_tex = PLAYER;
	
	m_x = 0;
	m_y = 780.0f;
	m_x_width = 300.0f;
	m_y_height = 300.0f;

	m_tu = 0.0f;
	m_tv = 0.0f;
	m_tu_width = 1.0f;
	m_tv_height = 1.0f;

}

VOID Player::Move()
{

	
	if (directx.XinputState.Gamepad.sThumbLX >= DEAD_ZONE_RIGHT)
	{
		m_save_direction = Right;
		m_x += m_move_speed;

	}

	else if (directx.XinputState.Gamepad.sThumbLX <= -DEAD_ZONE_LEFT)
	{
		m_save_direction = Left;
		m_x -= m_move_speed;

	}

	switch (m_save_direction)
	{
	case Right:
		m_tu_width = -1.0;
		break;
	case Left:
		m_tu_width = 1.0;
		break;
	default:
		break;
	}


}


