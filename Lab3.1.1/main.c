#include "myfactory.h"

#include <stdio.h>
#include <stdlib.h>

	typedef char const* (*PTRFUN)();

	typedef struct Animal {
		PTRFUN* vtable;
		// vtable entries:
		// 0: char const* name(void* this);
		// 1: char const* greet();
		// 2: char const* menu();
	}Animal;


	void animalPrintGreeting(Animal* animal);
	void animalPrintMenu(Animal* animal);

	// parrots and tigers defined in respective dynamic libraries

	// animalPrintGreeting and animalPrintMenu similar as in lab 1

	int main(void) {
		struct Animal* p1 = (struct Animal*)myfactory("parrot", "Modrobradi");
		struct Animal* p2 = (struct Animal*)myfactory("tiger", "Straško");
		if (!p1 || !p2) {
			printf("Creation of plug-in objects failed.\n");
			exit(1);
		}

		animalPrintGreeting(p1);//"Sto mu gromova!"
		animalPrintGreeting(p2);//"Mijau!"

		animalPrintMenu(p1);//"brazilske orahe"
		animalPrintMenu(p2);//"mlako mlijeko"

		system("pause");

		free(p1); free(p2);

	}


	void animalPrintGreeting(Animal* animal)
	{
		printf("%s pozdravlja: %s\n", (animal->vtable[0])(), (animal->vtable[1])());
	}

	void animalPrintMenu(Animal* animal)
	{
		printf("%s voli: %s\n", (animal->vtable[0])(), (animal->vtable[2])());
	}



