#include <iostream>

struct Triangle {
	int a, b, c;
};

bool canTriangleBeConstructed(Triangle triangle) {
	return triangle.a + triangle.b > triangle.c && triangle.a + triangle.c > triangle.b && triangle.b + triangle.c > triangle.a;
}

int main(int argc, char** argv) {
	std::cout << "How many triangles do you want to work with:  " << std::endl;
	int numberOfTriangles = 0;
	std::cin >> numberOfTriangles;


	Triangle* triangles = new Triangle[numberOfTriangles];

	for (int i = 0; i < numberOfTriangles; i++) {
		std::cout << "Fill in the side a for the triangle with id " << (i + 1) << ": ";
		std::cin >> triangles[i].a;
		std::cout << "Fill in the side b for the triangle with id  " << (i + 1) << ": ";
		std::cin >> triangles[i].b;
		std::cout << "Fill in the side c for the triangle with id  " << (i + 1) << ": ";
		std::cin >> triangles[i].c;

		if (canTriangleBeConstructed(triangles[i])) {
			int circumference = triangles[i].a + triangles[i].b + triangles[i].c;
			std::cout << "Circumference of this triangle is: " << circumference << std::endl;
		}
		else {
			std::cout << "This triangle cannot be constructed" << std::endl;
		}
	}

	delete[] (triangles);
	return 0;
}