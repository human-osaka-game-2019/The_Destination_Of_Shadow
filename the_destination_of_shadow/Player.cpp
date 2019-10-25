#include "Main.h"
#include "Player.h"

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
	
	if (directx.XinputState.Gamepad.sThumbLX >= directx.game_pad_dead_zone.RIGHT)
	{
		*player_x += m_work_speed;

	}

	else if (directx.XinputState.Gamepad.sThumbLX <= -directx.game_pad_dead_zone.LEFT)
	{
		*player_x -= m_work_speed;

	}

}

