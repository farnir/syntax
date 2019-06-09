//
// Created by daze on 08/06/19.
//

#include <algorithm>
#include <sstream>
#include <cstring>
#include "stack.hh"

void Stack::split(std::string str)
{
    std::vector<std::string> vec;
    std::istringstream is(str);
    std::string res;
    while (std::getline(is, res, ' ')) // pushing every split word into a temporary vector
        vec.push_back(res);

    for (auto i = vec.rbegin(); i != vec.rend(); ++i) // using a reverse iterator to fill the queue in the right order
    {
        _queue.push_front(*i);
    }
}

// return true in case of valid input file, false and a message indicating the error line otherwise

bool Stack::loop()
{
  std::string line;
  std::istringstream is(_str);
  std::getline(is, line, '\n');
  int i = 1;
  while (!_queue.empty()) // Doing the process all over until the queue is empty - only way to have a valid input file
    {

      // First step is removing the top element of the stack
      std::string front = _queue.front();
      //std::cout << "FRONT = " << front << std::endl;
      //std::cout << "LINE = " << line << std::endl;
      _queue.pop_front();

      if (isupper(front[0]) != 0) // Checks if we have a non-terminal or terminal
	{
	  std::string token = _table.find(front, line); // Searching the symbol in the table
	  if (token != "error" && token != "e") // Checking if token is not empty nor an espilon, represented as "e"
	    split(token); // Splitting the tokens into individual keywords to push into the queue
	  else if (token != "e")
	    {
	      std::cout << "Symbol Table doesn't recognize this pattern at line " << i << std::endl;
	      std::cout << "Expected: " << front << std::endl;
	      std::cout << "Got: " << line << std::endl;
	      return (false);
	    }
        }
      else
        {
	  if (front != line) // if our top element of the stack doesn't match what is on the line, the file is not valid
            {
	      std::cout << "Terminal not recognized at line " << i << std::endl;
	      std::cout << "Expected: " << front << std::endl;
	      std::cout << "Got: " << line << std::endl;
	      return (false);
            }
	  std::getline(is, line, '\n'); // Carrying on the process for the next line in the input file
	  ++i;
        }
    }
  std::cout << "Input file is valid" << std::endl;
  return (true); // We return true if we get out of the loop, meaning the stack is empty and the file valid
}

Stack::Stack(std::string str) : _str(str){

    // initializing the stack with our first element and endmarker
    _queue.push_front("$");
    _queue.push_front("CODE");
}
