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
	NORMAL,
	SHADOW_BORROW,
	SHADOW_USE,
};

class Player : public CharacterBase
{
private:

	Xinput* xinput;

	PLAYER_MODE m_current_mode = PLAYER_MODE::NORMAL;

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
	* @brief m_current_modeのゲット関数
	*/
	inline PLAYER_MODE GetCurrentMode() { return m_current_mode; }
	
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
	* @brief 現在の世界に応じてモードを切り替える関数
	*/
	VOID ModeChange();
	/**
	* @brief 攻撃に関する関数
	*/
	VOID Attack();
	/**
	* @brief NORMAL_MODE時の自機の動作に関する関数
	*/
	VOID BaseMove();
	/**
	* @brief 現在のMODEによって動作を切り替える関数
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
