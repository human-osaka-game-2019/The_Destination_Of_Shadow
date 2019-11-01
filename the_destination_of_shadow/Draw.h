/**
* @file Draw.h
*/

#ifndef DRAW_H_
#define DRAW_H_

#include <windows.h>
#include <d3d9.h>

#include "DirectX.h"

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
class DrawTex
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
	* @param x			描画したい画像のx座標
	* @param y			描画したい画像のy座標
	* @param tu			描画したい画像のtu
	* @param tv			描画したい画像のtv
	* @param width		描画したい画像の幅
	* @param height		描画したい画像の高さ
	* @param tu_width	描画したい画像のtuの幅
	* @param tv_height	描画したい画像のtvの高さ
	* @param texture	描画したい画像のTextuerID
	* @param alpha		描画したい画像の透明度（255～0まで）
	* @param degree		描画したい画像の角度
	*/
	VOID Draw(FLOAT x, FLOAT y, FLOAT tu, FLOAT tv, FLOAT width, FLOAT height, FLOAT tu_width, FLOAT tv_height, INT texture, INT alpha = 255, DOUBLE degree = 0.0f);

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