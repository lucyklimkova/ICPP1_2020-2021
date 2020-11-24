#include "Person.h"
#include "Address.h"
#include "Date.h"
#include <fstream>
#include <sstream>

void save() {
	Person listOfPersons[3];

	Date date1(1, 1, 2000);
	Address address1("Main street", "New York", 1);
	Person person1("John", "Doe", address1, date1);
	listOfPersons[0] = person1;

	Date date2(2, 2, 2005);
	Address address2("Prime street", "Las Vegas", 2);
	Person person2("Jack", "Stark", address2, date2);
	listOfPersons[1] = person2;

	Date date3(3, 3, 1970);
	Address address3("New street", "Chicago", 3);
	Person person3("Peter", "Pan", address3, date3);
	listOfPersons[2] = person3;

	std::ofstream writeOut;
	writeOut.open("outputFile.txt");
	for (int i = 0; i < 3; i++) {
		writeOut << listOfPersons[i] << std::endl;
	}

	writeOut.close();
}

void load() {
	int numberOfLines = 0;
	std::string line;
	std::ifstream read("outputFile.txt");

	while (std::getline(read, line)) {
		++numberOfLines;
	}

	Person* listOfPersons = new Person[numberOfLines];
	read.clear();
	read.seekg(0);

	for (int i = 0; i < numberOfLines; i++) {
		std::getline(read, line);
		std::istringstream stream(line);
		Person newPerson;
		stream >> newPerson;
		listOfPersons[i] = newPerson;
	}

	for (int i = 0; i < numberOfLines; i++) {
		std::cout << listOfPersons[i] << std::endl;
	}

	delete[] listOfPersons;
	read.close();
	
}

void saveToBin() {
	
	Person listOfPersons[3];

	Date date1(1, 1, 2000);
	Address address1("Main street", "New York", 1);
	Person person1("John", "Doe", address1, date1);
	listOfPersons[0] = person1;

	Date date2(2, 2, 2005);
	Address address2("Prime street", "Las Vegas", 2);
	Person person2("Jack", "Stark", address2, date2);
	listOfPersons[1] = person2;

	Date date3(3, 3, 1970);
	Address address3("New street", "Chicago", 3);
	Person person3("Peter", "Pan", address3, date3);
	listOfPersons[2] = person3;

	std::ofstream writeBinFile("outputFile.dat", std::ios::out | std::ios::binary);
	for (int i = 0; i < 3; i++) {
		writeBinFile.write((char*)&listOfPersons[i], sizeof(Person));
	}

	writeBinFile.close();
}

void loadFromBin() {

	std::ifstream readBinFile("outputFile.dat", std::ios::out | std::ios::binary);

	readBinFile.seekg(0, std::ios::end);
	int size = readBinFile.tellg() / sizeof(Person);
	Person* persons = new Person[size];
	readBinFile.seekg(0);

	for (int i = 0; i < size; i++) {
		readBinFile.read((char*)&persons[i], sizeof(Person));		
	}		

	for (int i = 0; i < size; i++) {
		std::cout << persons[i] << std::endl;
	}
	readBinFile.close();
		
}

int main(char** argv, int argc) {
	std::cout << "Load txt file: " << std::endl;
	save();
	load();

	std::cout << "Load BIN file:" << std::endl;
	saveToBin();
	loadFromBin();

	system("pause");
	return 0;
}