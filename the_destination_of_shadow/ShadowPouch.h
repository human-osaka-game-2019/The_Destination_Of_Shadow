#ifndef SHADOW_POUCH_H_
#define SHADOW_POUCH_H_

#include <vector>

#include "Object.h"

class ShadowPouch : public Object
{
private:

	std::vector<GIMMICK_ID>shadow_item{};

public:
	ShadowPouch() {};
	~ShadowPouch() {};
	VOID ShadowStore(GIMMICK_ID id);
};

#endif // !SHADOW_POUCH_H_

