#include "Animal.hpp"
#include "myfactory.hpp"
#include <iostream>
#include <sstream>
void animalPrintGreeting(Animal &animal);
void animalPrintMenu(Animal &animal);

int main(void) {
	myfactory& fact(myfactory::instance());
	std::vector<std::string> vecIds = fact.getIds();
	for (int i = 0; i<vecIds.size(); ++i) {
		std::ostringstream oss;
		oss << "Ljubimac " << i;
		Animal* pa = (Animal*)fact.create(vecIds[i], oss.str());
		animalPrintGreeting(*pa);
		animalPrintMenu(*pa);
		delete pa;
	}

	system("pause");
}

void animalPrintGreeting(Animal &animal)
{
	std::cout << animal.name() << " pozdravlja: " << animal.greet() << "\n";
}

void animalPrintMenu(Animal &animal)
{
	std::cout << animal.name() << " voli: " << animal.menu() << "\n";
}

