#ifndef FIBGEN_H
#define FIBGEN_H

#include "Generator.h"
class FibonacciGenerator :
	public Generator
{
public:
	FibonacciGenerator(int count);

	virtual std::vector<int> generateNumbers() const override;

	virtual ~FibonacciGenerator()=default;

private:
	int count_;
};
#endif


