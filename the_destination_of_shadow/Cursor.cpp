#include "Cursor.h"

Cursor::Cursor(XyCoordinate player)
{

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

Cursor::Cursor(XyCoordinate player, XyCoordinate gimmick)
{

	m_move_speed = 10.0f;
	xy_coordinate.m_width = gimmick.m_width;
	xy_coordinate.m_height = gimmick.m_height;
	xy_coordinate.m_x = player.m_x;
	xy_coordinate.m_y = (player.m_y + player.m_height) - xy_coordinate.m_height;

	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(1.0f);
	texture.SetTvHeight(1.0f);
}

VOID Cursor::SavePosition()
{
	m_save_x = xy_coordinate.m_x;
	m_save_y = xy_coordinate.m_y;
}

VOID Cursor::Move()
{
	SavePosition();

	switch (m_save_direction)
	{
	case CURSOR_DIRECTION::NO:
		break;
	case CURSOR_DIRECTION::UP:
		xy_coordinate.m_y -= m_move_speed;
		break;
	case CURSOR_DIRECTION::RIGHT:
		xy_coordinate.m_x += m_move_speed;
		break;
	case CURSOR_DIRECTION::LEFT:
		xy_coordinate.m_x -= m_move_speed;
		break;
	case CURSOR_DIRECTION::DOWN:
		xy_coordinate.m_y += m_move_speed;
		break;
	default:
		break;
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
