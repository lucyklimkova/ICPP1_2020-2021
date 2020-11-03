#ifndef IOBJECT_H
#define IOBJECT_H
#include <string>

class IObject {
public:
	virtual ~IObject() {};
	virtual std::string ToString() const = 0;
};

#endif // !IOBJECT_H

