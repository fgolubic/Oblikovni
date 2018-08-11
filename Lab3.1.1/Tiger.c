#include <stdlib.h>
#include <stdio.h>
#include "Tiger.h"

void construct(Tiger* tiger, const char* name)
{
	tiger->virtTable = table;
	tiger->name = name;
}

void* create(char const* name)
{
	void* obj = malloc(sizeof(Tiger));
	construct((Tiger*)obj, name);
	return obj;
}

char const* name(void* this)
{
	return ((Tiger*)this)->name;
}

char const* greet()
{
	return "Mijau!";
}

char const* menu()
{
	return "mlako mlijeko";
}
