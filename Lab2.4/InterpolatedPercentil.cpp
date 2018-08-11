#include "InterpolatedPercentil.h"

#include<algorithm>


int InterpolatedPercentil::calculatePercentil(std::vector<int> const& arr, int percentil) const
{
	auto temp = arr;
	std::sort(temp.begin(), temp.end());

	if (percentil < 100 * (1 - 0.5) / temp.size()) {
		return temp[0];
	}
	if (percentil > 100 * (1 - 0.5) / temp.size()) {
		return temp[temp.size() - 1];
	}

	for(int i=0; i< temp.size(); ++i)
	{
		auto low = 100 * (i + 1 - 0.5) / temp.size();
		auto up = 100 * (i + 1 - 0.5 + 1) / temp.size();

		if(percentil>=low && percentil <= up)
		{
			auto res = temp[i] + temp.size() * (percentil - low) * (temp[i + 1] - temp[i]) / 100;
			return res;
		}
	}
	return -1;

}
