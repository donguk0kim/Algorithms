#include "merge_sort.hpp"

int main() {

  std::vector<int> array1 { };
  std::vector<int> array2 { 1 };
  std::vector<int> array3 { 5, 4, 3, 2, 1 };
  std::vector<int> array4 { 1, 2, 3, 4, 5, 5, 4, 3, 2, 1 };

  std::vector<int> result1 = mergeSort(array1);
  std::vector<int> result2 = mergeSort(array2);
  std::vector<int> result3 = mergeSort(array3);
  std::vector<int> result4 = mergeSort(array4);

  print(result1);
  print(result2);
  print(result3);
  print(result4);

  return 0;
}
