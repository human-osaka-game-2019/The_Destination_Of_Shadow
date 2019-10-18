#include "DirectX.h"
#include "Character.h"

class PLAYER :public CHARACTER_BASE
{
public:
	FLOAT acceleration;
	FLOAT work_speed;
	FLOAT max_speed;
	
	VOID Attack();
	VOID ShadowInstallation();

};