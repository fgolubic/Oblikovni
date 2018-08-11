#include "DistributionTester.h"

#include<iostream>
#include<sstream>
#include <string>


DistributionTester::DistributionTester(std::initializer_list<int> percentiles):percentiles_(percentiles)
{
	

}

std::string printSequence(std::vector<int> const& distr)
{
	std::ostringstream stream = std::ostringstream();

	for (const auto& value : distr)
	{
		stream << value << " , ";
	}

	auto res = stream.str();

	return res.substr(0, res.length() - 2) + " : ";
}

void DistributionTester::test(Generator const& gen, Percentil const&  percCalc) const
{
	auto seq = gen.generateNumbers();
	std::cout << printSequence(seq);

	for(const auto& p : percentiles_)
	{
		std::cout << percCalc.calculatePercentil(seq, p)<< "/ ";
	}

	std::cout << std::endl;
}



