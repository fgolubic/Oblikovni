#include <exception>

#include "FileSource.h"

FileSource::FileSource(std::string const& file_name) 
    : file_(file_name)
{
    if (!file_.is_open()) {
        throw std::invalid_argument("File : " + file_name + ", not found!");
    }
}

int FileSource::next()
{
    if (file_.eof()) {
        return -1;
    }

    auto number = -1;
    file_ >> number;

    return number;
}

FileSource::~FileSource()
{
    file_.close();
}
