//
// Created by daze on 08/06/19.
//

#ifndef SYNTAX_STACK_HH
#define SYNTAX_STACK_HH

#include <iostream>
#include <queue>
#include "symbol.hh"

class Stack {
private:
    std::string _str; // String corresponding to the input file
    std::deque<std::string> _queue; // Queue representing the stack acting as a LiFo
    TableSymbol _table; // Object containing all the symbols

    void split(std::string str); // Function used to split and push into the stack
public:
    Stack(std::string str);

    bool loop(); // Main loop
};


#endif //SYNTAX_STACK_HH
