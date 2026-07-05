#include <iostream>
#include "HashSet.hpp"

void print(int number) {
  std::cout << number << std::endl;
}

void sprint(const char* string) {
  std::cout << string << std::endl;
}

int main() {
  
  // test case - HashSet::insert
  sprint("test case - HashSet::insert");
  HashSet hashset;
  hashset.insert(1);
  hashset.insert(2);
  hashset.insert(3);
  hashset.insert(4);
  hashset.insert(5);
  hashset.insert(6);
  hashset.print();
  sprint("");
  
  // test case - HashSet::remove
  sprint("test case - HashSet::remove");
  hashset.remove(2);
  hashset.remove(3);
  hashset.remove(10);
  hashset.print();
  sprint("");

  // test case - HashSet::includes
  sprint("test case - HashSet::includes");
  print(hashset.includes(1));
  print(hashset.includes(5));
  print(hashset.includes(10));
  sprint("");
  
  return 0;
}
