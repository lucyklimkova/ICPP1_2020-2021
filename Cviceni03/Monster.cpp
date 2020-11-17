#include "Monster.h"

int Monster::GetHp() const {
	return hp;
}

void Monster::SetHp(int hp) {
	this->hp = hp;
}

int Monster::GetMaxHp() const {
	return maxhp;
}

void Monster::SetMaxHp(int maxhp) {
	this->maxhp = maxhp;
}