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

Mountain::Mountain()
{
	xy_coordinate.m_x = 0.0f;
	xy_coordinate.m_y = 635.0f;
	xy_coordinate.m_width = 1920.0f;
	xy_coordinate.m_height = 300.0f;

	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(0.25f);
	texture.SetTvHeight(1.0f);
	texture.SetTextureNum(MOUNTAIN);
}

Cloud::Cloud()
{
	xy_coordinate.m_x = 0.0f;
	xy_coordinate.m_y = 0.0f;
	xy_coordinate.m_width = 1920.0f;
	xy_coordinate.m_height = 700.0f;

	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(0.25f);
	texture.SetTvHeight(1.0f);
	texture.SetTextureNum(CLOUD);
}
RealGround::RealGround()
{
	xy_coordinate.m_x = 0.0f;
	xy_coordinate.m_y = 200.0f;
	xy_coordinate.m_width = 1920.0f;
	xy_coordinate.m_height = 900.0f;

	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(0.25f);
	texture.SetTvHeight(1.0f);
	texture.SetTextureNum(REAL_GROUND);
}

ShadowGround::ShadowGround()
{
	xy_coordinate.m_x = 0.0f;
	xy_coordinate.m_y = 196.0f;
	xy_coordinate.m_width = 1920.0f;
	xy_coordinate.m_height = 900.0f;

	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(0.25f);
	texture.SetTvHeight(1.0f);
	texture.SetTextureNum(SHADOW_GROUND);
}
