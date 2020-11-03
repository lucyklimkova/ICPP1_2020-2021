#include "PhoneNumbersList.h"
#include <stdexcept>


Model::PhoneNumbersList::PhoneNumbersList() {
	_firstElement = NULL;
	_lastElement = NULL;
}

void Model::PhoneNumbersList::addPerson(Entity::Person person)
{
	Element* element = new Element;
	element->person = person;
	element->nextElement = NULL;

	if (_firstElement == NULL) {
		_firstElement = element;
		_lastElement = element;
	}
	else {
		_lastElement->nextElement = element;
		_lastElement = _lastElement->nextElement;
	}
}

std::string Model::PhoneNumbersList::findPhoneNumber(std::string name) const {
	if (name.empty()) {
		throw std::invalid_argument("Name is empty");
	}

	Element* newElement;
	newElement = _firstElement;
	while (newElement != NULL) {
		if (newElement->person.GetName() == name)
			return newElement->person.GetPhone();
		newElement = newElement->nextElement;
	}
	if (newElement == NULL) {
		throw std::runtime_error("Phone number not found");
	}
}

std::string Model::PhoneNumbersList::findPhoneNumber(int id) const {
	if (id < 0) {
		throw std::invalid_argument("Received a negative value");
	}

	Element* newElement;
	newElement = _firstElement;
	while (newElement != NULL) {
		if (newElement->person.GetId() == id)
			return newElement->person.GetPhone();
		newElement = newElement->nextElement;
	}
	if (newElement == NULL) {
		throw std::runtime_error("Phone number not found");
	}
}
