#include<algorithm>
#include<iostream>
#include<set>
#include<stack>
#include<string>
#include<vector>


class Solver{
public:
    Solver(std::string& alpha):regular_expression(alpha){}

    std::string FindPrefix(const char letter, const size_t power){
      std::stack<std::pair<int, int>> reg_expr_processing;
      std::pair<int, int> empty_word = std::make_pair(-1, -1);
      for (size_t i = 0; i < regular_expression.size(); i++) {
        try {
          if (alphabet.find(regular_expression[i]) != alphabet.end()) {
            if (regular_expression[i] == '1') {
              reg_expr_processing.push(std::make_pair(-1, -1));
            } else {
              reg_expr_processing.push(
                  std::make_pair(regular_expression[i] == letter, 0));
            }
          } else if (regular_expression[i] == '+') {
            std::pair<int, int> expr2 = reg_expr_processing.top();
            reg_expr_processing.pop();
            std::pair<int, int> expr1 = reg_expr_processing.top();
            reg_expr_processing.pop();

            std::pair<int, int> new_expr(0, 0);
            new_expr.second = std::max(expr1.second, expr2.second);
            new_expr.first = std::max(expr1.first, expr2.first);
            if(new_expr.first == 0 && (expr2.first == -1 || expr1.first == -1)){
              new_expr.first = -1;
            }
            reg_expr_processing.push(new_expr);
          } else if (regular_expression[i] == '*') {
            std::pair<int, int> expr = reg_expr_processing.top();
            reg_expr_processing.pop();

            if(expr.first > 0){
              expr.first = power;
            }
            else{
              expr.first = -1;
            }
            reg_expr_processing.push(expr);
          } else if (regular_expression[i] == '.') {
            std::pair<int, int> expr2 = reg_expr_processing.top();
            reg_expr_processing.pop();
            std::pair<int, int> expr1 = reg_expr_processing.top();
            reg_expr_processing.pop();

            std::pair<int, int> new_expr(0, 0);
            if(expr1 == empty_word){
              reg_expr_processing.push(expr2);
            }
            else if(expr2 == empty_word){
              reg_expr_processing.push(expr1);
            }
            else{
              if(expr1.first != 0 && expr2.first !=0 && expr1.first != -1 && expr2.first != -1){
                new_expr.first = expr1.first + expr2.first;
              } else if (expr1.first != 0 && expr2.first != 0) {
                new_expr.first = std::max(expr1.first, expr2.first);
              }
              new_expr.second = std::max(expr1.second, expr1.first + expr2.second);
              reg_expr_processing.push(new_expr);
            }
          } else {
            throw "undefined symbol";
          }
        } catch (...) {
          return "ERROR";
        }
      }
      if(reg_expr_processing.size() == 1){
        if(std::max(reg_expr_processing.top().first, reg_expr_processing.top().second) >= power){
          return "YES";
        }
        else{
          return "NO";
        }
      }
      else{
        return "ERROR";
      }
    }

   private:
    std::string regular_expression;
    const std::set<char> alphabet{'a', 'b', 'c', '1'};
};