#ifndef GUARD_glutton_hpp
#define GUARD_glutton_hpp

#include <string>

struct glutton
{
    std::string name;
    int ate;
};

bool compare (const glutton&, const glutton&);

#endif