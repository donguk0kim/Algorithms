#include "dynamic_array.hpp"

int main() {

  // test cases
  DynamicArray array;
  array.Push(1);
  array.Push(2);
  array.Push(3);
  array.Push(4);
  array.Push(5);
  array.Print();

  array.Pop();
  array.Shift();
  array.Pop();
  array.Shift();
  array.Print();

  array.Unshift(2);
  array.Unshift(1);
  array.Push(4);
  array.Push(5);
  array.Print();

  array.Push(6);
  array.Push(7);
  array.Push(8);
  array.Push(9);
  array.Push(10);
  array.Print();

  return 0;
}
