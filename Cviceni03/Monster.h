#ifndef MONSTER_H
#define MONSTER_H
#include "MovableObject.h"

class Monster : public MovableObject {
	int hp;
	int maxhp;
public:
	Monster(int id) : MovableObject(id) { hp = maxhp = 0.0; };
	~Monster() { };
	int GetHp() const;
	void SetHp(int hp);
	int GetMaxHp() const;
	void SetMaxHp(int maxhp);
};

#endif // !MONSTER_H
