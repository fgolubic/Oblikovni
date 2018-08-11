#ifndef FILE_SOURCE_H

#define FILE_SOURCE_H

#include <fstream>
#include <string>

#include "Source.h"

class FileSource : public Source
{
public:
    FileSource(std::string const& file_name);

    virtual int next() override;

    virtual ~FileSource();
private:
    std::ifstream file_;
};

#endif // !FILE_SOURCE_H