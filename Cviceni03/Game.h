#ifndef GAME_H
#define GAME_H
#include "Object.h"
#include "MovableObject.h"

class Game {
	int* arrayOfIds = new int[100];
	Object** arrayOfObjects = new Object * [10];
	MovableObject** arrayOfMovableObjects = new MovableObject * [100];
	MovableObject** arrayOfMovableObjectsRotating = new MovableObject * [100];

	int numberOfStaticObjects = 0;
	int numberOfMovableObjects = 0;
	int numberOfMovableObjectsRotating = 0;
	int arrayCounter = 0;

public:
	~Game();
	void InsertObject(Object* o);
	int* FindIdsOfStaticObjects(double xmin, double xmax, double ymin, double ymax);
	MovableObject** FindMovableObjectsInArea(double x, double y, double r);
	MovableObject** FindMovableObjectsInArea(double x, double y, double r, double umin, double umax);
	//getters
	int GetNumberOfStaticObjects();
	int GetNumberOfMovableObjects();
	int GetNumberOfMovableObjectsRotating();
};

#endif // !GAME_H

