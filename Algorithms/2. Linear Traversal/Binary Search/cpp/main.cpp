#include "binary_search.hpp"

int main() {

  std::vector<int> array { 1, 5, 7, 9, 15 };
  Print(array);

  std::cout << BinarySearch(array, 5) << std::endl;
  std::cout << BinarySearch(array, 9) << std::endl;
  std::cout << BinarySearch(array, 1) << std::endl;
  std::cout << BinarySearch(array, 15) << std::endl;
  std::cout << BinarySearch(array, 10) << std::endl;
  std::cout << BinarySearch(array, -10) << std::endl;

  return 0;
}
