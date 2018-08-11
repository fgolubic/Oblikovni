#ifndef CLOSEST_H
#define CLOSEST_H
#include "Percentil.h"
class ClosestPercentil :
	public Percentil
{
public:

	virtual int calculatePercentil(std::vector<int> const& arr, int percentil) const override;

	virtual ~ClosestPercentil()=default;
};

#endif
