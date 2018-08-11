#include <algorithm>
#include <iostream>

#include "MedianObserver.h"

void MedianObserver::update(NumberSequence const& subject)
{
    auto values = subject.values();
    std::sort(values.begin(), values.end());

    auto median = 0.0;
    auto size = values.size();
    if (size % 2 == 0) {
        median = static_cast<double>(values[size / 2 - 1] + values[size / 2]) / 2;
    }
    else {
        median = values[size / 2];
    }

    std::cout << "Medijan: " << median << std::endl;
}
