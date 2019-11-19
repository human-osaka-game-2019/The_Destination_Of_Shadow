/**
* @file Player.h
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Main.h"
#include "Character.h"
#include "Xinput.h"

enum class PLAYER_MODE
{
	NO_CHANGE,
	NORMAL,
	SHADOW_BORROW,
	SHADOW_USE,
};

class Player : public CharacterBase
{
private:

	Xinput* xinput;

	PLAYER_MODE m_next_mode = PLAYER_MODE::NO_CHANGE;

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
	/**
	* @brief m_next_modeのゲット関数
	*/
	inline PLAYER_MODE GetNextMode() { return m_next_mode; }
	
	//! 加速度
	FLOAT m_acceleration;
	//! 歩くスピード
	FLOAT m_work_speed=4.0f;
	//! 最大のスピード
	FLOAT m_max_speed;
	//! 鏡を使用したか
	BOOL m_uses_mirror = FALSE;

	/**
	* @brief コンストラクタ
	*/
	Player();

	~Player() {}
	/**
	* @brief 攻撃に関する関数
	*/
	VOID Attack();
	/**
	* @brief NORMAL_MODE時の自機の動作に関する関数
	*/
	VOID Move();
	/**
	* @brief 影の設置に関する関数
	*/
	VOID ShadowInstallation();
	/**
	* @brief 影を借りる関数
	*/
	VOID ShadowBorrow();
		 
};

#endif
