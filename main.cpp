#include <iostream>
#include <istream>
#include <fstream>
#include <algorithm>
// Main function to verify the number of argument and instantiate our main class.
// It also catch all our exceptions from the code.

std::string change(std::string str, std::string toFind, std::string toReplace)
{
    if (size_t pos = str.find(toFind) != std::string::npos)
    {
        str.replace(pos, toFind.length(), toReplace);
    }
    return str;
}

std::string tokenFormatting(std::string file)
{
    std::ifstream is;
       is.open("test");
       std::string str;
       if (is) {
           // get length of file:
           is.seekg (0, is.end);
           int length = is.tellg();
           is.seekg (0, is.beg);

           char * buffer = new char [length];

           // read data as a block:
           is.read(buffer,length);
           str = buffer;
           delete[] buffer;
           //std::cout << str << std::endl;
           is.close();
       }
       std::string tmp;
       std::string line;
       std::string final;
       int len = std::count(str.begin(), str.end(), '\n');
       for (int i = 0; i < len;++i)
       {
           line = str.substr(0, str.find('\n'));
           tmp = line.substr(0, line.find('|'));
           final.append(tmp + '\n');
           size_t pos = str.find('\n');
           str.erase(0, pos + 1);
       }
       std::cout << final << std::endl;
    return (final);
}

int main(int ac, char** av) {
  if (ac != 2) {
    std::cout << "Usage: ./syntax_analyser file" << std::endl;
    return (1);
  }
  try {
    tokenFormatting(av[1]);
    return (0);
  } catch (std::string const & e) {
    std::cout << e << std::endl;
    return (1);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    return (1);
  }
}
