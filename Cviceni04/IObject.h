#ifndef IOBJECT_H
#define IOBJECT_H
#include <string>
#include "IComparable.h"

class IObject : public IComparable {
public:
	virtual ~IObject() = 0;
	virtual std::string ToString() const = 0;
};

#endif // !IOBJECT_H

