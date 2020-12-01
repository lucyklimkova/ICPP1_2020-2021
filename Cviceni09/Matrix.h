#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <stdexcept>


template<typename T> class Matrix {
private:
	T** arrayMatrix;
	int rows;
	int columns;

public:
	Matrix(int rows, int columns);
	Matrix(const Matrix<T>& m);
	~Matrix();
	void Set(int row, int column, T value);
	void SetZ(T* array);
	T& Get(int row, int column) const;
	template<typename R> Matrix<R> Cast() const;
	Matrix Transposition() const;
	Matrix Product(const Matrix& m) const;
	Matrix Product(T scalar) const;
	Matrix Sum(const Matrix& m) const;
	Matrix Sum(T scalar) const;
	bool IsTheSame(const Matrix& m) const;
	void Print() const;
};

template<typename T>
Matrix<T>::Matrix(int rows, int columns) {
	this->rows = rows;
	this->columns = columns;
	this->arrayMatrix = new T * [rows];

	for (int i = 0; i < rows; i++) {
		arrayMatrix[i] = new T[columns];
		for (int j = 0; j < columns; j++) {
			arrayMatrix[i][j] = 0;
		}
	}
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& m) {

	rows = m.rows;
	columns = m.columns;
	arrayMatrix = new T * [rows];
	for (int i = 0; i < rows; i++) {
		arrayMatrix[i] = new T[columns];
		for (int j = 0; j < columns; j++) {
			arrayMatrix[i][j] = m.arrayMatrix[i][j];
		}
	}
}

template<typename T>
Matrix<T>::~Matrix() {

	for (int i = 0; i < rows; i++) {
		delete[] arrayMatrix[i];
	}
	delete[] arrayMatrix;
}

template<typename T>
void Matrix<T>::Set(int row, int column, T value) {

	if (row < 0 || row > rows) {
		throw std::out_of_range("This row is out of range!");
	}
	if (column < 0 || column > columns) {
		throw std::out_of_range("This column is out of range!");
	}

	arrayMatrix[row][column] = value;
}

template<typename T>
void Matrix<T>::SetZ(T* array) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			this->arrayMatrix[i][j] = array[(i * columns) + j];
		}
	}
}

template<typename T>
T& Matrix<T>::Get(int row, int column) const {

	if (row < 0 || row > rows) {
		throw std::out_of_range("This row is out of range!");
	}
	if (column < 0 || column > columns) {
		throw std::out_of_range("This column is out of range!");
	}

	return arrayMatrix[row][column];
}


template<typename T>
Matrix<T> Matrix<T>::Transposition() const {

	Matrix<T> newMatrix { columns, rows };

	for (int i = 0; i < newMatrix.rows; i++) {
		for (int j = 0; j < newMatrix.columns; j++) {
			newMatrix.arrayMatrix[i][j] = arrayMatrix[j][i];
		}
	}
	return newMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::Product(const Matrix& m) const {

	if (columns != m.rows) {
		throw std::invalid_argument("Cannot multiply this two matrix!");
	}

	Matrix<T> newMatrix{ rows, columns };

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < m.columns; j++) {
			T newValue = 0;
			for (int k = 0; k < m.rows; k++) {
				newValue += arrayMatrix[i][k] * m.arrayMatrix[k][j];
			}
			newMatrix.arrayMatrix[i][j] = newValue;
		}
	}
	return newMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::Product(T scalar) const {

	Matrix<T> newMatrix { rows, columns };

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.arrayMatrix[i][j] = arrayMatrix[i][j] * scalar;
		}
	}

	return newMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::Sum(const Matrix& m) const {

	if (rows != m.rows || columns != m.columns) {
		throw std::invalid_argument("Cannot sum this two matrix!");
	}

	Matrix<T> newMatrix { rows, columns };
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.arrayMatrix[i][j] = m.arrayMatrix[i][j] + arrayMatrix[i][j];
		}
	}

	return newMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::Sum(T scalar) const {

	Matrix<T> newMatrix { rows, columns };
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.arrayMatrix[i][j] = arrayMatrix[i][j] + scalar;
		}
	}

	return newMatrix;
}

template<typename T>
bool Matrix<T>::IsTheSame(const Matrix& m) const {

	if (rows != m.rows || columns != m.columns) return false;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (arrayMatrix[i][j] != m.arrayMatrix[i][j])
				return false;
		}
	}

	return true;
}

template<typename T>
void Matrix<T>::Print() const {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << arrayMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

template<typename T>
template<typename R>
Matrix<R> Matrix<T>::Cast() const {

	Matrix<R> newMatrix { rows, columns };

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newMatrix.Set(i, j, static_cast<R>(Get(i, j)));
		}
	}

	return newMatrix;
}


#endif // !MATRIX_H
