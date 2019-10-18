#include "DirectX.h"
#include "Character.h"

class WALKING_ENEMY :public CHARACTER_BASE 
{
public:
	VOID Move();

};

class FLYING_ENEMY :public CHARACTER_BASE
{
public:
	VOID Move();
};