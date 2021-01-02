#include <iostream>

#include "EarleyParser.h"

int main() {
  Grammar grammar;
  int number_of_rules = 0;
  std::cin >> number_of_rules;
  std::string rule;
  std::getline(std::cin, rule);
  for (int i = 0; i < number_of_rules; i++) {
    std::getline(std::cin, rule);

    char from;
    std::string to = "";
    size_t ind = 0;

    // Firstly, we find a non terminal that is a capital letter (A-Y)
    // Z is reserved
    while (ind < rule.size() && (rule[ind] < 'A' || rule[ind] > 'Y')) {
      ++ind;
    }
    from = rule[ind];
    ++ind;

    // The rest goes for the right part of production rule (spaces are skipped)
    while (ind < rule.size()) {
      if (rule[ind] != ' ') {
        to += rule[ind];
      }
      ++ind;
    }

    // Add rule to our grammar
    grammar.AddRule(from, to);
  }

  EarleyParser parser(grammar);

  int number_of_words = 0;
  std::cin >> number_of_words;
  std::string word;
  std::getline(std::cin, word);
  for (int i = 0; i < number_of_words; i++) {
    std::getline(std::cin, word);
    if (parser.IsWordInLanguage(word)) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }
}