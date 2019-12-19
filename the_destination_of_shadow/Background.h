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
	inline VOID SetPlus(FLOAT plus_value) { texture.SetTu(texture.GetTu() + plus_value); }
	/**
	* @brief m_save_tuに任意の値を引くセット関数
	* @param minus_value
	*/
	inline VOID SetMinus(FLOAT minus_value) { texture.SetTu(texture.GetTu() - minus_value); }
};

class Cloud :public Object
{
public:

	/**
	* @brief コンストラクタ
	*/
	Cloud();

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

class RealGround :public Object
{
public:

	/**
	* @brief コンストラクタ
	*/
	RealGround();

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

class ShadowGround :public Object
{
public:

	/**
	* @brief コンストラクタ
	*/
	ShadowGround();

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
