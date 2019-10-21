/**
* @file DirectX.h
*/

#ifndef DirectX_H
#define DirectX_H

#include <windows.h>
#include <d3d9.h>
#include <dinput.h>
#include<Xinput.h>
#include <d3dx9tex.h>
#include <tchar.h>

enum KEY_STATE
{
	PRESS,
	RELEASE,
	ON,
	OFF
};

class WindowSize
{
public:
	const INT m_WINDOW_WIDTH = 1920;
	const INT m_WINDOW_HEIGHT = 1080;
};

 class GamePadDeadZone
{
public:
	const FLOAT m_GAMEPAD_LEFT_DEADZONE = 7849;	//! Xboxコントローラー左スティックのデットゾーン

	const FLOAT m_GAMEPAD_RIGHT_DEADZONE = 8689;	//! Xboxコントローラー右スティックのデットゾーン

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
	//! 接続されているかを確認するためのフラグ
	BOOL m_is_connected;
};

class Mask
{
public:
	const INT MASK_NUM = 0x80;
};

/**
* @brief DirectX使用に必要な構造体、関数を詰め込んだclass
*/
class DirectX
{
private:

	GamePadDeadZone game_pad_dead_zone;

	WindowSize window_size;
	
	Key key;

	Connection connection;

	Mask mask;

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
	LPDIRECT3DTEXTURE9 pTexture[20];

	LPD3DXFONT pFont;//フォントオブジェクト

	/**
	* @brief デバイスの作成
	* @param (hWnd)
	* @param (*FilePath)
	*/
	HRESULT BuildDxDevice(HWND hWnd, const TCHAR* FilePath);

	/**
	* @brief デバイスの初期化
	* @param (hWnd)
	* @param (*FilePath)
	*/
	HRESULT InitD3Device(HWND hWnd, const TCHAR* FilePath);

	/**
	* @brief Xboxコントローラーの状態を更新する関数
	*/
	VOID UpdateControllerState();

	/**
	* @brief ウィンドウの初期設定
	*/
	VOID InitPresentParameters(HWND hWnd);

};


#endif