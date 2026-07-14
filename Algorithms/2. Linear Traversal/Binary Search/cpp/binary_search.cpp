#include "binary_search.hpp"

// log(n)
int BinarySearch(std::vector<int> array, int target) {

  int mid_index = (int) array.size() / 2;
  int mid = array[mid_index];
  if (mid == target) return mid_index;
  if (array.size() == 1 && mid != target) return -1;

  std::vector<int> left (array.begin(), array.end() - mid_index);
  std::vector<int> rite (array.begin() + mid_index + 1, array.end());

  if (mid > target) {
    return BinarySearch(left, target);
  } else {
    int index = BinarySearch(rite, target);
    return index < 0 ? index : mid_index + index + 1;
  }
}

// debugger
void Print(std::vector<int> array) {
  std::cout << "{ ";
  for (int index = 0; index < array.size(); index++) {
    std::cout << array[index];
    if (index < array.size() - 1) std::cout << ", ";
  }
  std::cout << " }\n" << std::endl;
}
