#include <iostream>
#include "Matrix.h";


int main() {
	Matrix<int> m{ 3,3 };
	int jednodpole[] = { 0,1,2,3,4,5,6,7,8 };
	m.SetZ(jednodpole);
	Matrix<int> mt = m.Transposition();
	Matrix<int> mmt = m.Product(mt);
	Matrix<double> mmt_d = mmt.Cast<double>();
	Matrix<double> n_d{ 3,3 };
	double jednodpole_d[] = { 4.5,5,0,2,-0.5,7,1.5,9,6 };
	n_d.SetZ(jednodpole_d);
	Matrix<double> mmtn_d = mmt_d.Product(n_d);
	Matrix<int> r = mmtn_d.Cast<int>();
	Matrix<int> t{ 3,3 };
	int tpole[] = { 85,225,236,292,819,866,499,1413,1496 };
	t.SetZ(tpole);
	std::cout << "r==t ? " << (r.IsTheSame(t) ? "true" : "false") << std::endl;
	return 0;
}