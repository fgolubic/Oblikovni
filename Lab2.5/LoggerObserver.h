#ifndef LOGGER_OBSERVER_H

#define LOGGER_OBSERVER_H

#include <fstream>
#include <string>

#include "NumberSequence.h"
#include "Observer.h"

class LoggerObserver : public Observer
{
public:
    LoggerObserver(std::string const& file_name);

    virtual void update(NumberSequence const& subject) override;

    virtual ~LoggerObserver();
private:
    std::ofstream file_;
};

#endif // !LOGGER_OBSERVER_H