#ifndef CURSOR_H_
#define CURSOR_H_

#include "Object.h"
#include "Gimmick.h" 

enum class CURSOR_DIRECTION
{
	NO,
	UP,
	RIGHT,
	LEFT,
	DOWN,
};

class Cursor : public Object
{
private:

	Xinput* xinput;

	FLOAT m_move_speed;

	FLOAT m_save_x;

	FLOAT m_save_y;

	CURSOR_DIRECTION m_save_direction= CURSOR_DIRECTION::NO;

public:

	virtual ~Cursor() {}
	/**
	* @brief プレイヤーの前に描画されるように初期化する用
	*/
	Cursor(XyCoordinate player);
	/**
	* @brief カーソルとウィンドウのX軸の当たり判定
	* @return カーソルのX座標がウィンドウないならばTRUEを返す
	*/
	BOOL HitCheckWindowX();
	/**
	* @brief カーソルとウィンドウのY軸の当たり判定
	* @return カーソルのY座標がウィンドウないならばTRUEを返す
	*/
	BOOL HitcheckWindowY();
	/**
	* @brief カーソル移動関数
	*/
	VOID Move();
	/**
	* @brief 現在の座標を記憶する関数
	*/
	VOID SavePosition();
	/**
	* @brief カーソルがウィンドウ外にでた場合前の座標に戻す関数
	*/
	VOID ModifyCoordinates();
	/**
	* @brief m_save_directionのセット関数
	* @param カーソルの進む方向
	*/
	inline VOID SetSaveDirection(CURSOR_DIRECTION direction) { m_save_direction = direction; }
};

#endif // !CURSOR_H_
