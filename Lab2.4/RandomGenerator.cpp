#include "RandomGenerator.h"



RandomGenerator::RandomGenerator(int mean, int deviation, int count)
	:mean_(mean),deviation_(deviation),count_(count), gen_(std::random_device()())
{
}


std::vector<int> RandomGenerator::generateNumbers()const
{
	auto distiribution = std::normal_distribution<>(mean_, deviation_);
	std::vector<int> res = std::vector<int>(count_);


	for(int i=0; i<count_; i++)
	{
		res[i] = std::round(distiribution(gen_));
	}
	return res;
}



