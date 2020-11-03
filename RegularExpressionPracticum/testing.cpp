#include<fstream>
#include "Solver.cpp"

int main(){
    for (size_t i = 1; i <= 12; i++)
    {
      std::ifstream fin("Tests/test" + std::to_string(i) + ".txt");
      std::string alpha, correct_ans;
      char x;
      size_t k;
      fin >> alpha >> x >> k >> correct_ans;
      Solver s(alpha);
      if(s.FindPrefix(x, k) == correct_ans){
        std::cout << "Test " << i << " passed successfully!" << std::endl;
      }
      else{
        std::cout << "Test " << i << " FAILED!" << std::endl;
      }
    }
}