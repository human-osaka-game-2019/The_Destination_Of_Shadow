#include"DirectX.h"

class CHARACTER_BASE 
{
protected:
	INT hp;
	FLOAT width;
	FLOAT height;
	FLOAT move_speed;

	virtual VOID Move();

};