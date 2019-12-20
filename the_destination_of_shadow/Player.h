/**
* @file Player.h
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public CharacterBase
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
	inline DIRECTION GetSaveDirection() { return m_save_direction; }
	/**
	* @brief m_save_directionのセット関数
	* @direction playerの方向
	*/
	inline VOID SetSaveDirection(DIRECTION direction) { m_save_direction = direction; }
	
	//! 加速度
	FLOAT m_acceleration;
	//! 歩くスピード
	FLOAT m_work_speed = 4.0f;
	//! 最大のスピード
	FLOAT m_max_speed;
	//! 鏡を使用したか
	BOOL m_uses_mirror = FALSE;
	//! 移動数カウント
	FLOAT m_move_count = 4.0f;
	//! ジャンプ
	FLOAT fc_jump = 0.0f;

	const FLOAT JUMP_POWER = 50.0f;
	const FLOAT GRAVITY = 2.0f;
	FLOAT m_crrent_jump_power = 0.0f;
	FLOAT m_gravity = GRAVITY;
	BOOL m_is_jumping = FALSE;

	VOID JumpStart();
	VOID Jump();
	VOID JumpEnd();

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
	//VOID ShadowBorrow();

	/**
	* @brief m_save_directionのゲット関数
	*/
	inline FLOAT GetSaveTu() { return texture.GetTu(); }
	/**
	* @brief m_save_tuのセット関数
	* @param save_tu
	*/
	inline VOID SetSaveTu(FLOAT save_tu) { texture.SetTu(save_tu); }
	inline VOID SetSaveTv(FLOAT save_tv) { texture.SetTu(save_tv); }
	/**
	* @brief m_save_tuに任意の値を足すセット関数
	* @param plus_value
	*/
	inline VOID SetPlusTu(FLOAT plus_value) { texture.SetTu(texture.GetTu() + plus_value); }
	inline VOID SetPlusTv(FLOAT plus_value) { texture.SetTv(texture.GetTv() + plus_value); }
	/**
	* @brief m_save_tuに任意の値を引くセット関数
	* @param minus_value
	*/
	inline VOID SetMinusTu(FLOAT minus_value) { texture.SetTu(texture.GetTu() - minus_value); }

	AnimetionTu* Idle_tu = new AnimetionTu(0.0f, (1.0f / 6.0) * 3);
	AnimetionTv* Idle_tv = new AnimetionTv(0.0f, 1.0f / 16.0f);
	AnimetionCount* Idle_count = new AnimetionCount(0, 6);
};

#endif
