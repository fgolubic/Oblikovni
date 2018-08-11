#include<Windows.h>
#include"myfactory.h"

typedef void* (*FUNPTR)(char const*);

void* myfactory(char const* libname, char const* ctorarg)
{
	FUNPTR create;
	HINSTANCE dllHandle = LoadLibrary(libname);

	if(!dllHandle)
	{
		return NULL;
	}

	create = (FUNPTR)GetProcAddress(dllHandle, "create");

	if (!create) {
		return NULL;
	}

	return create(ctorarg);

}