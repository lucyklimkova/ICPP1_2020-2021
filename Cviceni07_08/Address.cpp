#include "Address.h"


Address::Address(std::string street, std::string city, int zipCode) {
	_street = street;
	_city = city;
	_zipCode = zipCode;
}

Address::Address() {

}

Address::~Address() {

}

std::ostream& operator<<(std::ostream& out, const Address& address) {
	out << address._street << " " << address._city << " " << address._zipCode;
	return out;
}

std::istream& operator>>(std::istream& in, Address& address) {
	in >> address._street >> address._city >> address._zipCode;
	return in;
}