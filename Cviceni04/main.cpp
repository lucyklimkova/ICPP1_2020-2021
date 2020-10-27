#include <iostream>
#include <time.h>
#include <cstdlib>
#include "IComparable.h"
#include "Time.h"

#define SIZE 10

void SortArray(IComparable** array, int sizeOfArray) {
	for (int i = 0; i < sizeOfArray; i++) {
		for (int j = i + 1; j < sizeOfArray; j++) {
			if (array[i]->CompareTo(array[j]) == 1) {
				IComparable* temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

int main(char** argc, int argv) {
	srand(time(NULL));
	IComparable** newArray = new IComparable * [SIZE];
	for (int i = 0; i < SIZE; i++) {
		int h = rand() % (23);
		int m = rand() % (59);
		int s = rand() % (59);
		newArray[i] = new Time(h,m,s);
	}

	SortArray(newArray, SIZE);

	std::cout << "Printing times from and array: " << std::endl;
	for (int i = 0; i < SIZE; i++) {
		std::cout << "Time on position " << i <<" is: " << newArray[i]->ToString() << std::endl;
	}
}