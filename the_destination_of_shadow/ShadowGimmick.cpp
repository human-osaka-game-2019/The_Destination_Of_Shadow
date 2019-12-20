#include"ShadowGimmick.h"

ShadowGimmick::ShadowGimmick(FLOAT x, FLOAT y, SHADOW_GIMMICK_ID id) : m_id(id)
{
	xy_coordinate.m_x = x;
	xy_coordinate.m_y = y;

	switch (id)
	{
	case SHADOW_GIMMICK_ID::BOTTON:
		InitBotton();
		break;
	case SHADOW_GIMMICK_ID::DOOR:
		InitDoor();
		break;
	default:
		break;
	}
}

VOID ShadowGimmick::GimmickSettl()
{
	m_is_settled = TRUE;
}

BOOL ShadowGimmick::IsHitCursor(XyCoordinate cursor)
{
	FLOAT cursor_width = cursor.m_x + cursor.m_width;
	FLOAT cursor_height = cursor.m_y + cursor.m_height;
	FLOAT gimmick_width = xy_coordinate.m_x + xy_coordinate.m_width;
	FLOAT gimmick_height = xy_coordinate.m_y + xy_coordinate.m_height;

	if (cursor.m_x <= gimmick_width && xy_coordinate.m_x <= cursor_width
		&& cursor.m_y <= gimmick_height && xy_coordinate.m_y <= cursor_height)
	{
		return TRUE;
	}

	return FALSE;
}

BOOL ShadowGimmick::IsSettledBoton()
{
	if (m_is_settled)
		return TRUE;

	return FALSE;
}

VOID ShadowGimmick::InitBotton()
{
	xy_coordinate.m_width = 200;
	xy_coordinate.m_height = 200;

	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(1.0f);
	texture.SetTvHeight(1.0f);
}

VOID ShadowGimmick::InitDoor()
{
	xy_coordinate.m_width = 400;
	xy_coordinate.m_height = 1000;

	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(1.0f);
	texture.SetTvHeight(1.0f);
}
