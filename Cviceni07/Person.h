#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "Address.h"
#include "Date.h"

struct Person {
private:
	std::string _firstName;
	std::string _lastName;
	Address _placeOfResidence;
	Date _dateOfBirth;

public:
	Person();
	Person(std::string firstName, std::string lastName, Address placeOfResidence, Date dateOfBirth);
	friend std::ostream& operator<< (std::ostream& out, const Person& person);
	friend std::istream& operator>> (std::istream& in, Person& person);
};

#endif // !PERSON_H