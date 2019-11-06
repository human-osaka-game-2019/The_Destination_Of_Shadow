#ifndef CHARACTER_H
#define CHARACTER_H

#include"DirectX.h"
#include"Object.h"

/**
* @enum Direction
* キャラクターの向きを管理する
*/

enum Direction
{
	/*! 右を向いている */
	Right,
	/*! 左を向いている */
	Left,
};

/**
* @brief PlayerとEnemyの親class
*/
class CharacterBase : public Object
{
protected:

	INT m_hp;
	FLOAT m_move_speed;
	Direction m_save_direction;

public:

	/**
	* @brief キャラクターの動作、エネミーならAI、プレイヤーなら動作に関する処理を書く
	*/
	virtual VOID Move() = 0;
};

#endif


