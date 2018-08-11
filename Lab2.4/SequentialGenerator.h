#ifndef SEQGEN_H
#define SEQGEN_H

#include "Generator.h"

class SequentialGenerator :
	public Generator
{
public:
	SequentialGenerator(int lowerBound, int uppderBound, int increment);

	virtual std::vector<int> generateNumbers() const override;

	virtual ~SequentialGenerator() = default;

private:
	int lowerBound_;
	int upperBound_;
	int increment_;

};


#endif
