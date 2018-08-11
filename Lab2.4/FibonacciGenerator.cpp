#include "FibonacciGenerator.h"



FibonacciGenerator::FibonacciGenerator(int count)
	:count_(count)
{
}

int fibonacci(int n)
{
	if (n == 0) return 0;

	if (n == 1) return 1;

	return fibonacci(n - 1) + fibonacci(n - 2);

}

std::vector<int> FibonacciGenerator::generateNumbers() const
{
	std::vector<int> res = std::vector<int>(count_);
	for(int i=1;i<=count_;i++)
	{
		res[i - 1] = fibonacci(i);
	}
	return res;
}

