#include "DirectX.h"
#include "Character.h"

class WalkingEnemy :public CharacterBase
{
public:
	VOID Move();

};

class FlyingEnemy :public CharacterBase
{
public:
	VOID Move();

};
