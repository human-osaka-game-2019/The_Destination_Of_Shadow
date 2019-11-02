/**
* @file Draw.h
*/

#ifndef DRAW_H_
#define DRAW_H_

#include <windows.h>
#include <d3d9.h>

#include "DirectX.h"

/**
* @enum TEX
* TextureIDリスト
*/
enum TEX
{
	SKY,
	CLOUD,
	CLOUD02,
	CLOUD03,
	MOUNT,
	PLAYER,
	REAL_BACKGROUND,
	SHADOW_BACKGROUND,
	MAXTEX,
};

//カスタムバーテックス
struct CUSTOMVERTEX
{
	FLOAT x, y, z, rhw;
	DWORD color;
	FLOAT tu, tv;
};

/**
* @brief xy座標をまとめた構造体
*/
struct XyCoordinate
{
	FLOAT m_x;
	FLOAT m_y;
	FLOAT m_width;
	FLOAT m_height;
};

/**
* @brief uv座標をまとめた構造体
*/
struct UvCoordinate
{
	FLOAT m_tu;
	FLOAT m_tv;
	FLOAT m_tu_size;
	FLOAT m_tv_size;
};

/**
* @brief Textuer描画関係class
*/
class Texture
{
private:

	TEX m_tex;
	INT m_alpha;
	UvCoordinate uv_coordinate;

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
	* @param xy_coordinate	描画したい画像のxy座標
	* @param alpha			アルファ値、最大255
	* @param degree			描画したい画像の角度
	*/
	VOID Draw(XyCoordinate xy_coordinate, INT alpha = 255, DOUBLE degree = 0.0f);

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
	DOUBLE ToRadian(DOUBLE degree);

	/**
	* @brief UvCoordinate構造体のゲット関数
	*/
	inline UvCoordinate GetUvCoordinate() { return uv_coordinate; }

	/**
	* @brief m_tuのセット関数
	* @param tu
	*/
	inline VOID SetTu(FLOAT tu) { uv_coordinate.m_tu = tu; }

	/**
	* @brief m_tvのセット関数
	* @param tv
	*/
	inline VOID SetTv(FLOAT tv) { uv_coordinate.m_tv = tv; }

	/**
	* @brief m_tu_widthのセット関数
	* @param tu tuの幅
	*/
	inline VOID SetTuWidth(FLOAT tu_width) { uv_coordinate.m_tu_size = tu_width; }

	/**
	* @brief m_tv_heightのセット関数
	* @param tv tvの高さ
	*/
	inline VOID SetTvHeight(FLOAT tv_height) { uv_coordinate.m_tv_size = tv_height; }

	/**
	* @brief TextureIDのセット関数
	* @param TextureID
	*/
	inline VOID SetTextureNum(TEX tex) { m_tex = tex; }

	/**
	* @brief Alpha値のセット関数
	* @param Alpha値
	*/
	inline VOID SetAlpha(INT alpha) { m_alpha = alpha; }
};

#endif
