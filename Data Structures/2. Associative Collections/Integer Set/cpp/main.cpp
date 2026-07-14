#include "integer_set.hpp"
#include "max_int_set.hpp"

#include <iostream>

void Sprint(const char* string) {
  std::cout << string << std::endl;
}

int main() {

  // test case - MaxIntSet
  Sprint("test case - MaxIntSet");
  MaxIntSet maxintset(5);
  maxintset.Insert(0);
  maxintset.Insert(2);
  maxintset.Insert(4);
  maxintset.Remove(2);
  maxintset.Print();
  Sprint("");

  // test case - IntSet::Insert
  Sprint("test case - IntSet::Insert");
  IntegerSet intset;
  intset.Insert(1);
  intset.Insert(2);
  intset.Insert(3);
  intset.Insert(4);
  intset.Insert(5);
  intset.Remove(2);
  intset.Remove(3);
  intset.Print();
  Sprint("");

  // test case - IntSet::Includes
  Sprint("test case - IntSet::Includes");
  std::cout << intset.Includes(1) << std::endl;
  std::cout << intset.Includes(2) << std::endl;
  std::cout << intset.Length() << std::endl;
  Sprint("");

  return 0;
}
