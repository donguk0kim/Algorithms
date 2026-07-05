#include "BinarySearch.hpp"

int main() {
  
  std::vector<int> array { 1, 5, 7, 9, 15 };
  print(array);
  
  std::cout << binarySearch(array, 5) << std::endl;
  std::cout << binarySearch(array, 9) << std::endl;
  std::cout << binarySearch(array, 10) << std::endl;
  std::cout << binarySearch(array, -10) << std::endl;
  
  return 0;
}
