#include "fibonacci.hpp"

Fibonacci::Fibonacci() {
  this->cache[1] = 1;
  this->cache[2] = 1;
}

// Top Down
int Fibonacci::top_down(int nth) {
  if (cache[nth] != 0) return cache[nth];
  int fibonacci = top_down(nth - 1) + top_down(nth - 2);
  cache[nth] = fibonacci;
  return fibonacci;
}

// Bottom Up
int Fibonacci::bottom_up(int nth) {
  for (int k = 3; k <= nth; k++) {
    int fibonacci = cache[k - 1] + cache[k - 2];
    cache[k] = fibonacci;
  }
  return cache[nth];
}
