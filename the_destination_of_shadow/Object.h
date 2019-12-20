/**
* @file Object.h
*/

#ifndef OBJECT_H_
#define OBJECT_H_

#include <windows.h>
#include <d3d9.h>

#include"Main.h"
#include"Draw.h"

enum class GIMMICK_ID
{
	NO_ID,
	BUILDING,
};

enum class LR_Direction
{
	RIGHT,
	LEFT
};

/**
* @enum Direction
* 向きを管理する
*/
enum class DIRECTION
{
	/*! 右を向いている */
	RIGHT,
	/*! 左を向いている */
	LEFT,
};

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
	* @brief アニメーションの関数
	* @param flamecount   なんのアニメーションをするためのflamecountか
	* @param count  　　　何回処理に入るのか
	* @param tu  　　　　 アニメーションをする初めのtu座標
	* @param tv           アニメーションをする初めのtv座標
	* @param split_tu     tuの幅（1/???）
	* @param split_tv     tvの幅（1/???）
	* @param start_tu	　開始地点のtu
	* @param start_tv	　開始地点のtv
	* @param finish_tu	　終了地点のtu
	* @param finish_tv	　終了地点のtv
	*/
	VOID Animetion(INT* flamecount, INT count, UvCoordinate* uv_coordnate, FLOAT start_tu, FLOAT start_tv, FLOAT finish_tu, FLOAT finish_tv);

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

class ScrollObject : public Object
{
private:
	const FLOAT MAX_CAMERA_MOVE = 1620.0f;
	const FLOAT CAMERA_MOVE_SPEED = 10.0f;
	FLOAT m_crrent_camera_pos = 0.0f;
public:

	ScrollObject() {}
	virtual ~ScrollObject() {}
	VOID ObjScroll(LR_Direction direction);
	VOID CameraScroll(LR_Direction player);
};

#endif // !OBJECT_H_
