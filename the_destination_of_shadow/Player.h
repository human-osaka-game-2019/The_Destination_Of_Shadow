/**
* @file Player.h
*/


#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "DirectX.h"

class Player :public CharacterBase
{
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
	* @brief m_texのゲット関数
	*/
	inline TEX GetTex() { return m_tex; }

	/**
	* @brief m_xのゲット関数
	*/
	inline FLOAT GetX() { return m_x; }
	/**
	* @brief m_yのゲット関数
	*/
	inline FLOAT GetY() { return m_y; }
	/**
	* @brief m_x_widthのゲット関数
	*/
	inline FLOAT GetXWidth() { return m_x_width; }
	/**
	* @brief m_y_heightのゲット関数
	*/
	inline FLOAT GetYHeight() { return m_y_height; }

	/**
	* @brief m_tuのゲット関数
	*/
	inline FLOAT GetTu() { return m_tu; }
	/**
	* @brief m_tvのゲット関数
	*/
	inline FLOAT GetTv() { return m_tv; }
	/**
	* @brief m_tu_widthのゲット関数
	*/
	inline FLOAT GetTuWidth() { return m_tu_width; }
	/**
	* @brief m_tv_heightのゲット関数
	*/
	inline FLOAT GetTvHeight() { return m_tv_height; }
	
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

