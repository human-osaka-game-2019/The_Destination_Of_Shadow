/**
* @file Object.h
*/

#ifndef OBJECT_H_
#define OBJECT_H_

#include <windows.h>
#include <d3d9.h>

#include"Draw.h"

/**
* @brief 全てのオブジェクトのもとになるクラス
*/
class Object
{
protected:

	XyCoordinate xy_coordinate;

public:

	virtual ~Object() {}

	Texture texture;

	/**
	* @brief XyCoordinateのゲット関数
	*/
	XyCoordinate GetXyCoordinate() { return xy_coordinate; }

	/**
	* @brief m_xのゲット関数
	*/
	inline FLOAT GetX() { return xy_coordinate.m_x; }
	/**
	* @brief m_yのゲット関数
	*/
	inline FLOAT GetY() { return xy_coordinate.m_y; }
	/**
	* @brief m_x_widthのゲット関数
	*/
	inline FLOAT GetXWidth() { return xy_coordinate.m_width; }
	/**
	* @brief m_y_heightのゲット関数
	*/
	inline FLOAT GetYHeight() { return xy_coordinate.m_height; }

};

#endif // !OBJECT_H_
