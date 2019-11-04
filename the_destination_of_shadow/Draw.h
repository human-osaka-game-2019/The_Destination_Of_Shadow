/**
* @file Draw.h
*/

#ifndef DRAW_H_
#define DRAW_H_

#include <windows.h>
#include <d3d9.h>

#include "DirectX.h"
#include"Object.h"

//カスタムバーテックス
struct CUSTOMVERTEX
{
	FLOAT x, y, z, rhw;
	DWORD color;
	FLOAT tu, tv;
};

/**
* @brief Textuer描画関係class
*/
class Texture
{
public:

	/**
	* @brief Renderの初期化
	*/
	VOID InitRender();

	/**
	* @brief 画像回転用
	* @param original[]		回転前の座標
	* @param rotatevertex[]	回転後の座標
	* @param degree			回転したい角度
	*/
	VOID Rotate(CUSTOMVERTEX  original[], CUSTOMVERTEX rotatevertex[], DOUBLE degree = 0.0f);

	/**
	* @brief 描画関数
	* @param object		描画したい画像のクラス
	* @param degree		描画したい画像の角度
	*/
	VOID Draw(Object object, DOUBLE degree = 0.0f);

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
	VOID Animetion(INT* flamecount, INT count, FLOAT* tu, FLOAT* tv, FLOAT split_tu, FLOAT split_tv, FLOAT start_tu, FLOAT start_tv, FLOAT finish_tu, FLOAT finish_tv);

	/**
	* @brief 画像読み込み用関数
	* @param FilePath	読み込む画像のファイルパス
	* @param TEX		TextuerID
	*/
	VOID LoadTexture(const CHAR* file_name, INT TEX);

	/**
	* @brief 角度をラジアンに変換する
	* @param degree 変換したい角度
	*/
	DOUBLE to_Rad(DOUBLE degree);
};



#endif