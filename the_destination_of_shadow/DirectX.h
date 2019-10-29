/**
* @file DirectX.h
*/

#ifndef DirectX_H
#define DirectX_H

#include <windows.h>
#include <d3d9.h>
#include <dinput.h>
#include <Xinput.h>
#include <d3dx9tex.h>
#include <tchar.h>

/**
 * @enum KEY_STATE
 * DirectInputで使用するキーの状態
 */
enum KEY_STATE
{
	//! 押していない状態
	OFF,	
	//! 押した瞬間
	PRESS,
	//! 押している状態
	ON,		
	//! 放した瞬間
	RELEASE,

};

//!最大Textuer数
const INT MAX_TEX = 20; 

/**
* @brief Windowのサイズ
*/
class WindowSize
{
private:
	WindowSize(const WindowSize&);
	WindowSize& operator =(const WindowSize&);
public:
	WindowSize(){}
	const INT WIDTH = 1920;
	const INT HEIGHT = 1080;
};

/**
* @brief XInputで使用するコントローラーのスティックのデットゾーン
*/
 class GamePadDeadZone
{
private:
	 GamePadDeadZone(const GamePadDeadZone&);
	 GamePadDeadZone& operator =(const GamePadDeadZone&);
public:
	GamePadDeadZone(){}
	//! Xboxコントローラー左スティックのデットゾーン
	const FLOAT LEFT = 7849;

	//! Xboxコントローラー右スティックのデットゾーン
	const FLOAT RIGHT = 8689;

};

 /**
* @brief DirectInputで使用するKeyState
*/
class Key
{
private:
	Key(const Key&);
	Key& operator =(const Key&);
public:
	Key(){}
	KEY_STATE m_state[256];
};

/**
* @brief マスク値
*/
class Mask
{
private:
	Mask(const Mask&);
	Mask& operator =(const Mask&);
public:
	Mask(){}
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

	DirectX(const DirectX&);

	DirectX& operator = (const DirectX&);

public:
	DirectX(){}
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
	LPDIRECT3DTEXTURE9 pTexture[MAX_TEX];

	//フォントオブジェクト
	LPD3DXFONT pFont;

	/**
	* @brief デバイスの初期化
	* @param hWnd ウィンドウハンドル
	*/
	HRESULT InitDinput(HWND hWnd);

	/**
	* @brief デバイスの作成
	* @param hWnd ウィンドウハンドル
	* @param FilePath ファイルパス
	*/
	HRESULT BuildDxDevice(HWND hWnd, const TCHAR* FilePath);

	/**
	* @brief デバイスの初期化
	* @param hWnd ウィンドウハンドル
	* @param FilePath ファイルパス
	*/
	HRESULT InitD3Device(HWND hWnd, const TCHAR* FilePath);

	/**
	* @brief Xboxコントローラーの状態を更新する関数
	* @return Xboxコントローラーが接続されているならtrueを返す
	*/
	BOOL UpdateControllerState();

	/**
	* @brief ウィンドウの初期設定
	* @param hWnd ウィンドウハンドル
	*/
	VOID InitPresentParameters(HWND hWnd);

	/**
	* @brief キーボードの状態を更新
	*/
	VOID UpdateKeyState();

	/**
	* @brief キーの状態を取得
	* @param 入手したいキーのマクロ
	* @return キーの状態を返す
	*/
	inline KEY_STATE GetKeyState(INT diks)const
	{
		return key.m_state[diks];
	}

	/**
	* @brief 現在のキー入力状態を取得する
	* @param 最上位ビットチェック用配列
	* @param 前のキー状態記憶用配列
	* @return 現在のキー入力状態 
	*/
	KEY_STATE GetInputState(BYTE curr_diks, BYTE prev_diks);

	/**
	* @brief キーが押されたかを判断する
	* @param 最上位ビットチェック用配列
	* @return 押されていたならtrueを返す
	*/
	BOOL IsKeyPressed(BYTE curr_diks);

	/**
	* @brief 最上位ビットが立っているかを確認し、キーの状態を確認する
	* @sa KEY_STATE GetInputState(BYTE curr_diks, BYTE prev_diks)
	* @sa KEY_STATE GetPrevDik(BYTE curr_diks);
	*/
	VOID CheckInputStateDetails();
};

#endif
