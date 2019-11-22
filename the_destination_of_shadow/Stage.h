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
	CurrentStage current_stage;

	RealBackground real_background;
	ShadowBackground shadow_background;
	Mountain mountain;

	//! 遷移のクールタイム
	INT fc_cooldown = 30;

	VOID Scroll();
};
#endif
