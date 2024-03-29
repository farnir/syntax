#ifndef SYMBOL_HH
#define SYMBOL_HH

#include <string>
#include <vector>
#include <memory>

// Structure that represent one case in the symbol table.
struct Symbol {
  std::string index; // Terminal
  std::string input; // Non-terminal
  std::string result; // different token possibilities

  Symbol(std::string _index, std::string _input, std::string _result) {
    index = _index;
    input = _input;
    result = _result;
  };
};

// Class that store all cases of the symbol table and give access to it.
class TableSymbol {
  std::vector<std::unique_ptr<Symbol>> table;

public:
  TableSymbol();
  ~TableSymbol() = default;

  std::string find(std::string index, std::string input); // Function used to get the possible tokens
private:
  void init();
};

#endif //SYMBOL_HH
