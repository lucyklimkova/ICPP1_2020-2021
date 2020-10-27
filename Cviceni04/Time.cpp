#include "Time.h"

Time::Time(int hour, int minute, int second) {
	_hour = hour;
	_minute = minute;
	_second = second;
}

int Time::CompareTo(IComparable* object) const {

	Time* time = dynamic_cast<Time*>(object);
	int firstRes = time->_hour * 3600 + time->_minute * 60 + time->_second;
	int secondRes = _hour * 3600 + _minute * 60 + _second;
	if (firstRes == secondRes) {
		return 0;
	}
	else if (secondRes < firstRes) {
		return -1;
	}
	else {
		return 1;
	}
}

std::string Time::ToString() const {
	return std::to_string(_hour) + ':' + std::to_string(_minute) + ':' + std::to_string(_second);
}