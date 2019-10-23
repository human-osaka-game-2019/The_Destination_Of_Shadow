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

/**
 * @enum KEY_STATE
 * DirectInputで使用するキーの状態
 */
enum KEY_STATE
{
	//! 押した瞬間
	PRESS,

	//! 放した瞬間
	RELEASE,

	//! 押している状態
	ON,		

	//! 押していない状態
	OFF,	
};

/**
* @brief Windowのサイズ
*/
class WindowSize
{
public:
	const INT WIDTH = 1920;
	const INT HEIGHT = 1080;
};

/**
* @brief XInputで使用するコントローラーのスティックのデットゾーン
*/
 class GamePadDeadZone
{
public:
	const FLOAT LEFT = 7849;	//! Xboxコントローラー左スティックのデットゾーン

	const FLOAT RIGHT = 8689;	//! Xboxコントローラー右スティックのデットゾーン

};

 /**
* @brief DirectInputで使用するKeyState
*/
class Key
{
public:
	static const INT MAX = 256;

	KEY_STATE m_state[256];
};

/**
* @brief マスク値
*/
class Mask
{
public:
	const INT NUM = 0x80;
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
	* @param hWnd
	* @param FilePath
	*/
	HRESULT BuildDxDevice(HWND hWnd, const TCHAR* FilePath);

	/**
	* @brief デバイスの初期化
	* @param hWnd
	* @param FilePath
	*/
	HRESULT InitD3Device(HWND hWnd, const TCHAR* FilePath);

	/**
	* @brief Xboxコントローラーの状態を更新する関数
	*/
	BOOL UpdateControllerState();

	/**
	* @brief ウィンドウの初期設定
	* @param hWnd
	*/
	VOID InitPresentParameters(HWND hWnd);

};


#endif