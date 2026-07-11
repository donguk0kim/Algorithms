#include "binary_search.hpp"

int main() {
  
  std::vector<int> array { 1, 5, 7, 9, 15 };
  print(array);
  
  std::cout << binary_search(array, 5) << std::endl;
  std::cout << binary_search(array, 9) << std::endl;
  std::cout << binary_search(array, 1) << std::endl;
  std::cout << binary_search(array, 15) << std::endl;
  std::cout << binary_search(array, 10) << std::endl;
  std::cout << binary_search(array, -10) << std::endl;
  
  return 0;
}
