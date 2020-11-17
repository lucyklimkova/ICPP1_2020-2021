#ifndef GROWINGCONTAINER_H
#define GROWINGCONTAINER_H
#include <exception>
#include <iostream>

template<typename DataType, int initSize = 5>
class GrowingContainer {
public:
	GrowingContainer();
	~GrowingContainer();
	void Add(const DataType& o);
	DataType& operator[](int index);
	DataType operator[](int index) const;
	unsigned int count() const;
	void setGrowCoeficient(int coeficient);
private:
	DataType* _array;
	unsigned _arraySize;
	unsigned _countOfValidElements;
	unsigned growCoeficient = 2;
	bool isThereAFreeSpaceInArray() const;
	void expandArray();
};


template<typename DataType, int initSize>
GrowingContainer<DataType, initSize>::GrowingContainer() {
	_array = new DataType[initSize];
	_arraySize = initSize;
	_countOfValidElements = 0;
}

template<typename DataType, int initSize>
GrowingContainer<DataType, initSize>::~GrowingContainer() {
	delete[] _array;
}


template<typename DataType, int initSize>
void GrowingContainer<DataType, initSize>::Add(const DataType& o) {
	if (_countOfValidElements == _arraySize) {
		expandArray();
	}
	_array[_countOfValidElements++] = o;
}

template<typename DataType, int initSize>
DataType& GrowingContainer<DataType, initSize>::operator[](int index) {
	if (index >= _countOfValidElements) {
		throw std::out_of_range("This index is out of range");
	}
	return _array[index];
}

template<typename DataType, int initSize>
DataType GrowingContainer<DataType, initSize>::operator[](int index) const {
	if (index >= _countOfValidElements) {
		throw std::out_of_range("This index is out of range");
	}	
	return _array[index];
}

template<typename DataType, int initSize>
unsigned int GrowingContainer<DataType, initSize>::count() const {
	return _countOfValidElements;
}


template<typename DataType, int initSize>
bool GrowingContainer<DataType, initSize>::isThereAFreeSpaceInArray() const {
	if (_countOfValidElements < _arraySize) {
		return true;
	}
	return false;
}

template<typename DataType, int initSize>
void GrowingContainer<DataType, initSize>::expandArray() {
	if (isThereAFreeSpaceInArray()) {
		return;
	}

	DataType* newArray = new DataType[_arraySize * growCoeficient];

	for (int i = 0; i < _countOfValidElements; i++) {
		newArray[i] = _array[i];
	}

	delete[] _array;
	_array = newArray;
	_arraySize = _arraySize * growCoeficient;
}

template<typename DataType, int initSize>
void GrowingContainer<DataType, initSize>::setGrowCoeficient(int coeficient) {
	growCoeficient = coeficient;
}

#endif // !GROWINGCONTAINER_H