#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H
#include "Object.h"

enum BarrierType { 
	Rock, SmallPlant, BigPlant 
};

class StaticObject : public Object {
	BarrierType barrierType;
public:
	StaticObject(int id, BarrierType barrierType);
	~StaticObject() { };
	BarrierType GetBarrierType();
};

#endif // !STATIC_OBJECT_H
