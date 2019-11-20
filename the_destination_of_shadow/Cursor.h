#ifndef CURSOR_H_
#define CURSOR_H_

#include "Object.h"
#include "Xinput.h"

class Cursor : public Object
{
private:

	Xinput* xinput;

	FLOAT m_move_speed;

public:

	virtual ~Cursor() {}
	/**
	* @brief プレイヤーの前に描画されるように初期化する用
	*/
	Cursor(XyCoordinate player);
	/**
	* @brief カーソル移動関数
	*/
	VOID Move();
};

#endif // !CURSOR_H_
