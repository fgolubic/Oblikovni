#ifndef GENERATOR_H

#define GENERATOR_H

#include <vector>

class Generator
{
public:
	virtual std::vector<int> generateNumbers() const = 0;

	virtual ~Generator() = default;
};

#endif
