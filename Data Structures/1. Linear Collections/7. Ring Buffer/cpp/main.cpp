#include "RingBuffer.hpp"

// debugger
void print(int value) {
  std::cout << value << std::endl;
}

void sprint(const char* string) {
  std::cout << string << std::endl;
}

int main() {
  
  // test case - basic operations
  sprint("test case - basic operations");
  RingBuffer array;
  array.push(3);
  array.unshift(2);
  array.unshift(1);
  array.push(4);
  array.unshift(0);
  array.push(5);
  array.pop();
  array.shift();
  array.shift();
  array.print();
  
  // test case - accessors
  sprint("test case - accessors");
  print(array[0]);
  print(array[1]);
  print(array[2]);
  print(array[3]);
  print(array[4]);
  print(array[5]);
  
  return 0;
}
