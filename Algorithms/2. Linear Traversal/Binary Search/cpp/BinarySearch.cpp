#include "BinarySearch.hpp"

// binary search
int binarySearch(std::vector<int> array, int target) {
  
  int midIndex = (int) array.size() / 2;
  int mid = array[midIndex];
  if (mid == target) return midIndex;
  if (array.size() == 1 && mid != target) return -1;
  
  std::vector<int> left (array.begin(), array.end() - midIndex);
  std::vector<int> rite (array.begin() + midIndex + 1, array.end());
  
  if (mid > target) {
    return binarySearch(left, target);
  } else {
    int index = binarySearch(rite, target);
    return index < 0 ? index : midIndex + index + 1;
  }
}

// debugger
void print(std::vector<int> array) {
  std::cout << "{ ";
  for (int index = 0; index < array.size(); index++) {
    std::cout << array[index];
    if (index < array.size() - 1) std::cout << ", ";
  }
  std::cout << " }\n" << std::endl;
}
