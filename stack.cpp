//
// Created by daze on 08/06/19.
//

#include <algorithm>
#include <sstream>
#include <cstring>
#include "stack.h"

void Stack::split(std::string str)
{
    std::vector<std::string> vec;
    std::istringstream is(str);
    std::string res;
    while (std::getline(is, res, ' '))
    {
        vec.push_back(res);
    }

    for (auto i = vec.rbegin(); i != vec.rend(); ++i)
    {
        _queue.push_front(*i);
    }
}

bool Stack::loop()
{
    std::string line;
    std::istringstream is(_str);
    std::getline(is, line, '\n');
    int i = 1;
    while (!_queue.empty())
    {
        std::string front = _queue.front();
        _queue.pop_front();
        std::cout << "FRONT = " << front << std::endl;
        std::cout << "LINE = " << line << std::endl;
        if (isupper(front[0]) != 0)
        {
            std::string token = _table.find(front, line);
            std::cout << "TOKEN = " << token << std::endl;
            if (token != "" && token != "e")
            {
                split(token);
                std::cout << "FRONT AFTER SPLIT = " << _queue.front() << std::endl;
            }
        }
        else
        {
            if (front != line)
            {
                std::cout << "Incorrect syntax at line " << i << std::endl;
                return (false);
            }
            std::getline(is, line, '\n');
            ++i;
        }
    }
    return (true);
}

Stack::Stack(std::string str) : _str(str){
    _queue.push_front("$");
    _queue.push_front("CODE");
}
