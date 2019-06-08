#include "symbol.hh"

TableSymbol::TableSymbol() {
  init();
}

void TableSymbol::init() {
  table.push_back(std::make_unique<Symbol>("CODE", "vtype", "vtype id DECL CODE"));
  table.push_back(std::make_unique<Symbol>("CODE", "$", "e"));

  table.push_back(std::make_unique<Symbol>("DECL", "semi", "semi"));
  table.push_back(std::make_unique<Symbol>("DECL", "lparen", "lparen ARG rparen lbrace BLOCK RETURN rbrace"));
  table.push_back(std::make_unique<Symbol>("ARG", "vtype", "vtype id MOREARGS"));
  table.push_back(std::make_unique<Symbol>("ARG", "rparen", "e"));

  table.push_back(std::make_unique<Symbol>("MOREARG", "rparen", "e"));
  table.push_back(std::make_unique<Symbol>("MOREARG", "comma", "comma vtype id MOREARGS"));

  table.push_back(std::make_unique<Symbol>("BLOCK", "vtype", "STMT BLOCK"));
  table.push_back(std::make_unique<Symbol>("BLOCK", "id", "STMT BLOCK"));
  table.push_back(std::make_unique<Symbol>("BLOCK", "if", "STMT BLOCK"));
  table.push_back(std::make_unique<Symbol>("BLOCK", "while", "STMT BLOCK"));
  table.push_back(std::make_unique<Symbol>("BLOCK", "return", "e"));
  table.push_back(std::make_unique<Symbol>("BLOCK", "rbrace", "e"));

  table.push_back(std::make_unique<Symbol>("STMT", "vtype", "vtype id semi"));
  table.push_back(std::make_unique<Symbol>("STMT", "id", "id RHSORFCALL semi"));
  table.push_back(std::make_unique<Symbol>("STMT", "if", "if lparen COND rparen lbrace BLOCK rbrace else lbrace BLOCK rbrace"));
  table.push_back(std::make_unique<Symbol>("STMT", "while", "while lparen COND rparen lbrace BLOCK rbrace"));

  table.push_back(std::make_unique<Symbol>("RHSORFCALL", "assign", "assign RHS"));

  table.push_back(std::make_unique<Symbol>("RHS", "id", "EXPR"));
  table.push_back(std::make_unique<Symbol>("RHS", "lparen", "EXPR"));
  table.push_back(std::make_unique<Symbol>("RHS", "num", "EXPR"));
  table.push_back(std::make_unique<Symbol>("RHS", "literal", "literal"));

  table.push_back(std::make_unique<Symbol>("EXPR", "id", "TERM EXPR2"));
  table.push_back(std::make_unique<Symbol>("EXPR", "lparen", "TERM EXPR2"));
  table.push_back(std::make_unique<Symbol>("EXPR", "num", "TERM EXPR2"));

  table.push_back(std::make_unique<Symbol>("EXPR2", "semi", "e"));
  table.push_back(std::make_unique<Symbol>("EXPR2", "rparen", "e"));
  table.push_back(std::make_unique<Symbol>("EXPR2", "addsub", "addsub EXPR2"));

  table.push_back(std::make_unique<Symbol>("TERM", "id", "FACTOR TERM2"));
  table.push_back(std::make_unique<Symbol>("TERM", "lparen", "FACTOR TERM2"));
  table.push_back(std::make_unique<Symbol>("TERM", "num", "FACTOR TERM2"));

  table.push_back(std::make_unique<Symbol>("TERM2", "semi", "e"));
  table.push_back(std::make_unique<Symbol>("TERM2", "rparen", "e"));
  table.push_back(std::make_unique<Symbol>("TERM2", "addsub", "e"));
  table.push_back(std::make_unique<Symbol>("TERM2", "num", "multidiv TERM"));

  table.push_back(std::make_unique<Symbol>("FACTOR", "id", "id"));
  table.push_back(std::make_unique<Symbol>("FACTOR", "lparen", "lparen EXPR rparen"));
  table.push_back(std::make_unique<Symbol>("FACTOR", "num", "num"));

  table.push_back(std::make_unique<Symbol>("COND", "id", "FACTOR comp FACTOR"));
  table.push_back(std::make_unique<Symbol>("COND", "lparen", "FACTOR comp FACTOR"));
  table.push_back(std::make_unique<Symbol>("COND", "num", "FACTOR comp FACTOR"));

  table.push_back(std::make_unique<Symbol>("RETURN", "return", "return FACTOR semi"));
}

std::string TableSymbol::find(std::string index, std::string input) {
  for (auto &tmp : table) {
    if (tmp->index == index && tmp->input == input)
      return tmp->result;
  };
  return NULL;
}
