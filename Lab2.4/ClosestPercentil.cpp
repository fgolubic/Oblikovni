#include "ClosestPercentil.h"

#include<algorithm>

int ClosestPercentil::calculatePercentil(std::vector<int> const& arr, int percentil) const
{
	auto temp = arr;

	std::sort(temp.begin(), temp.end());

	int pos = static_cast<int> (std::round(static_cast<double>(percentil * temp.size()) / 100 + 0.5)) - 1;

	return temp[pos];
}



