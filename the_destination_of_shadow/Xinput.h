#ifndef XINPUT_H_
#define XINPUT_H_

#include<Windows.h>
#include <Xinput.h>

enum TRIGGER
{
	LEFT_TRIGGER,
	RIGHT_TRIGGER,
};

enum STICK
{
	LEFT_X_STICK,
	LEFT_Y_STICK,
	RIGHT_X_STICK,
	RIGHT_Y_STICK,
};

class Xinput
{
private:

	//　コントローラーの状態
	XINPUT_STATE XinputState;

	//	バイブレーションの強さ
	XINPUT_VIBRATION XinputVibration;

public:

	inline VOID SetVibrationLeft(INT power) { XinputVibration.wLeftMotorSpeed = power; }

	inline VOID SetVibrationRight(INT power) { XinputVibration.wRightMotorSpeed = power; }

	inline XINPUT_VIBRATION GetXinputVibration() const { return XinputVibration; }

	inline auto GetBotton() const { return XinputState.Gamepad.wButtons; }

	inline auto GetTriggrt(TRIGGER trigger)  const
	{
		switch (trigger)
		{
		case LEFT_TRIGGER:
			return XinputState.Gamepad.bLeftTrigger;
		case RIGHT_TRIGGER:
			return XinputState.Gamepad.bRightTrigger;
		}
	}

	inline auto GetStick(STICK stick) const
	{
		switch (stick)
		{
		case LEFT_X_STICK:
			return XinputState.Gamepad.sThumbLX;
		case LEFT_Y_STICK:
			return XinputState.Gamepad.sThumbLY;
		case RIGHT_X_STICK:
			return XinputState.Gamepad.sThumbRX;
		case RIGHT_Y_STICK:
			return XinputState.Gamepad.sThumbRY;
		}
	}

	/**
	* @brief Xboxコントローラーの状態を更新する関数
	* @return Xboxコントローラーが接続されているならtrueを返す
	*/
	BOOL UpdateControllerState();

};

#endif // !XINPUT_H_

