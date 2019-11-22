/**
* @file Background.h
*/

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Object.h"

/**
* @brief 現実ステージに関するクラス
*/
class RealBackground :public Object
{
public:
	
	/**
	* @brief コンストラクタ
	*/
	RealBackground();
};

/**
* @brief 山脈に関するクラス
*/
class Mountain :public Object
{
public:

	/**
	* @brief コンストラクタ
	*/
	Mountain();

	/**
	* @brief m_save_directionのゲット関数
	*/
	inline FLOAT GetSaveTu() { return m_save_tu; }
	/**
	* @brief m_save_tuのセット関数
	* @param save_tu
	*/
	inline VOID SetSaveTu(FLOAT save_tu) { m_save_tu = save_tu; }
	/**
	* @brief m_save_tuに任意の値を足すセット関数
	* @param plus_value
	*/
	inline VOID SetPlus(FLOAT plus_value) { m_save_tu + plus_value; }
	/**
	* @brief m_save_tuに任意の値を引くセット関数
	* @param minus_value
	*/
	inline VOID SetMinus(FLOAT minus_value) { m_save_tu - minus_value; }

private:

	FLOAT m_save_tu = 0.0f;
	FLOAT m_fc_scroll = 0;
};

/**
* @brief 影のステージに関するクラス
*/
class ShadowBackground :public Object
{
public:

	/**
	* @brief コンストラクタ
	*/
	ShadowBackground();
};
#endif
