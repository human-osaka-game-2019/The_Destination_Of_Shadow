#include "Gimmick.h"

Gimmick::Gimmick(FLOAT x, FLOAT y)
{
	xy_coordinate.m_x = x;
	xy_coordinate.m_y = y;
	xy_coordinate.m_width = 300.0f;
	xy_coordinate.m_height = 600.0f;

	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(1.0f);
	texture.SetTvHeight(1.0f);
	texture.SetTextureNum(KARI);
}

VOID Gimmick::MakeTransparent()
{
	INT max_alpha = 255;
	INT half_alpha = 128;

	if (is_shadow == FALSE)
	{
		if (texture.GetAlpha() >= half_alpha)
			texture.SetAlpha(texture.GetAlpha() - 1);
	}
