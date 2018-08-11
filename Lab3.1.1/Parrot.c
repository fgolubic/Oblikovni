#include <stdlib.h>
#include <stdio.h>
#include "Parrot.h"

void construct(Parrot* parrot, const char* name)
{
	parrot->virtTable = table;
	parrot->name = name;
}

void* create(char const* name)
{
	void* obj = malloc(sizeof(Parrot));
	construct((Parrot*)obj, name);
	return obj;
}

char const* name(void* this)
{
	return ((Parrot*)this)->name;
}

char const* greet()
{
	return "Sto mu gromova!";
}

char const* menu()
{
	return "brazilske orahe";
}
