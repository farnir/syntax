//
// Created by daze on 08/06/19.
//

#include <algorithm>
#include <sstream>
#include "stack.h"

void stack::loop(std::string str)
{
    std::string line;
    std::istringstream is(str);
    while (!is.eof())
    {
        std::getline(is, line, '\n');

    }
}
