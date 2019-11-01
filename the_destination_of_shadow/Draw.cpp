#include "Draw.h"

#include "Main.h"

VOID DrawTex::InitRender()
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

VOID DrawTex::Rotate(CUSTOMVERTEX  original[], CUSTOMVERTEX rotatevertex[], DOUBLE degree)
{
	FLOAT center_x = (original[0].x + original[1].x) / 2.0f;
	FLOAT center_y = (original[0].y + original[3].y) / 2.0f;


	for (INT i = 0; i < 4; i++)
	{
		original[i].x -= center_x;
		original[i].y -= center_y;

		rotatevertex[i] = original[i];

		// 回転後のx = 回転前のx・cosθ - 回転前のy・sinθ
		rotatevertex[i].x = (FLOAT)(original[i].x * cos(to_Rad(degree)) - original[i].y * sin(to_Rad(degree)));

		// 回転後のy = 回転前のx・sinθ + 回転前のy・cosθ
		rotatevertex[i].y = (FLOAT)(original[i].x * sin(to_Rad(degree)) + original[i].y * cos(to_Rad(degree)));

		original[i].x += center_x;
		original[i].y += center_y;

		rotatevertex[i].x += center_x;
		rotatevertex[i].y += center_y;
	}

}


//描画関数
VOID DrawTex::Draw(FLOAT x, FLOAT y, FLOAT tu, FLOAT tv, FLOAT width, FLOAT height, FLOAT tu_width, FLOAT tv_height, INT texture, INT alpha, DOUBLE degree)
{
	InitRender();

	D3DCOLOR    color;  // 頂点カラー
	// 半透明処理をするかどうかを判断し、頂点カラーを決定
	color = (alpha >= 255) ? D3DCOLOR_XRGB(255, 255, 255) : D3DCOLOR_RGBA(255, 255, 255, alpha);

	CUSTOMVERTEX customvertex[4]
	{
		{x        ,y         ,0,1,color,tu           ,tv            },
		{x + width,y         ,0,1,color,tu + tu_width,tv            },
		{x + width,y + height,0,1,color,tu + tu_width,tv + tv_height},
		{x        ,y + height,0,1,color,tu           ,tv + tv_height},
	};

	directx.pD3Device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	CUSTOMVERTEX vertex[4];
	Rotate(customvertex, vertex, degree);

	directx.pD3Device->SetTexture(0, directx.pTexture[texture]);
	directx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CUSTOMVERTEX));
}

//アニメーション関数

VOID DrawTex::Animetion(INT * flamecount, INT count, FLOAT * tu, FLOAT * tv, FLOAT split_tu, FLOAT split_tv, FLOAT start_tu, FLOAT start_tv, FLOAT finish_tu, FLOAT finish_tv)
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


VOID DrawTex::LoadTexture(const CHAR * file_name, INT TEX)
{

	D3DXCreateTextureFromFileEx(
		directx.pD3Device,
		_T(file_name),
		0,
		0,
		1,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0x00000000,
		nullptr,
		nullptr,
		&directx.pTexture[TEX]);
}


DOUBLE DrawTex::to_Rad(DOUBLE degree)
{

	return degree * atan(1.0)* 4.0 / 180.0;
}