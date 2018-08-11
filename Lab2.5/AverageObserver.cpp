#include <iostream>
#include <numeric>

#include "AverageObserver.h"

void AverageObserver::update(NumberSequence const& subject)
{
    auto const& values = subject.values();

    std::cout << "Average: " << static_cast<double>(std::accumulate(values.cbegin(), values.cend(), 0)) / values.size() << std::endl;
}
