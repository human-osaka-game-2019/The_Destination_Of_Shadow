#include "Gimmick.h"

Gimmick::Gimmick()
{
	
}

Gimmick::Gimmick(FLOAT x,FLOAT y,GIMMICK_ID id)
{

	xy_coordinate.m_x = x;
	xy_coordinate.m_y = y;

	texture.SetAlpha(255);

	switch (id)
	{
	case GIMMICK_ID::NO_ID:
		break;
	case GIMMICK_ID::BUILDING:
		InitBuilding();
		break;
	default:
		break;
	}
}

VOID Gimmick::InitBuilding()
{
	//初期化の値は適当
	xy_coordinate.m_width = 750;
	xy_coordinate.m_height = 1200;

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