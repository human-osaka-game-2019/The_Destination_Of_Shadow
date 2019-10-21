#include "DirectX.h"
#include "Character.h"

class Player :public CharacterBase
{
public:
	FLOAT acceleration;
	FLOAT work_speed;
	FLOAT max_speed;
	
	VOID Attack();
	VOID ShadowInstallation();

};