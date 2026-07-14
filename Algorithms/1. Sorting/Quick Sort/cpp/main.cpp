#include "quicksort.hpp"

int main() {

  // test case naive
  std::vector<int> array1 { 5, 4, 3, 2, 1, 0, 5, 4, 3, 2, 1, 0 };
  Print(Quicksort(array1));

  // test case in place
  std::vector<int> array2 { 5, 4, 3, 2, 1, 0, 5, 4, 3, 2, 1, 0 };
  QuicksortInplace(array2, 0, (int) array2.size() - 1);
  Print(array2);

  return 0;
}
