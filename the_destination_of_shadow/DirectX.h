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

enum KEY_STATE
{
	PRESS,
	RELEASE,
	ON,
	OFF
};

class DIRECTX
{
private:
	
	Key key;

	Connection connection;

	Mash mash;

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

	//　コントローラーの状態
	XINPUT_STATE XinputState;

	//	バイブレーションの強さ
	XINPUT_VIBRATION XinputVibration;

	//　テクスチャ
	LPDIRECT3DTEXTURE9 pTexture[TEX_MAX];

	LPD3DXFONT pFont;//フォントオブジェクト

	//! デバイスの作成
	HRESULT BuildDxDevice(HWND hWnd, const TCHAR* FilePath);

	//! デバイスの初期設定
	HRESULT InitD3Device(HWND hWnd, const TCHAR* FilePath);

	//! Xboxコントローラーの状態を更新する関数
	VOID UpdateControllerState();

	//! ウィンドウの初期設定
	VOID InitPresentParameters(HWND hWnd);

};

class Key
{
public:
	static const INT MAX_KEY = 256;

	KEY_STATE m_key_state[256];
};

class Connection
{
public:
	BOOL m_is_connected;
};

class Mash
{
public:
	const INT MASK_NUM = 0x80;
};

#endif