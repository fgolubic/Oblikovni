#ifndef DISTTEST_H
#define DISTTEST_H
#include <initializer_list>
#include<vector>

#include "Generator.h" 
#include "Percentil.h"

class DistributionTester
{
public:
	DistributionTester(std::initializer_list<int> percentiles);
	
	virtual ~DistributionTester() = default;

	void test(Generator const& gen, Percentil const&  percCalc) const;

private:
	std::vector<int> percentiles_;
};

#endif