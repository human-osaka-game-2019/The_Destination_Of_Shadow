/**
* @file Xinput.h
*/

#ifndef XINPUT_H_
#define XINPUT_H_

#include<Windows.h>
#include <Xinput.h>

/**
* @enum TRIGGER
* xBoxコントローラーの左右のトリガー
*/
enum class TRIGGER
{
	//! 左トリガー
	LEFT,
	//! 右トリガー
	RIGHT,
};

/**
* @enum STICK
* xBoxコントローラーの左右スティック、XY軸
*/
enum class STICK
{
	//! 左スティックX軸
	LEFT_X,
	//! 左スティックY軸
	LEFT_Y,
	//! 右スティックX軸
	RIGHT_X,
	//! 右スティックY軸
	RIGHT_Y,
};

/**
* @brief Xboxコントローラーの操作に関するクラス
*/
class Xinput
{
private:

	//　コントローラーの状態
	XINPUT_STATE XinputState;

	//	バイブレーションの強さ
	XINPUT_VIBRATION XinputVibration;

	Xinput(const Xinput&);

	Xinput& operator =(const Xinput&);

	static Xinput* instance;

	Xinput(){}

public:

	/**
	* @brief Xinputのインスタンスをゲットする
	*/
	static Xinput* GetInstance()
	{
		if (instance == NULL)
			instance = new Xinput;
		return instance;
	}
	/**
	* @brief インスタンスを破棄
	*/
	static VOID Destroy()
	{
		delete instance;
		instance = NULL;
	}
	/**
	* @brief xBoxコントローラーの左モーターの強さをセット
	* @param power モーターの強さ。最大65535 
	*/
	inline VOID SetVibrationLeft(INT power) { XinputVibration.wLeftMotorSpeed = power; }
	/**
	* @brief xBoxコントローラーの右モーターの強さをセット
	* @param power モーターの強さ。最大65535
	*/
	inline VOID SetVibrationRight(INT power) { XinputVibration.wRightMotorSpeed = power; }
	/**
	* @brief XINPUT_VIBRATIONのゲット関数
	*/
	inline XINPUT_VIBRATION GetXinputVibration() const { return XinputVibration; }
	/**
	* @brief xBoxコントローラーのボタン状態を取得
	*/
	inline auto GetBotton() const { return XinputState.Gamepad.wButtons; }
	/**
	* @brief xBoxコントローラーのトリガー状態を取得
	* @param trigger 左右どちらか
	*/
	inline BYTE GetTriggrt(TRIGGER trigger)  const
	{
		switch (trigger)
		{
		case TRIGGER::LEFT:
			return XinputState.Gamepad.bLeftTrigger;
		case TRIGGER::RIGHT:
			return XinputState.Gamepad.bRightTrigger;
		}
	}
	/**
	* @brief xBoxコントローラーのスティック状態を取得
	* @param stick 左右、XYどちらか
	*/
	inline SHORT GetStick(STICK stick) const
	{
		switch (stick)
		{
		case STICK::LEFT_X:
			return XinputState.Gamepad.sThumbLX;
		case STICK::LEFT_Y:
			return XinputState.Gamepad.sThumbLY;
		case STICK::RIGHT_X:
			return XinputState.Gamepad.sThumbRX;
		case STICK::RIGHT_Y:
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

