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
