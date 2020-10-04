#include <iostream>

struct Trojuhelnik {
	int a, b, c;
};

bool lzeSestrojit(Trojuhelnik triangle) {
	return triangle.a + triangle.b > triangle.c && triangle.a + triangle.c > triangle.b && triangle.b + triangle.c > triangle.a;
}

int main(int argc, char** argv) {
	std::cout << "Zadej pocet trojuhelniku k nacteni: " << std::endl;
	int pocetTr = 0;
	std::cin >> pocetTr;


	Trojuhelnik* poleTrojuhelniku = new Trojuhelnik[pocetTr];

	for (int i = 0; i < pocetTr; i++) {
		std::cout << "Zadej stranu a pro trojuhelnik " << (i + 1) << ": ";
		std::cin >> poleTrojuhelniku[i].a;
		std::cout << "Zadej stranu b pro trojuhelnik " << (i + 1) << ": ";
		std::cin >> poleTrojuhelniku[i].b;
		std::cout << "Zadej stranu c pro trojuhelnik " << (i + 1) << ": ";
		std::cin >> poleTrojuhelniku[i].c;

		if (lzeSestrojit(poleTrojuhelniku[i])) {
			int obvod = poleTrojuhelniku[i].a + poleTrojuhelniku[i].b + poleTrojuhelniku[i].c;
			std::cout << "Obvod je: " << obvod << std::endl;
		}
		else {
			std::cout << "Nelze sestrojit trojuhelnik" << std::endl;
		}
	}

	delete[] (poleTrojuhelniku);
	return 0;
}