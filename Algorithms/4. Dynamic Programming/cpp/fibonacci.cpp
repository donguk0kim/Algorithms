#include "fibonacci.hpp"

Fibonacci::Fibonacci() {
  cache_[1] = 1;
  cache_[2] = 1;
}

// Top Down
int Fibonacci::TopDown(int nth) {
  if (cache_[nth] != 0) return cache_[nth];
  int fibonacci = TopDown(nth - 1) + TopDown(nth - 2);
  cache_[nth] = fibonacci;
  return fibonacci;
}

// Bottom Up
int Fibonacci::BottomUp(int nth) {
  for (int k = 3; k <= nth; k++) {
    int fibonacci = cache_[k - 1] + cache_[k - 2];
    cache_[k] = fibonacci;
  }
  return cache_[nth];
}
