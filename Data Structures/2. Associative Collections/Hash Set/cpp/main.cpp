#include "hash_set.hpp"

#include <iostream>

void Print(int number) {
  std::cout << number << std::endl;
}

void Sprint(const char* string) {
  std::cout << string << std::endl;
}

int main() {

  // test case - HashSet::Insert
  Sprint("test case - HashSet::Insert");
  HashSet hashset;
  hashset.Insert(1);
  hashset.Insert(2);
  hashset.Insert(3);
  hashset.Insert(4);
  hashset.Insert(5);
  hashset.Insert(6);
  hashset.Print();
  Sprint("");

  // test case - HashSet::Remove
  Sprint("test case - HashSet::Remove");
  hashset.Remove(2);
  hashset.Remove(3);
  hashset.Remove(10);
  hashset.Print();
  Sprint("");

  // test case - HashSet::Includes
  Sprint("test case - HashSet::Includes");
  Print(hashset.Includes(1));
  Print(hashset.Includes(5));
  Print(hashset.Includes(10));
  Sprint("");

  return 0;
}
