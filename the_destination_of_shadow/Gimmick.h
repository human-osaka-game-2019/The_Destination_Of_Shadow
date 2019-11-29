#ifndef GIMMICK_H_
#define GIMMICK_H_

#include "Object.h"

class Gimmick : public Object
{
private:
	GIMMICK_ID m_id = GIMMICK_ID::NO_ID;
	BOOL m_is_shadow = TRUE;

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
	* @return m_is_shadow 現在の影の状態
	*/
	inline BOOL GetShadow() { return m_is_shadow; }
	/**
	* @brief ギミックのIDを入手する関数
	* @param ギミックのID
	*/
	inline GIMMICK_ID GetGimmickId() { return m_id; }
};

#endif // !GIMMICK_H_

