#ifndef NUMBER_SEQUENCE_H

#define NUMBER_SEQUENCE_H

#include <functional>
#include <memory>
#include <vector>

#include "Observer.h"
#include "Source.h"

class NumberSequence
{
public:
    NumberSequence(std::shared_ptr<Source> source);

    void start();

    std::vector<int> const& values() const;

    void register_observer(Observer& observer);

    void remove_observer(Observer const& observer);
private:
    void notify() const;

    std::vector<std::reference_wrapper<Observer>> observers_;

    std::shared_ptr<Source> source_;
    std::vector<int> values_;
};

#endif 