#include "hash_map.hpp"

#include <iostream>

void Print(int value) {
  std::cout << value << std::endl;
}

int main() {
  HashMap hashmap;
  hashmap.Set(1,1);
  hashmap.Set(2,2);
  hashmap.Set(3,3);
  hashmap.Set(4,4);
  hashmap.Set(5,5);
  hashmap.Print();

  Print(hashmap.Includes(5));
  Print(hashmap.Includes(10));

  return 0;
}
