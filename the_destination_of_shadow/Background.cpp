#include "Main.h"
#include "Background.h"

RealBackground::RealBackground()
{
	xy_coordinate.m_x = 0.0f;
	xy_coordinate.m_y = 0.0f;
	xy_coordinate.m_width = 1920.0f;
	xy_coordinate.m_height = 1080.0f;

	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(1.0f);
	texture.SetTvHeight(1.0f);
	texture.SetTextureNum(REAL_BACKGROUND);
}

ShadowBackground::ShadowBackground()
{
	xy_coordinate.m_x = 0.0f;
	xy_coordinate.m_y = 0.0f;
	xy_coordinate.m_width = 1920.0f;
	xy_coordinate.m_height = 1080.0f;

	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(1.0f);
	texture.SetTvHeight(1.0f);
	texture.SetTextureNum(SHADOW_BACKGROUND);
}
