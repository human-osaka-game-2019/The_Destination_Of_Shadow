#ifndef PLAYER_MANAGER_H_
#define PLAYER_MANAGER_H_

#include "Player.h"
#include "Cursor.h"

enum class PLAYER_MODE
{
	NO_CHANGE,
	NORMAL,
	SHADOW_BORROW,
	SHADOW_USE,
};

class PlayerManager
{
private:

	Player* player;

	Cursor* cursor;

	Xinput* xinput;

	PLAYER_MODE m_next_mode = PLAYER_MODE::NO_CHANGE;

	PLAYER_MODE m_current_mode = PLAYER_MODE::NORMAL;

public:

	/**
	* @brief プレイヤーに関する画像を読み込む関数
	*/
	VOID Load();
	/**
	* @brief プレイヤーに関する画像を描画する関数
	*/
	VOID Draw();
	/**
	* @brief モードを切り替える関数変化しない場合はそのまま抜ける
	*/
	VOID ModeChange();
	/**
	* @brief モードごとのプレイヤーの動作を呼び出す関数
	*/
	VOID Move();
	/**
	* @brief  NormalMode時の挙動
	*/
	VOID NormalModeMove();
	/**
	* @brief ShadowBorrowMode時の挙動
	*/
	VOID ShadowBorrowModeMove();
	/**
	* @brief ShadowUseMode時の挙動
	*/
	VOID ShadowUseModeMove();
	PlayerManager();
	~PlayerManager();

};

#endif // !PLAYER_MANAGER_H_
