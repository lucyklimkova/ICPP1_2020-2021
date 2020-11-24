#include "Date.h"

Date::Date(int day, int month, int year) {
	_day = day;
	_month = month;
	_year = year;
}


Date::Date() {
}

Date::~Date() {
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
	out << date._day << ". " << date._month << ". " << date._year;
	return out;
}

std::istream& operator>>(std::istream& in, Date& date) {

	char ch;
	in >> date._day >> ch >> date._month >> date._year;
	return in;
}
