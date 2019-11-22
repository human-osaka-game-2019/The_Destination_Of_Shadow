#include "Cursor.h"

Cursor::Cursor(XyCoordinate player)
{
	xinput = Xinput::GetInstance();

	m_move_speed = 10.0f;

	xy_coordinate.m_x = player.m_x + 100;
	xy_coordinate.m_y = player.m_y + 100;
	xy_coordinate.m_width = 100.0f;
	xy_coordinate.m_height = 100.0f;

	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(1.0f);
	texture.SetTvHeight(1.0f);
	//texture.SetTextureNum();
}

VOID Cursor::SavePosition()
{
	m_save_x = xy_coordinate.m_x;
	m_save_y = xy_coordinate.m_y;
}

VOID Cursor::Move()
{
	SavePosition();

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

	ModifyCoordinates();

}

VOID Cursor::ModifyCoordinates()
{
	if (HitCheckWindowX() == FALSE)
	{
		xy_coordinate.m_x = m_save_x;
	}

	if (HitcheckWindowY() == FALSE)
	{
		xy_coordinate.m_y = m_save_y;
	}
}

BOOL Cursor::HitCheckWindowX()
{
	INT window_x = 0;
	INT window_width = 1920;

	if (xy_coordinate.m_x >= window_x 
		&& xy_coordinate.m_x + xy_coordinate.m_width <= window_width)
	{
		return TRUE;
	}

	return FALSE;
}

BOOL Cursor::HitcheckWindowY()
{
	INT window_y = 0;
	INT window_height = 1080;

	if (xy_coordinate.m_y >= window_y
		&& xy_coordinate.m_y + xy_coordinate.m_height <= window_height)
	{
		return TRUE;
	}

	return FALSE;
}
