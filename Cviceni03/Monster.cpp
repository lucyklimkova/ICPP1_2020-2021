#include "Monster.h"

int Monster::GetHp() {
	return hp;
}

void Monster::SetHp(int hp) {
	this->hp = hp;
}

int Monster::GetMaxHp() {
	return maxhp;
}

void Monster::SetMaxHp(int maxhp) {
	this->maxhp = maxhp;
}