#ifndef RANDOMGEN_H
#define RANDOMGEN_H

#include<random>

#include "Generator.h"
class RandomGenerator :
	public Generator
{
public:
	RandomGenerator(int mean, int deviation, int count );

	virtual std::vector<int> generateNumbers() const override;

	virtual ~RandomGenerator() = default;

	private:
		int mean_;
		int deviation_;
		int count_;
		mutable std::mt19937 gen_;
};


#endif
