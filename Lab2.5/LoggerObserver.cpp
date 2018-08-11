#include "LoggerObserver.h"

LoggerObserver::LoggerObserver(std::string const& file_name) 
    : file_(file_name, std::fstream::app)
{
    if (!file_.is_open()) {
        throw std::invalid_argument("File : " + file_name + ", not found!");
    }
}

void LoggerObserver::update(NumberSequence const& subject)
{
    for (auto const& val : subject.values()) {
        file_ << val << " |";
    }
    file_ << std::endl;
}

LoggerObserver::~LoggerObserver()
{
    file_.close();
}
