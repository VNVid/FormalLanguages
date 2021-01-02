#ifndef EARLEY_PARSER_H
#define EARLEY_PARSER_H

#include <map>
#include <set>
#include <string>
#include <vector>

#include "Grammar.h"
#include "State.h"

class EarleyParser {
 public:
  EarleyParser(Grammar gr) : grammar_(gr){};
  bool IsWordInLanguage(std::string word);

 private:
  Grammar grammar_;

  void Scan(size_t cur_pos, std::vector<std::set<State>>& D,
            const std::string& word);
  bool Predict(size_t cur_pos, std::vector<std::set<State>>& D,
               const std::string& word);
  bool Complete(size_t cur_pos, std::vector<std::set<State>>& D,
                const std::string& word);
};

#endif