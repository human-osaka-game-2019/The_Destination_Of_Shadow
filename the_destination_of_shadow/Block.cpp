#include "Block.h"
#include "Main.h"

Block::Block()
{
	xy_coordinate.m_x = 1920.0f;
	xy_coordinate.m_y = 590.0f;
	xy_coordinate.m_width = 150.0f;
	xy_coordinate.m_height = 150.0f;

	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(1.0f);
	texture.SetTvHeight(1.0f);
	texture.SetTextureNum(SHADOW_BLOCK);
}

VOID Block::BlockScrol()
{
	xy_coordinate.m_x += m_move_speed;
}
