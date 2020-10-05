#include "Enemy.h"

/**
* @brief プレイヤー関するクラス
*/
WalkingEnemy::WalkingEnemy()
{
	xinput = Xinput::GetInstance();

	m_hp;
	m_move_speed = 4.0f;
	m_save_direction;

	xy_coordinate.m_x = 0;
	xy_coordinate.m_y = 635.0f;
	xy_coordinate.m_width = 300.0f;
	xy_coordinate.m_height = 300.0f;

	texture.SetAlpha(255);
	texture.SetTu(0.0f);
	texture.SetTv(1.0f / 16.0f);
	texture.SetTuWidth(1.0f / 8.0f);
	texture.SetTvHeight(1.0f / 16.0f);
	texture.SetTextureNum(PLAYER);
}