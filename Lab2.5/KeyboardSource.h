#ifndef KEYBOARD_SOURCE_H

#define KEYBOARD_SOURCE_H

#include "Source.h"

class KeyboardSource : public Source
{
public:
    virtual int next() override;

    virtual ~KeyboardSource() = default;
};

#endif // !KEYBOARD_SOURCE_H