#ifndef SHADOW_GIMMICK_H_
#define SHADOW_GIMMICK_H_

#include "Object.h"

class ShadowGimmick :public Object
{
private:

	SHADOW_GIMMICK_ID m_id = SHADOW_GIMMICK_ID::NO_ID;
	BOOL m_is_settled = FALSE;

	VOID InitBotton();
	VOID InitDoor();
public:

	ShadowGimmick(FLOAT x,FLOAT y, SHADOW_GIMMICK_ID id);
	virtual ~ShadowGimmick() {}

	inline SHADOW_GIMMICK_ID GetId() { return m_id; }
	inline BOOL GetGimmickSettled() { return m_is_settled; }
	BOOL IsHitCursor(XyCoordinate cursor);
	BOOL IsSettledBoton();
	VOID GimmickSettl();
};

#endif // !SHADOW_GIMMICK_H_

