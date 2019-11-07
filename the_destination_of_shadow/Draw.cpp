#include "Draw.h"
#include "Main.h"

VOID Texture::InitRender()
{
	// テクスチャの設定
	directx.pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	directx.pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	directx.pD3Device->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	// アルファ・ブレンディングを行う
	directx.pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	// 透過処理を行う
	directx.pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	// 半透明処理を行う
	directx.pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
}

VOID Texture::Rotate(CUSTOMVERTEX  original[], CUSTOMVERTEX rotatevertex[], DOUBLE degree)
{
	FLOAT center_x = (original[0].x + original[1].x) / 2.0f;
	FLOAT center_y = (original[0].y + original[3].y) / 2.0f;


	for (INT i = 0; i < 4; i++)
	{
		original[i].x -= center_x;
		original[i].y -= center_y;

		rotatevertex[i] = original[i];

		// 回転後のx = 回転前のx・cosθ - 回転前のy・sinθ
		rotatevertex[i].x = (FLOAT)(original[i].x * cos(ToRadian(degree)) - original[i].y * sin(ToRadian(degree)));

		// 回転後のy = 回転前のx・sinθ + 回転前のy・cosθ
		rotatevertex[i].y = (FLOAT)(original[i].x * sin(ToRadian(degree)) + original[i].y * cos(ToRadian(degree)));

		original[i].x += center_x;
		original[i].y += center_y;

		rotatevertex[i].x += center_x;
		rotatevertex[i].y += center_y;
	}

}

//アニメーション関数

VOID Texture::Animetion(INT * flamecount, INT count, FLOAT * tu, FLOAT * tv, FLOAT split_tu, FLOAT split_tv, FLOAT start_tu, FLOAT start_tv, FLOAT finish_tu, FLOAT finish_tv)
{
	if (*flamecount >= count)
	{
		*tu += split_tu;
		*tv += split_tv;
		count = 0.0f;
		*flamecount = count;
	}
	if (*tu >= finish_tu)
	{
		split_tu = start_tu;
		*tu = split_tu;
	}
	if (*tv >= finish_tv)
	{
		split_tv = start_tv;
		*tv = split_tv;
	}
}

DOUBLE Texture::ToRadian(DOUBLE degree)
{

	return degree * atan(1.0)* 4.0 / 180.0;
}
