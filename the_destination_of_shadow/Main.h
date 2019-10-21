﻿#ifndef MAIN_H
#define MAIN_H

#include <windows.h>
#include <d3d9.h>

#include "Draw.h"

enum TEX
{
	PYON,
	MAXTEX,
};

enum SCENE
{
	TITLE_SCENE,
	HELP_SCENE,
	GAME_SCENE,
	EXIT_SCENE,
	RESULT_SCENE,
};


extern DirectX directx;

extern SCENE scene;

extern DrawTex draw_tex;


//WinMain関数
INT WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdline, _In_ INT nCmdShow);

//ウィンドプロシージャの生成
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//window作成
HWND GenerateWindow(HWND* hWnd, HINSTANCE* hInstance, const TCHAR* API_NAME);

//メインループ
VOID Mainloop(MSG* msg);

#endif
