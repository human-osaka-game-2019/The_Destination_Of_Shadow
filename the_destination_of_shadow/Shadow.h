#ifndef SHADOW_H_
#define SHADOW_H_

#include "Object.h"

class Shadow : public Object
{
private:

public:
	/**
	* @brief カーソルの位置とギミックの種類と大きさによって変数を初期化する
	* @note 実装途中
	*/
	Shadow(XyCoordinate gimmick, XyCoordinate cursor);
	virtual ~Shadow() {};
};

#endif // !SHADOW_H_
