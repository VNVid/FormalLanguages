#include <fstream>
#include <iostream>

#include "Parser/EarleyParser.h"

std::vector<std::string> RunTest(std::string file_name) {
  std::ifstream fin(file_name);
  std::vector<std::string> mistakes(0);
  Grammar grammar;
  int number_of_rules = 0;
  fin >> number_of_rules;
  std::string rule;
  std::getline(fin, rule);
  for (int i = 0; i < number_of_rules; i++) {
    std::getline(fin, rule);

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

    // The rest goes for the right part of production rule (spaces are
    // skipped)
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
  fin >> number_of_words;
  std::string word;
  std::getline(fin, word);
  bool correct_ans = false;
  for (int i = 0; i < number_of_words; i++) {
    std::getline(fin, word);
    fin >> correct_ans;
    if (parser.IsWordInLanguage(word) != correct_ans) {
      mistakes.push_back(word);
    }
    std::getline(fin, word);
  }

  return mistakes;
}

void PrintResult(std::vector<std::string>& mistakes, std::string test_name) {
  if (mistakes.size() == 0) {
    std::cout << "Test \"" << test_name << "\" passed successfully!"
              << std::endl;
  } else {
    std::cout << " Test \"" << test_name << "\" failed on words: ";
    for (auto word : mistakes) {
      std::cout << "\"" << word << "\" ";
    }
    std::cout << std::endl;
  }
}

int main() {
  std::vector<std::string> mistakes;
  std::string test_name;
  std::string file_name;

  // Languge with one word only
  file_name = "Tests/OneWord.txt";
  mistakes = RunTest(file_name);
  test_name = "One word in language";
  PrintResult(mistakes, test_name);

  // Words with equal number of 'a' and 'b'
  file_name = "Equal.txt";
  mistakes = RunTest(file_name);
  test_name = "Equal Number Of 'a' and 'b'";
  PrintResult(mistakes, test_name);

  // Balanced bracket sequences
  file_name = "bbs.txt";
  mistakes = RunTest(file_name);
  test_name = "Balanced bracket sequences";
  PrintResult(mistakes, test_name);

  // L = {a, b, c, a+a, a+b, a+c, b+a, b+b, ..., a+a+a, a+a+b, ...}
  // Language consists of different sums of 'a', 'b', 'c'
  file_name = "sum.txt";
  mistakes = RunTest(file_name);
  test_name = "Sum";
  PrintResult(mistakes, test_name);
}