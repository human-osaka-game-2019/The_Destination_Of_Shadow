/**
* @file Object.h
*/

#ifndef OBJECT_H_
#define OBJECT_H_

#include"DirectX.h"

enum TEX
{
	SKY,
	CLOUD,
	CLOUD02,
	CLOUD03,
	MOUNT,
	PLAYER,
	MAXTEX,
};


/**
* @brief 全てのオブジェクトのもとになるクラス
*/
class Object
{
protected:

	TEX m_tex;
	INT m_alpha;

	FLOAT m_x;
	FLOAT m_y;
	FLOAT m_x_width;
	FLOAT m_y_height;

	FLOAT m_tu;
	FLOAT m_tv;
	FLOAT m_tu_width;
	FLOAT m_tv_height;

public:
	virtual ~Object() {}

	inline INT GetAlpha() { return m_alpha; }

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
};

#endif // !OBJECT_H_

