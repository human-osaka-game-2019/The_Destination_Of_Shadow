#ifndef PLAYER_MANAGER_H_
#define PLAYER_MANAGER_H_

#include "Player.h"
#include "Cursor.h"

class PlayerManager
{
private:

	Player* player;

	Cursor* cursor;

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
	PlayerManager();
	~PlayerManager();

};

#endif // !PLAYER_MANAGER_H_
