//
// Created by daze on 08/06/19.
//

#ifndef SYNTAX_STACK_H
#define SYNTAX_STACK_H

#include <iostream>
#include <queue>

class stack {
private:
    std::deque<std::string> queue;
public:
    void loop(std::string str);
};


#endif //SYNTAX_STACK_H
