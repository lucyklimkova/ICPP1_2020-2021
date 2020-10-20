#include "MovableObject.h"

double MovableObject::GetAngleOfRotation() {
	return angleOfRotation;
}

void MovableObject::SetAngleOfRotation(double angleOfRotation) {
	
	while (angleOfRotation > 2 * M_PI)
		angleOfRotation = angleOfRotation - (2 * M_PI);

	while (angleOfRotation < 0) {
		angleOfRotation = angleOfRotation + (2 * M_PI);
	}

	this->angleOfRotation = angleOfRotation;
}