#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_

#include <vector>

#include "Cursor.h"
#include "Gimmick.h"
#include "Player.h"
#include "Stage.h"
#include "Xinput.h"

enum class PLAYER_MODE
{
	NO_CHANGE,
	NORMAL,
	SHADOW_BORROW,
	SHADOW_USE,
};

class GameManager
{
private:

	Xinput* xinput;
	Player* player;
	Cursor* cursor;
	Stage* stage;

	std::vector<Gimmick>gimmick;

	PLAYER_MODE m_next_mode = PLAYER_MODE::NO_CHANGE;

	PLAYER_MODE m_current_mode = PLAYER_MODE::NORMAL;

	/**
	* @brief ノーマルモード時の挙動
	*/
	VOID NormalModeMove();
	/**
	* @brief 影を使うモード時の挙動 
	*/
	VOID ShadowBorrowModeMove();
	/**
	* @brief 影を借りるモード時の挙動
	*/
	VOID ShadowUseModeMove();
	/**
	* @brief 影を借りることが可能か調べる関数
	* @param &gimmick ギミッククラスを格納したvector　
	*/
	VOID ShadowBorrowChacek(std::vector<Gimmick>&gimmick);
	/**
	* @brief 影を借りた時の処理
	* @param gimmick 影を借りるギミッククラス
	*/
	VOID GetShadow(Gimmick* gimmick);
	/**
	* @brief カーソルとギミックが重なり合っているかを確認する関数
	* @param gimmick 確認するギミッククラス
	*/
	BOOL IsHitGimmick(Gimmick gimmick);

	VOID Scroll(LR_Direction direction);

	VOID CameraMove(LR_Direction direction);

public:

	GameManager();
	virtual ~GameManager();
	/**
	* @brief 画像読み込み
	*/
	VOID Load();
	/**
	* @brief 画像描画関数
	*/
	VOID Draw();
	/**
	* @brief プレイヤーのモード切替関数	
	*/
	VOID ModeChange();
	/**
	* @brief ギミックの挙動
	*/
	VOID GimmickMove();
	/**
	* @brief プレイヤーの挙動
	*/
	VOID PlayerMove();

};

#endif // !GAME_MANAGER_H_
