#ifndef GIMMICK_H_
#define GIMMICK_H_

#include "Object.h"

class Gimmick:public Object
{
private:

	BOOL is_shadow = TRUE;

public:

	Gimmick(FLOAT x,FLOAT y);
	virtual ~Gimmick() {}
	VOID MakeTransparent()
};

#endif // !GIMMICK_H_

