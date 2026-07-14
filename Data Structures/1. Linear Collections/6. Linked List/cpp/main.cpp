#include "linked_list.hpp"

#include <iostream>

void Sprint(const char* string) {
  std::cout << string << std::endl;
}

int main() {

  // test case - basic operations
  Sprint("test case - basic operations");
  LinkedList list;
  list.Push(1, 1);
  list.Push(2, 2);
  list.Push(3, 3);
  list.Push(4, 4);
  list.Push(5, 5);
  list.Remove(3);

  list.Print();
  std::cout << list.count_ << std::endl;

  return 0;
}
