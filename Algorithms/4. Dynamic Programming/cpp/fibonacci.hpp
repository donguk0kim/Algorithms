#pragma once

#include <unordered_map>

class Fibonacci {
  std::unordered_map<int, int> cache_;

public:
  Fibonacci();
  int TopDown(int nth);
  int BottomUp(int nth);
};
