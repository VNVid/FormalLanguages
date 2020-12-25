#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <map>
#include <string>
#include <vector>

/*
In this structure we store production rules in the following format:
    for each nonterminal symbol we keep a set of expressions
*/

struct Grammar {
  std::map<char, std::vector<std::string>> rules;

  Grammar() {}
  void AddRule(char from, std::string to) { rules[from].push_back(to); }
  std::vector<std::string> operator[](char c) {
    if (rules.count(c) > 0) {
      return rules[c];
    }
    return {};
  }
};

#endif