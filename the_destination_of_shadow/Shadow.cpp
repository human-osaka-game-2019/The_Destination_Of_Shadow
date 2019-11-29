#include "Shadow.h"

Shadow::Shadow(XyCoordinate gimmick,XyCoordinate cursor)
{
	xy_coordinate.m_x = cursor.m_x;
	xy_coordinate.m_y = cursor.m_y;
	xy_coordinate.m_width = gimmick.m_width;
	xy_coordinate.m_height = gimmick.m_height;

	texture.SetTu(0.0f);
	texture.SetTv(0.0f);
	texture.SetTuWidth(1.0f);
	texture.SetTvHeight(1.0f);
}