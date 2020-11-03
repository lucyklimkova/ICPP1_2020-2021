#include <iostream>
#include "PhoneNumbersList.h"
#include "Person.h"

int main(char** argv, int argc) {

	Model::PhoneNumbersList phoneNumbersList;
	Entity::Person person;
	Entity::Person person2;
	person.SetId(1);
	person.SetName("Pepa");
	person.SetPhone("730550600");
	person2.SetId(2);
	person2.SetName("Franta");
	person2.SetPhone("777111225");
	phoneNumbersList.addPerson(person);
	phoneNumbersList.addPerson(person2);

	try {
		std::cout << phoneNumbersList.findPhoneNumber("test2a") << std::endl;
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}


	try {
		std::cout << phoneNumbersList.findPhoneNumber(-10) << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}


	try {
		std::cout << phoneNumbersList.findPhoneNumber("") << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << phoneNumbersList.findPhoneNumber("Pepa") << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << phoneNumbersList.findPhoneNumber(1) << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}
	catch (const std::runtime_error& e2) {
		std::cout << e2.what() << std::endl;
	}


	return 0;
}