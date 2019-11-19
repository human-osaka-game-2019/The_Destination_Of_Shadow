#include "Cursor.h"

Cursor::Cursor(XyCoordinate player)
{
	xinput = Xinput::GetInstance();

	m_move_speed = 4.0f;

	xy_coordinate.m_x = player.m_x + 100;
	xy_coordinate.m_y = player.m_y + 200;
	xy_coordinate.m_width = 400.0f;
	xy_coordinate.m_height = 400.0f;

	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(1.0f);
	texture.SetTvHeight(1.0f);
	//texture.SetTextureNum();
}

VOID Cursor::Move()
{
	if (xinput->GetStick(STICK::LEFT_X) >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		xy_coordinate.m_x += m_move_speed;
	}

	if (xinput->GetStick(STICK::LEFT_X) <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		xy_coordinate.m_x -= m_move_speed;
	}

	if (xinput->GetStick(STICK::LEFT_Y) >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		xy_coordinate.m_y -= m_move_speed;
	}

	if (xinput->GetStick(STICK::LEFT_Y) <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		xy_coordinate.m_y += m_move_speed;
	}
}
