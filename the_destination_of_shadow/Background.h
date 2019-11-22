/**
* @file Player.h
*/

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "DirectX.h"
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

class Mountain :public Object
{
public:

	/**
	* @brief コンストラクタ
	*/
	Mountain();

	/**
	* @brief ステージをスクロールする関数
	*/
	VOID Scroll();

private:

	FLOAT save_tu = 0.0f;
	FLOAT scroll_speed=0.2f;
	FLOAT fc_scroll = 0;
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
