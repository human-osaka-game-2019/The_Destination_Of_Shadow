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
	xinput = Xinput::GetInstance();

	m_hp;
	m_move_speed = 4.0f;
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

VOID Player::Move()
{
	switch (current_mode)
	{
	case MODE::NORMAL:
		BaseMove();
		break;
	case MODE::SHADOW_BORROW:
		//ShadowBorrow();
		break;
	case MODE::SHADOW_USE:
		ShadowInstallation();
		break;
	default:
		break;
	}
}

VOID Player::BaseMove()
{

	if (xinput->GetStick(STICK::LEFT_X) >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		m_save_direction = Right;
		xy_coordinate.m_x += m_move_speed;
	}

	else if (xinput->GetStick(STICK::LEFT_X) <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		m_save_direction = Left;
		xy_coordinate.m_x -= m_move_speed;
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
