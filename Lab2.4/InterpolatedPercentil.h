#ifndef INTER_H
#define INTER_H


#include "Percentil.h"
class InterpolatedPercentil :
	public Percentil
{
public:
	virtual int calculatePercentil(std::vector<int> const& arr, int percentil) const override;

	virtual ~InterpolatedPercentil()=default;
};

#endif
