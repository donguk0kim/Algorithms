#include <iostream>
#include "Quicksort.hpp"

int main() {
  
  // test case wasteful
  std::vector<int> array1 { 5, 4, 3, 2, 1, 0, 5, 4, 3, 2, 1, 0 };
  print(quicksort(array1));
  
  // test case inplace
  std::vector<int> array2 { 5, 4, 3, 2, 1, 0, 5, 4, 3, 2, 1, 0 };
  quicksortInplace(array2, 0, (int) array2.size() - 1);
  print(array2);
  
  return 0;
}
