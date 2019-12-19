#ifndef STAGE_H
#define STAGE_H

#include "Background.h"

enum class LR_Direction
{
	RIGHT,
	LEFT
};

/**
* @brief ステージに関するクラス
*/
class Stage
{
public:

	/**
	* @enum Stage
	* コンストラクタ
	*/
	Stage();

	/**
	* @enum CurrentStage
	* 現在どのステージにいるかの判定
	*/
	enum class CurrentStage
	{
		//! 影の世界
		SHADOW,
		//! 現実世界
		REAL
	};

	/**
	* @enum CurrentStage
	* ゲッター
	*/
	inline Stage::CurrentStage GetCurrentStage() { return current_stage; }

	CurrentStage current_stage = CurrentStage::REAL;

	VOID SetLR_Direction(LR_Direction direction) { lr_direction = direction; }

	RealBackground real_background;
	ShadowBackground shadow_background;
	Mountain* mountain;
	Cloud* cloud;
	RealGround* real_ground;
	ShadowGround* shadow_ground;

	//! 遷移のクールタイム
	INT fc_cooldown = 30;

	VOID MountainScroll();

	VOID CloudScroll();

	VOID RealGroundScroll();

	VOID ShadowGroundScroll();

private:

	LR_Direction lr_direction = LR_Direction::RIGHT;
};
#endif
