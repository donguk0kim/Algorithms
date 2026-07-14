#include "merge_sort.hpp"

// nlog(n)
std::vector<int> MergeSort(std::vector<int> array) {
  if (array.size() <= 1) return array;

  int mid_index = (int) array.size() / 2;
  std::vector<int> left;
  std::vector<int> rite;

  if (array.size() & 1) {
    left = std::vector<int>(array.begin(), array.end() - mid_index);
    rite = std::vector<int>(array.begin() + mid_index + 1, array.end());
  } else {
    left = std::vector<int>(array.begin(), array.end() - mid_index);
    rite = std::vector<int>(array.begin() + mid_index, array.end());
  }

  left = MergeSort(left);
  rite = MergeSort(rite);
  return Merge(left, rite);
}

// helper function
std::vector<int> Merge(std::vector<int> left, std::vector<int> rite) {
  std::vector<int> result;

  while (!left.empty() && !rite.empty()) {

    if (left[0] < rite[0]) {
      result.push_back(left[0]);
      left.erase(left.begin());

    } else if (left[0] > rite[0]) {
      result.push_back(rite[0]);
      rite.erase(rite.begin());

    } else {
      result.push_back(left[0]);
      left.erase(left.begin());
    }
  }

  result.insert(result.end(), left.begin(), left.end());
  result.insert(result.end(), rite.begin(), rite.end());
  return result;
}

// debugger
void Print(std::vector<int> array) {
  std::cout << "{ ";
  for (int index = 0; index < array.size(); index++) {
    std::cout << array[index];
    if (index < array.size() - 1) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}
