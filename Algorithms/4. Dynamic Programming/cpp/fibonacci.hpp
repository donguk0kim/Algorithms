#pragma once

#include <unordered_map>

class Fibonacci {
  std::unordered_map<int, int> cache_;

public:
  Fibonacci();
  int topDown(int nth);
  int bottomUp(int nth);
};
