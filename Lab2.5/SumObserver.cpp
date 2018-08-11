#include <iostream>
#include <numeric>

#include "SumObserver.h"

void SumObserver::update(NumberSequence const& subject)
{
    auto const& values = subject.values();

    std::cout << "Sum: " << std::accumulate(values.cbegin(), values.cend(), 0) << std::endl;
}
