//
// Created by daze on 08/06/19.
//

#ifndef SYNTAX_STACK_H
#define SYNTAX_STACK_H

#include <iostream>
#include <queue>
#include "symbol.hh"

class Stack {
private:
    std::string _str;
    std::deque<std::string> _queue;
    TableSymbol _table;

    void split(std::string str);
public:
    Stack(std::string str);

    bool loop();
};


#endif //SYNTAX_STACK_H
