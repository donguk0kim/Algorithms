#include "fibonacci.hpp"

Fibonacci::Fibonacci() {
  cache_[1] = 1;
  cache_[2] = 1;
}

// Top Down
int Fibonacci::topDown(int nth) {
  if (cache_[nth] != 0) return cache_[nth];
  int fibonacci = topDown(nth - 1) + topDown(nth - 2);
  cache_[nth] = fibonacci;
  return fibonacci;
}

// Bottom Up
int Fibonacci::bottomUp(int nth) {
  for (int k = 3; k <= nth; k++) {
    int fibonacci = cache_[k - 1] + cache_[k - 2];
    cache_[k] = fibonacci;
  }
  return cache_[nth];
}
