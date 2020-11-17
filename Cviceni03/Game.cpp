#include <math.h>
#include "Game.h"
#include "StaticObject.h"

#define SIZE 100


Game::Game() {
	arrayOfObjects = new Object * [SIZE];
	arrayOfIds = nullptr;
	arrayOfMovableObjects = nullptr;
	arrayOfMovableObjectsRotating = nullptr;

	numberOfStaticObjects = 0;
	numberOfMovableObjects = 0;
	numberOfMovableObjectsRotating = 0;
	arrayCounter = 0;
}

void Game::InsertObject(Object* obj) {
	if (arrayCounter >= SIZE) {
		throw "This index is too big, not enough space in array";
	}
	arrayOfObjects[arrayCounter++] = obj;
	
}

int* Game::FindIdsOfStaticObjects(double xmin, double xmax, double ymin, double ymax) {
	numberOfStaticObjects = 0;
	arrayOfIds = new int[arrayCounter];
	for (int i = 0; i < arrayCounter; i++) {
		if (dynamic_cast<StaticObject*>(arrayOfObjects[i]) == nullptr) {
			continue;
		}
		
		if ((arrayOfObjects[i]->GetX() > xmin && arrayOfObjects[i]->GetX() < xmax) &&
			(arrayOfObjects[i]->GetY() > ymin && arrayOfObjects[i]->GetY() < ymax)) {
			arrayOfIds[numberOfStaticObjects++] = arrayOfObjects[i]->GetId();
		}
	}

	return arrayOfIds;
}

MovableObject** Game::FindMovableObjectsInArea(double x, double y, double r)
{
	numberOfMovableObjects = 0;
	arrayOfMovableObjects = new MovableObject * [arrayCounter];
	for (int i = 0; i < arrayCounter; i++) {
		if (dynamic_cast<MovableObject*>(arrayOfObjects[i]) == nullptr) {
			continue;
		}
			
		if (sqrt(pow(abs(arrayOfObjects[i]->GetX() - x), 2.0) + 
				pow(abs(arrayOfObjects[i]->GetY() - y), 2.0)) < r) {
			arrayOfMovableObjects[numberOfMovableObjects++] = (MovableObject*)arrayOfObjects[i];
		}
	}

	return arrayOfMovableObjects;
}

MovableObject** Game::FindMovableObjectsInArea(double x, double y, double r, double umin, double umax) {
	numberOfMovableObjectsRotating = 0;
	MovableObject** arrayOfObjectsInArea = FindMovableObjectsInArea(x, y, r);
	arrayOfMovableObjectsRotating = new MovableObject * [arrayCounter];

	for (int i = 0; i < GetNumberOfMovableObjects(); i++) {
		if ((arrayOfObjectsInArea[i]->GetAngleOfRotation() < umax) && 
			(arrayOfObjectsInArea[i]->GetAngleOfRotation() > umin)) {
			arrayOfMovableObjectsRotating[numberOfMovableObjectsRotating++] = arrayOfObjectsInArea[i];
		}
	}

	return arrayOfMovableObjectsRotating;

}

int Game::GetNumberOfStaticObjects() const {
	return 	numberOfStaticObjects;
}

int Game::GetNumberOfMovableObjects() const {
	return numberOfMovableObjects;
}

int Game::GetNumberOfMovableObjectsRotating() const {
	return numberOfMovableObjectsRotating;
}


Game::~Game() {

	delete[] arrayOfIds;
	delete[] arrayOfObjects;
	delete[] arrayOfMovableObjects;
	delete[] arrayOfMovableObjectsRotating;

}
