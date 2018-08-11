#include <algorithm>
#include <chrono>
#include <thread>

#include "NumberSequence.h"

NumberSequence::NumberSequence(std::shared_ptr<Source> source)
    : source_(source), values_()
{
    
}

void NumberSequence::start()
{
    auto value = 0;
    while(true) {
        value = source_->next();

        if (value == -1) {
            break;
        }

        values_.push_back(value);
        notify();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

std::vector<int> const& NumberSequence::values() const
{
    return values_;
}

void NumberSequence::register_observer(Observer& observer)
{
    observers_.push_back(observer);
}

void NumberSequence::remove_observer(Observer const& observer)
{
    observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
}

void NumberSequence::notify() const
{
    std::for_each(observers_.begin(), observers_.end(), [this](auto obs) { obs.get().update(*this); });
}
