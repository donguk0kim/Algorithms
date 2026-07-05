#include <iostream>
#include "HashMap.hpp"

void print(int value) {
  std::cout << value << std::endl;
}

int main() {
  HashMap hashmap;
  hashmap.set(1,1);
  hashmap.set(2,2);
  hashmap.set(3,3);
  hashmap.set(4,4);
  hashmap.set(5,5);
  hashmap.print();

  print(hashmap.includes(5));
  print(hashmap.includes(10));
  
  return 0;
}
