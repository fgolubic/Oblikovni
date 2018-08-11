#ifndef SUM_OBSERVER_H

#define SUM_OBSERVER_H

#include "NumberSequence.h"
#include "Observer.h"

class SumObserver : public Observer
{
public:
    virtual void update(NumberSequence const& subject);

    virtual ~SumObserver() = default;
};

#endif // !SUM_OBSERVER_H