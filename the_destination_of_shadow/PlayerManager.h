#ifndef PLAYER_MANAGER_H_
#define PLAYER_MANAGER_H_

#include "Player.h"
#include "Cursor.h"

class PlayerManager
{
private:

	Player* player;

	Cursor* cursor;

public:

	VOID Move();
	VOID Draw();
	PlayerManager();
	~PlayerManager();

};

#endif // !PLAYER_MANAGER_H_

