#ifndef BLOCK_H
#define BLOCK_H

#include "DirectX.h"
#include "Object.h"

class Block :public Object
{
public:

	/**
	* @brief コンストラクタ
	*/
	Block();

	/**
	* @brief ブロックのスクロール
	*/
	VOID BlockScrol();

	FLOAT m_move_speed = 4;
};

#endif
