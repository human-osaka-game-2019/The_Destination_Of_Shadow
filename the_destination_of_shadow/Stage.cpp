#include "Stage.h"

VOID Stage::Scroll()
{
	if (Xinput::GetInstance()->GetStick(STICK::LEFT_X) >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		mountain.SetPlus(0.001f);
		if (mountain.GetSaveTu() >= 1.0f)
		{
			mountain.SetSaveTu(0.0f);
		}
	}
	else if (Xinput::GetInstance()->GetStick(STICK::LEFT_X) <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		mountain.SetMinus(0.001f);
		if (mountain.GetSaveTu() <= -1.0f)
		{
			mountain.SetSaveTu(0.0f);
		}
	}
}