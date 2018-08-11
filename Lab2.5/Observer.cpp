#include "Observer.h"

static auto identity_number = 0;

Observer::Observer()
    : identity_(identity_number++)
{
    
}
