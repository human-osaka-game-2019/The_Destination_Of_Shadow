#ifndef CHARACTER_H
#define CHARACTER_H

#include"DirectX.h"

enum Direction
{
	Right,
	Left,
};

class CHARACTER_BASE 
{
protected:
	INT m_hp;
	FLOAT m_move_speed;
	Direction m_save_direction;

	TEX m_TEX;

	FLOAT m_x;
	FLOAT m_y;
	FLOAT m_x_width;
	FLOAT m_y_height;

	FLOAT m_tu;
	FLOAT m_tv;
	FLOAT m_tu_width;
	FLOAT m_tv_height;

public:
	virtual VOID Move()=0;
};

#endif

