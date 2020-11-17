#include "StaticObject.h"

StaticObject::StaticObject(int id, BarrierType barrierType) : Object(id) {
	this->barrierType = barrierType;
}

BarrierType StaticObject::GetBarrierType() const {
	return barrierType;
}