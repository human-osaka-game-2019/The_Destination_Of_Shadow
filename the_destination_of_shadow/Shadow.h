#ifndef SHADOW_H_
#define SHADOW_H_

#include "Object.h"

class Shadow : public Object
{
private:

public:
	Shadow(XyCoordinate gimmick, XyCoordinate cursor);
	virtual ~Shadow() {};
};

#endif // !SHADOW_H_
