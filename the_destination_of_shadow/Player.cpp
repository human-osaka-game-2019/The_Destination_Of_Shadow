#include "Main.h"
#include "Player.h"


namespace
{
	//! Xboxコントローラー左スティックのデットゾーン
	const FLOAT DEAD_ZONE_LEFT = 7849;

	//! Xboxコントローラー右スティックのデットゾーン
	const FLOAT DEAD_ZONE_RIGHT = 8689;
}

VOID Player::Attack()
{
	return VOID();
}

VOID Player::Move()
{
	return VOID();
}

VOID Player::ShadowInstallation()
{
	return VOID();
}

VOID Player::Move(INT* player_x,Player* player)
{
	
	if (directx.XinputState.Gamepad.sThumbLX >= DEAD_ZONE_RIGHT)
	{
		*player_x += m_work_speed;

	}

	else if (directx.XinputState.Gamepad.sThumbLX <= -DEAD_ZONE_LEFT)
	{
		*player_x -= m_work_speed;

	}

}

