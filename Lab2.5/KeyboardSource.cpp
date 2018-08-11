#include <iostream>

#include "KeyboardSource.h"

int KeyboardSource::next()
{
    if (std::cin.eof()) {
        return -1;
    }

    auto number = -1;
    std::cin >> number;

    return number;
}
