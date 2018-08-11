#include<stdio.h>
#include<stdlib.h>



typedef double (*funptr)(double);

/*======================
	Unary_Function Class
  ======================*/

typedef struct {
	funptr *vptr;
	int lower_bound;
	int upper_bound;

}Unary_Function;

typedef double(*fptr)(Unary_Function*, double);

double negative_value_at(Unary_Function* uf, double x)
{
	return -((fptr)uf->vptr[0])(uf,x);

}

funptr Unary_FunctionTable[2]= {
	(funptr)NULL, (funptr)negative_value_at
};

void tabulate(Unary_Function* uf)
{
	int x;
	for(x=uf->lower_bound; x<= uf->upper_bound; x++)
	{
		printf("f(%d)=%lf\n", x, ((fptr)uf->vptr[0])(uf,x));
	}
}

int same_functions_for_ints(Unary_Function *f1, Unary_Function *f2, double tolerance)
{
	double delta;
	if (f1->lower_bound != f2->lower_bound) return 0;
	if (f1->upper_bound != f2->upper_bound) return 0;
	for (int x = f1->lower_bound; x <= f1->upper_bound; x++) {
		delta = ((fptr)f1->vptr[0])(f1,x) - ((fptr)f2->vptr[0])(f2,x);
		if (delta < 0) delta = -delta;
		if (delta > tolerance) return 0;
	}
	return 1;
}

 void Unary_FunctionInit(Unary_Function* uf, int lb, int ub)
{
	 uf->vptr = Unary_FunctionTable;
	 uf->lower_bound = lb;
	 uf->upper_bound = ub;
}

/*======================
	Square Class
======================*/

typedef struct {
	funptr *vptr;
	int lower_bound;
	int upper_bound;
}Square;

double value_at_square(Square* square, double x)
{
	return x*x;
}

funptr SquareTable[2] = {
	(funptr)value_at_square, (funptr)negative_value_at
};

void SquareInit(Square* square, int lb, int ub)
{
	Unary_FunctionInit((Unary_Function*)square, lb, ub);
	square->vptr = SquareTable;
}

/*======================
	Linear Class
======================*/


typedef struct {
	funptr *vptr;
	int lower_bound;
	int upper_bound;
	double a;
	double b;
}Linear;

double value_at_linear(Linear* lin, double x)
{
	return (lin->a)*x + lin->b;
}

funptr LinearTable[2]= {
	(funptr)value_at_linear, (funptr)negative_value_at 
};


void LinearInit(Linear* lin, int lb, int ub,  int a_coef, int b_coef)
{
	SquareInit((Square*)lin, lb, ub);
	lin->vptr = LinearTable;
	lin->a = a_coef;
	lin->b = b_coef;

}



int main(void)
{
	Unary_Function *f1, *f2;

	f1 = (Unary_Function*)malloc(sizeof(Square));
	SquareInit((Square*)f1, -2, 2);

	tabulate(f1);
	
	f2 = (Unary_Function*)malloc(sizeof(Linear));
	LinearInit((Linear*)f2, -2, 2, 5, -2);

	tabulate(f2);

	printf("f1==f2: %s\n", same_functions_for_ints(f1, f2, 1E-6) ? "DA" : "NE");
	printf("neg_val f2(1) = %lf\n", ((fptr)f2->vptr[1])(f2, 1.0));
	free(f1);
	free(f2);

	system("pause");
	return 0;
}