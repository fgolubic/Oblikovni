

typedef char const* (*FUNPTR)(void*);

typedef struct
{
	FUNPTR* virtTable;

}Animal;