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
enum TRIGGER
{
	//! 左トリガー
	LEFT_TRIGGER,
	//! 右トリガー
	RIGHT_TRIGGER,
};

/**
* @enum STICK
* xBoxコントローラーの左右スティック、XY軸
*/
enum STICK
{
	//! 左スティックX軸
	LEFT_X_STICK,
	//! 左スティックY軸
	LEFT_Y_STICK,
	//! 右スティックX軸
	RIGHT_X_STICK,
	//! 右スティックY軸
	RIGHT_Y_STICK,
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

	/**
	* @brief xBoxコントローラーのスティック状態を取得
	* @param stick 左右、XYどちらか
	*/
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

