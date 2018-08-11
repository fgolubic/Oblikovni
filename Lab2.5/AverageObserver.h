#ifndef AVERAGE_OBSERVER_H

#define AVERAGE_OBSERVER_H

#include "NumberSequence.h"
#include "Observer.h"

class AverageObserver : public Observer
{
public:
    virtual void update(NumberSequence const& subject);

    virtual ~AverageObserver() = default;
};

#endif // !AVERAGE_OBSERVER_H