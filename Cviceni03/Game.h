#ifndef GAME_H
#define GAME_H
#include "Object.h"
#include "MovableObject.h"

class Game {
	int* arrayOfIds;
	Object** arrayOfObjects;
	MovableObject** arrayOfMovableObjects;
	MovableObject** arrayOfMovableObjectsRotating;

	int numberOfStaticObjects;
	int numberOfMovableObjects;
	int numberOfMovableObjectsRotating;
	int arrayCounter;

public:
	Game();
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

