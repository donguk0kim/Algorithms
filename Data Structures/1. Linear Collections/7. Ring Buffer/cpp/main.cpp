#include "ring_buffer.hpp"

// debugger
void Print(int value) {
  std::cout << value << std::endl;
}

void Sprint(const char* string) {
  std::cout << string << std::endl;
}

int main() {

  // test case - basic operations
  Sprint("test case - basic operations");
  RingBuffer array;
  array.Push(3);
  array.Unshift(2);
  array.Unshift(1);
  array.Push(4);
  array.Unshift(0);
  array.Push(5);
  array.Pop();
  array.Shift();
  array.Shift();
  array.Print();

  // test case - accessors
  Sprint("test case - accessors");
  Print(array[0]);
  Print(array[1]);
  Print(array[2]);
  Print(array[3]);
  Print(array[4]);
  Print(array[5]);

  return 0;
}
