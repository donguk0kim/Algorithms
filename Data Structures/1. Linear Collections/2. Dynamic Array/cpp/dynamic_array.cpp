#include <iostream>
#include <stdexcept>
#include "dynamic_array.hpp"

/* Constructor & Destructor */
DynamicArray::DynamicArray() : count{0}, capacity{5} {
  store = new int[capacity];
  fill();
}

DynamicArray::~DynamicArray() {
  delete[] store;
}

/* Basic Operations */

// O(1)
int& DynamicArray::operator[] (int index) {
  check_index(index);
  return store[index];
}

// O(1)
void DynamicArray::push(int val) {
  if (count == capacity) resize();
  (*this)[count] = val;
  count++;
}

// O(1)
int DynamicArray::pop() {
  check_index(count - 1);
  count--;
  (*this)[count] = NULL;
  return store[count];
}

// O(n)
void DynamicArray::unshift(int val) {
  if (count == capacity) resize();
  for (int index = count - 1; index >= 0; index--) {
    (*this)[index + 1] = (*this)[index];
  }
  (*this)[0] = val;
  count++;
}

// O(n)
int DynamicArray::shift() {
  check_index(0);
  int first = (*this)[0];
  for (int index = 1; index < count; index++) {
    (*this)[index - 1] = (*this)[index];
  }
  count--;
  (*this)[count] = NULL;
  return first;
}

void DynamicArray::print() {
  std::cout << "{ ";
  for (int index = 0; index < capacity; index++) {
    std::cout << store[index];
    if (index < capacity - 1) std::cout << ", ";
  }
  std::cout << " }\n" << std::endl;
}

/* Private */
void DynamicArray::check_index(int index) {
  if (is_invalid(index)) {
    throw std::out_of_range("Index out of bounds");
  }
}

bool DynamicArray::is_invalid(int index) {
  return index < 0;
}

void DynamicArray::resize() {
  int new_capacity = capacity * 2;
  int* new_store = new int[capacity];
  
  for (int index = 0; index < count; index++) {
    new_store[index] = (*this)[index];
  }
  
  delete[] store;
  store = new_store;
  capacity = new_capacity;
  fill();
}

void DynamicArray::fill() {
  for (int index = count; index < capacity; index++) {
    (*this)[index] = NULL;
  }
}
