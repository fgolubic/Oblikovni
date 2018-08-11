typedef char const* (*FUNPTR)(void*);

typedef struct
{
	FUNPTR* virtTable;
	const char* name;
}Parrot;

void construct(Parrot* tiger, char const* name);

void* create(char const* name);

char const* greet();

char const* menu();

char const*  name(void* this);

FUNPTR table[] = { name, greet, menu };