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

#define TEX_MAX 20

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

/**
* @def XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE
* @brief Xboxコントローラー左スティックのデットゾーン
*/
#define XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE  7849

/**
* @def XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE
* @brief Xboxコントローラー右スティックのデットゾーン
*/
#define XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE 8689

enum KEY_STATE
{
	PRESS,
	RELEASE,
	ON,
	OFF
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

class Mash
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