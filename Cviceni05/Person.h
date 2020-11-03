#ifndef PERSON_H
#define PERSON_H
#include <string>

namespace Entity {
	class Person {
		std::string name;
		std::string phone;
		int id{};
	public:	
		std::string GetName();
		std::string GetPhone();
		int GetId();
		void SetName(std::string name);
		void SetPhone(std::string phone);
		void SetId(int id);
	
	};
}

#endif // !PERSON_H