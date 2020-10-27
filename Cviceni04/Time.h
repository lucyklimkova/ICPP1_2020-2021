#ifndef TIME_H
#define TIME_H
#include <string>
#include "IComparable.h"

class Time : virtual public IComparable {
private:
	int _hour;
	int _minute;
	int _second;

public:
	Time(int hour, int minute, int second);
	virtual std::string ToString() const;
	int CompareTo(IComparable* object) const;
};

#endif // !TIME_H
