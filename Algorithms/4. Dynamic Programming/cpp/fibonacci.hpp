#include <unordered_map>

class Fibonacci {
  std::unordered_map<int, int> cache;
  
public:
  Fibonacci();
  int top_down(int nth);
  int bottom_up(int nth);
};
