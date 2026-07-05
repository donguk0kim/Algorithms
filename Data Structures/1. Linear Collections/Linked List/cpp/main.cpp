#include <iostream>
#include "LinkedList.hpp"

void sprint(const char* string) {
  std::cout << string << std::endl;
}

int main() {
  
  // test case - basic operations
  sprint("test case - basic operations");
  LinkedList list;
  list.push(1, 1);
  list.push(2, 2);
  list.push(3, 3);
  list.push(4, 4);
  list.push(5, 5);
  list.remove(3);
  
  list.print();
  std::cout << list.count << std::endl;
  
  return 0;
}
