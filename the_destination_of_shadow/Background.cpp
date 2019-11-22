#include "Background.h"

#include "Main.h"

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

Mountain::Mountain()
{
	xy_coordinate.m_x = 0.0f;
	xy_coordinate.m_y = 680.0f;
	xy_coordinate.m_width = 1920.0f;
	xy_coordinate.m_height = 300.0f;

	texture.SetTu(save_tu);
	texture.SetTv(0.0f);
	texture.SetTuWidth(0.25f);
	texture.SetTvHeight(1.0f);
	texture.SetTextureNum(MOUNTAIN);
}

VOID Mountain::Scroll()
{
	if (Xinput::GetInstance()->GetStick(STICK::LEFT_X) >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		texture.SetTu(save_tu += 0.001);
		if (save_tu >= 1.0f)
		{
			save_tu = 0.0f;
		}
	}
	else if (Xinput::GetInstance()->GetStick(STICK::LEFT_X) <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		texture.SetTu(save_tu -= 0.001);
		if (save_tu <= -1.0f)
		{
			save_tu = 0.0f;
		}
	}
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
