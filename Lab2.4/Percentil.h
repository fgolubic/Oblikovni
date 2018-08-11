#ifndef PERCENTIL_H
#define PERCENTIL_H
#include<vector>


class Percentil
{
public:
	virtual int calculatePercentil(std::vector<int> const& arr, int percentil) const = 0;

	virtual ~Percentil()=default;
};


#endif
