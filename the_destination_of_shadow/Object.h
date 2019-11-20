/**
* @file Object.h
*/

#ifndef OBJECT_H_
#define OBJECT_H_

#include <windows.h>
#include <d3d9.h>

#include"Main.h"
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
	* @brief 画像読み込み用関数
	* @param FilePath	読み込む画像のファイルパス
	* @param TEX		TextuerID
	*/
	VOID LoadTexture(const CHAR* file_name, INT TEX);
	/**
	* @brief 描画関数
	* @param xy_coordinate	描画したい画像のuv座標
	* @param tex			TextureID
	* @param alpha			アルファ値、最大255
	* @param degree			描画したい画像の角度
	*/
	VOID Draw(UvCoordinate uv_coordinate,TEX tex, INT alpha = 255, DOUBLE degree = 0.0f);
	/**
	* @brief XyCoordinateのゲット関数
	*/
	inline XyCoordinate GetXyCoordinate() const { return xy_coordinate; }
	/**
	* @brief m_xのゲット関数
	*/
	inline FLOAT GetX() const { return xy_coordinate.m_x; }
	/**
	* @brief m_yのゲット関数
	*/
	inline FLOAT GetY() const { return xy_coordinate.m_y; }
	/**
	* @brief m_x_widthのゲット関数
	*/
	inline FLOAT GetXWidth() const { return xy_coordinate.m_width; }
	/**
	* @brief m_y_heightのゲット関数
	*/
	inline FLOAT GetYHeight() const { return xy_coordinate.m_height; }
};

#endif // !OBJECT_H_
