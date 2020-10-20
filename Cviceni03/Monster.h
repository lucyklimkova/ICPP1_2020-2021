#ifndef MONSTER_H
#define MONSTER_H
#include "MovableObject.h"

class Monster : public MovableObject {
	int hp;
	int maxhp;
public:
	Monster(int id) : MovableObject(id) { hp = maxhp = 0; };
	~Monster() { };
	int GetHp();
	void SetHp(int hp);
	int GetMaxHp();
	void SetMaxHp(int maxhp);
};

#endif // !MONSTER_H
