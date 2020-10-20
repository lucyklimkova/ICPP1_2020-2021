#include <iostream>
#include "Game.h"
#include "Monster.h"
#include "StaticObject.h"
#include "MovableObject.h"

int main() {

	Game newGame;

	StaticObject* rock = new StaticObject(8, Rock);
	rock->SetX(10);
	rock->SetY(10);

	StaticObject* plant = new StaticObject(4, SmallPlant);
	rock->SetX(6);
	rock->SetY(6);

	Monster* monster = new Monster(1);
	monster->SetX(3);
	monster->SetY(3);
	monster->SetHp(15);
	monster->SetMaxHp(20);
	monster->SetAngleOfRotation(4);

	Monster* monster2 = new Monster(2);
	monster2->SetX(2);
	monster2->SetY(2);
	monster2->SetHp(5);
	monster2->SetMaxHp(10);
	monster2->SetAngleOfRotation(2);

	newGame.InsertObject(rock);
	newGame.InsertObject(monster);
	newGame.InsertObject(plant);
	newGame.InsertObject(monster2);

	int* idsOfStaticObj = newGame.FindIdsOfStaticObjects(-10, 10, -10, 10);

	std::cout << "----Finding objects in Game----" << std::endl;
	std::cout << "Static objects are the ones with ID: " << std::endl;
	for (int i = 0; i < newGame.GetNumberOfStaticObjects(); i++) {
		std::cout << idsOfStaticObj[i] << "  ";
	}
	std::cout << std::endl;

	MovableObject** movableObjects = newGame.FindMovableObjectsInArea(0, 0, 20, 0, 10);

	std::cout << "Movable objects are the ones with ID: " << std::endl;
	for (int i = 0; i < newGame.GetNumberOfMovableObjectsRotating(); i++) {
		std::cout << movableObjects[i]->GetId() << "  ";
	}
	std::cout << std::endl;

	delete rock, monster, plant, monster2;

	return 0;
}