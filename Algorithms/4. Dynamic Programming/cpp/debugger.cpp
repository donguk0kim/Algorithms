#include "debugger.hpp"

// print ints
void Print(int value) {
  std::cout << value << std::endl;
}

// print strings
void Sprint(const char* string) {
  std::cout << string << std::endl;
}

// print arrays
void Vprint(std::vector<int> array) {
  std::cout << "{ ";
  for (int k = 0; k < array.size(); k++) {
    std::cout << array[k];
    if (k < array.size() - 1) std::cout << ", ";
  }
  std::cout << " }";
}

// print 2d arrays
void Vvprint(std::vector<std::vector<int>> array) {
  std::cout << "{ ";
  for (int k = 0; k < array.size(); k++) {
    Vprint(array[k]);
    if (k < array.size() - 1) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}
