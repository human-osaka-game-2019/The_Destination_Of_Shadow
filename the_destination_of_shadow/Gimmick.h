#ifndef GIMMICK_H_
#define GIMMICK_H_

#include "Object.h"

enum class GIMMICK_ID
{
	NO_ID,
	BUILDING,
};

class Gimmick : public Object
{
private:

	GIMMICK_ID m_id = GIMMICK_ID::NO_ID;
	BOOL m_is_shadow = TRUE;

public:

	Gimmick(FLOAT x, FLOAT y, GIMMICK_ID id) {}
	virtual ~Gimmick() {}
	VOID InitBuilding(FLOAT x, FLOAT y);
	VOID MakeTransparent();
};

#endif // !GIMMICK_H_

