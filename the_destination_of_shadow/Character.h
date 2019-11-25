﻿#ifndef CHARACTER_H
#define CHARACTER_H

#include"Object.h"
#include"DirectX.h"

/**
* @enum Direction
* キャラクターの向きを管理する
*/

enum DIRECTION
{
	/*! 右を向いている */
	RIGHT,
	/*! 左を向いている */
	LEFT,
};

/**
* @brief PlayerとEnemyの親class
*/
class CharacterBase : public Object
{
protected:

	INT m_hp;
	FLOAT m_move_speed;
	DIRECTION m_save_direction;

public:

	/**
	* @brief キャラクターを動かす
	* @note 各派性クラスにて動作を書く
	*/
	virtual VOID Move() = 0;
};

#endif


