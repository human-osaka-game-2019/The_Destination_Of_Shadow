﻿
#include "DirectX.h"

HRESULT DirectX::BuildDxDevice(HWND hWnd, CONST TCHAR* filepath)
{
	if (FAILED(InitD3Device(hWnd, filepath)))
	{
		return E_FAIL;
	}

	pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (pDirect3D == NULL)
	{
		MessageBox(0, _T("Direct3Dの作成に失敗しました"), NULL, MB_OK);
		return E_FAIL;
	}

	return S_OK;
}

HRESULT DirectX::InitD3Device(HWND hWnd, CONST TCHAR* FilePath)
{
	if (NULL == (pDirect3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		MessageBox(0, _T("Direct3Dの作成に失敗しました"), _T(""), MB_OK);
		return E_FAIL;
	}

	InitPresentParameters(hWnd);

	if (FAILED(pDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&D3dPresentParameters, &pD3Device)))
	{

		MessageBox(0, _T("HALモードでDIRECT3Dデバイスの作成に失敗しました\nREFモードで再試行します"), NULL, MB_OK);
		if (FAILED(pDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd,
			D3DCREATE_MIXED_VERTEXPROCESSING,
			&D3dPresentParameters, &pD3Device)))
		{
			MessageBox(0, _T("DIRECT3Dデバイスの作成に失敗しました"), NULL, MB_OK);
			return E_FAIL;
		}
	}
	for (INT i = 0; i < MAX_TEX; i++)
	{
		if (FAILED(D3DXCreateTextureFromFileEx(pD3Device, FilePath, 100, 100, 0, 0, D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_DEFAULT,
			0xffffffff, NULL, NULL, &pTexture[i])))
		{
			MessageBox(0, _T("テクスチャの作成に失敗しました"), _T(""), MB_OK);
			return E_FAIL;
		}
	}
	if (FAILED(D3DXCreateFont(
		pD3Device,                 /* デバイス */
		16,                      /* 文字の高さ */
		0,                       /* 文字幅 */
		FW_NORMAL,               /* フォントの太さ */
		1,                       /* MIPMAPのレベル */
		FALSE,                   /* イタリックか？ */
		DEFAULT_CHARSET,         /* 文字セット */
		OUT_DEFAULT_PRECIS,      /* 出力精度 */
		DEFAULT_QUALITY,         /* 出力品質 */
		DEFAULT_PITCH | FF_SWISS,/* フォントピッチとファミリ */
		_T("ＭＳ Ｐゴシック"),       /* フォント名 */
		&pFont)))
	{
		MessageBox(0, _T("フォントの作成に失敗しました"), "", MB_OK);
		return E_FAIL;
	}

	return S_OK;
}

BOOL DirectX::UpdateControllerState()
{	 
	return (XInputGetState(0, &XinputState) == ERROR_SUCCESS) ?  TRUE :  FALSE;
}


VOID DirectX::InitPresentParameters(HWND hWnd)
{
	ZeroMemory(&D3dPresentParameters, sizeof(D3dPresentParameters));

	D3dPresentParameters.BackBufferWidth = window_size.WIDTH;
	D3dPresentParameters.BackBufferHeight = window_size.HEIGHT;
	D3dPresentParameters.BackBufferFormat = D3DFMT_UNKNOWN;
	D3dPresentParameters.BackBufferCount = 1;
	D3dPresentParameters.MultiSampleType = D3DMULTISAMPLE_NONE;
	D3dPresentParameters.MultiSampleQuality = 0;
	D3dPresentParameters.hDeviceWindow = hWnd;
	D3dPresentParameters.EnableAutoDepthStencil = FALSE;
	D3dPresentParameters.AutoDepthStencilFormat = D3DFMT_A1R5G5B5;
	D3dPresentParameters.Flags = 0;
	D3dPresentParameters.FullScreen_RefreshRateInHz = 0;
	D3dPresentParameters.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	D3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	D3dPresentParameters.Windowed = true;
}