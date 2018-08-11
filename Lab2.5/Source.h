#ifndef SOURCE_H

#define SOURCE_H

class Source
{
public:
    virtual int next() = 0;

    virtual ~Source() = default;
};

#endif 