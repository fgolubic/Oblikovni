#include "SequentialGenerator.h"



SequentialGenerator::SequentialGenerator(int lowerBound, int upperBound, int increment)
	:lowerBound_(lowerBound),upperBound_(upperBound),increment_(increment)
{
}


std::vector<int> SequentialGenerator::generateNumbers() const
{
	std::vector<int> res = std::vector<int>();

	for(int i=lowerBound_; i<=upperBound_; i+=increment_)
	{
		res.push_back(i);
	}
	return res;
}


