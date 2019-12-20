#ifndef STAGE_H
#define STAGE_H

#include "Background.h"

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

	RealBackground real_background;
	ShadowBackground shadow_background;
	Mountain* mountain;
	Cloud* cloud;
	RealGround* real_ground;
	ShadowGround* shadow_ground;

	//! 遷移のクールタイム
	INT fc_cooldown = 30;

	VOID MountainScroll(LR_Direction direction);

	VOID CloudScroll(LR_Direction direction);

	VOID RealGroundScroll(LR_Direction direction);

	VOID ShadowGroundScroll(LR_Direction direction);

private:

	//LR_Direction lr_direction = LR_Direction::RIGHT;
};
#endif
