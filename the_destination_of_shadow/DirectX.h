#ifndef DirectX_H
#define DirectX_H

#include <windows.h>
#include <d3d9.h>
#include <dinput.h>
#include<Xinput.h>
#include <d3dx9tex.h>
#include <tchar.h>

#define TEX_MAX 20

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#define XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE  7849
#define XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE 8689

class DIRECTX
{

public:
	//　Direct3Dのインターフェイス
	LPDIRECT3D9 pDirect3D;

	//　Direct3Dのデバイス
	IDirect3DDevice9* pD3Device;

	//　ウィンドウの設定
	D3DPRESENT_PARAMETERS D3dPresentParameters;

	//　DirectInputのキーボードデバイス
	LPDIRECTINPUTDEVICE8 pDxIKeyDevice;

	//　DirectInputのインターフェイス
	LPDIRECTINPUT8 pDinput;

	XINPUT_STATE XinputState;

	XINPUT_VIBRATION XinputVibration;

	//　テクスチャ
	LPDIRECT3DTEXTURE9 pTexture[TEX_MAX];

	LPD3DXFONT pFont;//フォントオブジェクト


	enum KEY_STATE
	{
		PRESS,
		RELEASE,
		ON,
		OFF
	};

	static const INT m_max_key = 256;

	const INT m_mask_num = 0x80;

	BOOL m_is_connected;

	KEY_STATE m_key_state[256];

	HRESULT BuildDxDevice(HWND hWnd, const TCHAR* FilePath);

	HRESULT InitD3Device(HWND hWnd, const TCHAR* FilePath);

	HRESULT UpdateControllerState();

	VOID InitPresentParameters(HWND hWnd);

};

#endif