#include "DynamicArray.hpp"

int main() {
  
  // test cases
  DynamicArray array;
  array.push(1);
  array.push(2);
  array.push(3);
  array.push(4);
  array.push(5);
  array.print();

  array.pop();
  array.shift();
  array.pop();
  array.shift();
  array.print();

  array.unshift(2);
  array.unshift(1);
  array.push(4);
  array.push(5);
  array.print();

  array.push(6);
  array.push(7);
  array.push(8);
  array.push(9);
  array.push(10);
  array.print();
  
  return 0;
}
