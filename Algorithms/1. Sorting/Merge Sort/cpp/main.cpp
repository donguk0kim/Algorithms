#include "merge_sort.hpp"

int main() {

  std::vector<int> array1 { };
  std::vector<int> array2 { 1 };
  std::vector<int> array3 { 5, 4, 3, 2, 1 };
  std::vector<int> array4 { 1, 2, 3, 4, 5, 5, 4, 3, 2, 1 };

  std::vector<int> result1 = MergeSort(array1);
  std::vector<int> result2 = MergeSort(array2);
  std::vector<int> result3 = MergeSort(array3);
  std::vector<int> result4 = MergeSort(array4);

  Print(result1);
  Print(result2);
  Print(result3);
  Print(result4);

  return 0;
}
