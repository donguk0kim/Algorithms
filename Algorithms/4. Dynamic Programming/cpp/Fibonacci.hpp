#include <unordered_map>

class Fibonacci {
  std::unordered_map<int, int> cache;
  
public:
  Fibonacci();
  int topDown(int nth);
  int bottomUp(int nth);
};
