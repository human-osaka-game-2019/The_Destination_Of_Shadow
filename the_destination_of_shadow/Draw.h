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
	MOUNTAIN,
	PLAYER,
	REAL_BACKGROUND,
	SHADOW_BACKGROUND,
	SHADOW_GROUND,
	REAL_GROUND,
	SHADOW_BLOCK,
	REAL_BLOCK,
	CURSOR,
	KARI,
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

	inline FLOAT GetTu() { return uv_coordinate.m_tu; }
	inline FLOAT GetTv() { return uv_coordinate.m_tv; }

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
	/**
	* @brief Alpha値のゲット関数
	* @return Alpha値
	*/
	inline INT GetAlpha() { return m_alpha; }
};

#endif
