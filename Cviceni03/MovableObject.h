#ifndef MOVABLE_OBJECT_H
#define MOVABLE_OBJECT_H
#include "Object.h"
#define _USE_MATH_DEFINES
#include <cmath>

class MovableObject : public Object {
	double angleOfRotation;
public:
	MovableObject(int id) : Object(id) { angleOfRotation = 0; };
	~MovableObject() { };
	double GetAngleOfRotation();
	void SetAngleOfRotation(double angleOfRotation);
};

#endif // !MOVABLE_OBJECT_H
