#include "MergeSort.hpp"

int main() {
  
  std::vector<int> array1 { 5, 4, 3, 2, 1 };
  std::vector<int> array2 { 1, 2, 3, 4, 5, 5, 4, 3, 2, 1 };

  std::vector<int> result1 = mergeSort(array1);
  std::vector<int> result2 = mergeSort(array2);
  
  print(result1);
  print(result2);
  
  return 0;
}
