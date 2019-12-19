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

DOUBLE Texture::ToRadian(DOUBLE degree)
{
	return degree * atan(1.0)* 4.0 / 180.0;
}
