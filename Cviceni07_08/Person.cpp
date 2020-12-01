#include "Person.h"


Person::Person() {
	_firstName = "";
	_lastName = "";
}

Person::~Person() {
}

Person::Person(std::string firstName, std::string lastName, Address placeOfResidence, Date dateOfBirth) {
	_firstName = firstName;
	_lastName = lastName;
	_placeOfResidence = placeOfResidence;
	_dateOfBirth = dateOfBirth;
}

std::ostream& operator<<(std::ostream& out, const Person& person) {
	out << person._firstName << " " << person._lastName << " " << person._placeOfResidence << " " << person._dateOfBirth;
	return out;
}

std::istream& operator>>(std::istream& in, Person& person) {
	in >> person._firstName;
	in >> person._lastName;
	in >> person._placeOfResidence;
	in >> person._dateOfBirth;
	return in;
}
