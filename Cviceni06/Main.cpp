#include "GrowingContainer.h"
#include <iostream>
#include <string>


int main(char** argv, int argc) {

	GrowingContainer<std::string, 5> container;


	container.Add("String1");
	container.Add("String2");
	container.Add("String3");
	container.Add("String4");
	container.Add("String5");

	std::cout << "Pocet prvku je: " << container.count() << std::endl;
	std::cout << "Prvek na pozici 1 je: " << container[0] << std::endl;
	std::cout << "Prvek na pozici 5 je: " << container[4] << std::endl;

	try {
		std::cout << container[10] << std::endl;
	}
	catch (...) {
		std::cout << "Error, out of range" << std::endl;
	}

	std::cout << "Adresa prvku 1 je: " << &container[0] << std::endl;

	//try {
	//	growingContainer.operator[](10);
	//}
	//catch (...) {
	//}
	

	return 0;
}