#include"Object.h"
#include"Main.h"

VOID Object::LoadTexture(const CHAR* file_name, INT TEX)
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

//描画関数
VOID Object::Draw(UvCoordinate uv_coordinate,TEX tex, INT alpha, DOUBLE degree)
{
	texture.InitRender();

	D3DCOLOR    color;  // 頂点カラー
	// 半透明処理をするかどうかを判断し、頂点カラーを決定
	color = (alpha >= 255) ? D3DCOLOR_XRGB(255, 255, 255) : D3DCOLOR_RGBA(255, 255, 255, alpha);
	FLOAT left = xy_coordinate.m_x;
	FLOAT right = xy_coordinate.m_width;
	FLOAT top = xy_coordinate.m_y;
	FLOAT bottom = xy_coordinate.m_height;

	CUSTOMVERTEX customvertex[4]
	{
		{left		  ,top			,0,1,color,uv_coordinate.m_tu							,uv_coordinate.m_tv							 },
		{left + right ,top			,0,1,color,uv_coordinate.m_tu + uv_coordinate.m_tu_size ,uv_coordinate.m_tv							 },
		{left + right ,top + bottom	,0,1,color,uv_coordinate.m_tu + uv_coordinate.m_tu_size ,uv_coordinate.m_tv + uv_coordinate.m_tv_size},
		{left		  ,top + bottom	,0,1,color,uv_coordinate.m_tu							,uv_coordinate.m_tv + uv_coordinate.m_tv_size},
	};

	directx.pD3Device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	CUSTOMVERTEX vertex[4];
	texture.Rotate(customvertex, vertex, degree);

	directx.pD3Device->SetTexture(0, directx.pTexture[tex]);
	directx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CUSTOMVERTEX));
}
