#include "Gimmick.h"

Gimmick::Gimmick(FLOAT x,FLOAT y,GIMMICK_ID id)
{
	switch (id)
	{
	case GIMMICK_ID::NO_ID:
		break;
	case GIMMICK_ID::BUILDING:
		InitBuilding(x, y);
		break;
	default:
		break;
	}
}

VOID Gimmick::InitBuilding(FLOAT x, FLOAT y)
{
	xy_coordinate.m_x = x;
	xy_coordinate.m_y = y;

	//初期化の値は適当
	xy_coordinate.m_width = 500;
	xy_coordinate.m_height = 600;

	texture.SetAlpha(255);

	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(1.0f);
	texture.SetTvHeight(1.0f);
}

VOID Gimmick::ChangeShadow()
{
	if (m_is_shadow)
		m_is_shadow = FALSE;
}

VOID Gimmick::MakeTransparent()
{
	INT half_alpha = 128;

	if (m_is_shadow == FALSE)
	{
		if (texture.GetAlpha() >= half_alpha)
			texture.SetAlpha(texture.GetAlpha() - 1);
	}
}
