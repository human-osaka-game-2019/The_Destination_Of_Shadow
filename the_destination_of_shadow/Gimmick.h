#ifndef GIMMICK_H_
#define GIMMICK_H_

#include "Object.h"

enum class LR_Direction_2
{
	RIGHT,
	LEFT
};

class Gimmick : public Object
{
private:
	GIMMICK_ID m_id = GIMMICK_ID::NO_ID;
	BOOL m_is_shadow = TRUE;

	LR_Direction_2 lr_direction = LR_Direction_2::RIGHT;

public:

	Gimmick(FLOAT x, FLOAT y, GIMMICK_ID id);
	virtual ~Gimmick() {}
	/**
	* @brief ギミックを建物の状態で初期化する
	* @param x x座標
	* @param y y座標
	*/
	VOID InitBuilding(FLOAT x, FLOAT y);
	/**
	* @brief 影を借りられた状態に変更する関数
	*/
	VOID ChangeShadow();
	/**
	* @brief 影が借りられていた時Alpha値を変更し、透過させる関数
	*/
	VOID MakeTransparent();
	/**
	* @brief 現在影を借りられているかどうかを返す
	*/
	inline BOOL GetShadow() { return m_is_shadow; }

	VOID GimmickScroll();

	/**
	* @brief m_save_directionのゲット関数
	*/
	inline FLOAT GetSaveTu() { return texture.GetTu(); }
	/**
	* @brief m_save_tuのセット関数
	* @param save_tu
	*/
	inline VOID SetSaveTu(FLOAT save_tu) { texture.SetTu(save_tu); }
	/**
	* @brief m_save_tuに任意の値を足すセット関数
	* @param plus_value
	*/
	inline VOID SetPlusTu(FLOAT plus_value) { texture.SetTu(texture.GetTu() + plus_value); }
	/**
	* @brief m_save_tuに任意の値を引くセット関数
	* @param minus_value
	*/
	inline VOID SetMinusTu(FLOAT minus_value) { texture.SetTu(texture.GetTu() - minus_value); }
};

#endif // !GIMMICK_H_

