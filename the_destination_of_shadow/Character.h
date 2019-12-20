#ifndef CHARACTER_H
#define CHARACTER_H

#include"Object.h"
#include"DirectX.h"

/**
* @brief PlayerとEnemyの親class
*/
class CharacterBase : public ScrollObject
{
public:

	/**
   * @enum ANIMETION_TYPE
   * キャラクターアニメーション各種
   */
	enum class ANIMETION_TYPE
	{
		IDLE,
		WALK,
		DASH,
		ATTACK,
		DIED,
		JUMP,
		ENTER
	};

	struct AnimetionTu
	{
		float m_start;
		float m_finish;
		AnimetionTu(float start, float finish):m_start(start),m_finish(finish) {};
	};

	struct AnimetionTv
	{
		float m_start;
		float m_finish;
		AnimetionTv(float start, float finish) :m_start(start), m_finish(finish) {};
	};

	struct AnimetionCount
	{
		int fc_animetion_type;
		int m_count;
		AnimetionCount(int animetion_type, int count) :fc_animetion_type(animetion_type), m_count(count) {};
	};

	/**
	* @brief キャラクターを動かす
	* @note 各派性クラスにて動作を書く
	*/
	virtual VOID Move() = 0;
protected:

	INT m_hp;
	FLOAT m_move_speed;
	DIRECTION m_save_direction;
};

#endif


