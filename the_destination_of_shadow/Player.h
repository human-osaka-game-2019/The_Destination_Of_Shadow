/**
* @file Player.h
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Main.h"
#include "Character.h"
#include "Xinput.h"

class Player :public CharacterBase
{
private:

	Xinput* xinput;

public:

	/**
	* @brief m_hpのゲット関数
	*/
	inline INT GetHp() { return m_hp; }
	/**
	* @brief m_move_speedのゲット関数
	*/
	inline FLOAT GetMoveSpeed() { return m_move_speed; }
	/**
	* @brief m_save_directionのゲット関数
	*/
	inline Direction GetSaveDirection() { return m_save_direction; }
	
	//! 加速度
	FLOAT m_acceleration;
	//! 歩くスピード
	FLOAT m_work_speed=4.0f;
	//! 最大のスピード
	FLOAT m_max_speed;

	/**
	* @brief コンストラクタ
	*/
	Player();

	virtual ~Player() {}
	
	/**
	* @brief 攻撃に関する関数
	*/
	VOID Attack();
	/**
	* @brief 自機の移動に関する関数
	*/
	VOID Move();
	/**
	* @brief 影の設置に関する関数
	*/
	VOID ShadowInstallation();
		 
};

#endif
