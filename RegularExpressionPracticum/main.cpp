#include "Solver.cpp"

int main() {
  std::string alpha;
  char x;
  size_t k;
  std::cin >> alpha >> x >> k;
  Solver s(alpha);
  std::cout << s.FindPrefix(x, k);
  return 0;
}