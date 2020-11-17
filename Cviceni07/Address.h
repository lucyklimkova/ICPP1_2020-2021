#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <iostream>

struct Address {
private:
	std::string _street;
	std::string _city;
	int _zipCode;

public:
	Address();
	Address(std::string street, std::string city, int zipCode);
	friend std::ostream& operator<< (std::ostream& out, const Address& address);
	friend std::istream& operator>> (std::istream& in, Address& address);
};

#endif // !ADDRESS_H
