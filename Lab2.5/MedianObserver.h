#ifndef MEDIAN_OBSERVER_H

#define MEDIAN_OBSERVER_H

#include "NumberSequence.h"
#include "Observer.h"

class MedianObserver : public Observer
{
public:
    virtual void update(NumberSequence const& subject);

    virtual ~MedianObserver() = default;
};

#endif //!MEDIAN_OBSERVER_H