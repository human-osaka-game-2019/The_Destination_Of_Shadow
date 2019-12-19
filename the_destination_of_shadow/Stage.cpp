#include "Stage.h"

Stage::Stage()
{
	mountain = new Mountain();
	cloud = new Cloud();
	real_ground = new RealGround();
	shadow_ground = new ShadowGround();
}

VOID Stage::CloudScroll()
{
	switch (lr_direction)
	{
	case LR_Direction::RIGHT:
		cloud->SetPlusTu(0.00004f);
		if (cloud->GetSaveTu() >= 1.0f)
		{
			cloud->SetSaveTu(0.0f);
		}
		break;
	case LR_Direction::LEFT:
		cloud->SetMinusTu(0.00004f);
		if (cloud->GetSaveTu() <= -1.0f)
		{
			cloud->SetSaveTu(0.0f);
		}
		break;
	default:
		break;
	}
}
VOID Stage::RealGroundScroll()
{
	switch (lr_direction)
	{
	case LR_Direction::RIGHT:
		real_ground->SetPlusTu(0.0003f);
		if (real_ground->GetSaveTu() >= 1.0f)
		{
			real_ground->SetSaveTu(0.0f);
		}
		break;
	case LR_Direction::LEFT:
		real_ground->SetMinusTu(0.0003f);
		if (real_ground->GetSaveTu() <= -1.0f)
		{
			real_ground->SetSaveTu(0.0f);
		}
		break;
	default:
		break;
	}

}
VOID Stage::ShadowGroundScroll()
{
	switch (lr_direction)
	{
	case LR_Direction::RIGHT:
		shadow_ground->SetPlusTu(0.0003f);
		if (shadow_ground->GetSaveTu() >= 1.0f)
		{
			shadow_ground->SetSaveTu(0.0f);
		}
		break;
	case LR_Direction::LEFT:
		shadow_ground->SetMinusTu(0.0003f);
		if (shadow_ground->GetSaveTu() <= -1.0f)
		{
			shadow_ground->SetSaveTu(0.0f);
		}
		break;
	default:
		break;
	}

}

VOID Stage::MountainScroll()
{
	switch (lr_direction)
	{
	case LR_Direction::RIGHT:
		shadow_ground->SetPlusTu(0.0001f);
		if (mountain->GetSaveTu() >= 1.0f)
		{
			mountain->SetSaveTu(0.0f);
		}
		break;
	case LR_Direction::LEFT:
		shadow_ground->SetMinusTu(0.0001f);
		if (mountain->GetSaveTu() <= -1.0f)
		{
			mountain->SetSaveTu(0.0f);
		}
		break;
	default:
		break;
	}

}
