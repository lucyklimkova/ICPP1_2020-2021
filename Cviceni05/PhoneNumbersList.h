#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <string>
#include "Person.h"

namespace Model {
	class PhoneNumbersList {

		struct Element {
			Entity::Person person;
			Element* nextElement = NULL;
		};

		Element* _firstElement;
		Element* _lastElement;
	public:
		PhoneNumbersList();
		~PhoneNumbersList();
		void addPerson(Entity::Person person);
		std::string findPhoneNumber(std::string name) const;
		std::string findPhoneNumber(int id) const;
	};
}

#endif // !PHONEBOOK_H