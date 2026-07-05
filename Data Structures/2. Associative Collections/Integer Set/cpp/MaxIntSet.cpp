#include <iostream>
#include <stdexcept>
#include "MaxIntSet.hpp"

/* constructor */
MaxIntSet::MaxIntSet(int max) : capacity{max} {
  store = new bool[capacity];
  fill();
}

/* public */
// O(1)
void MaxIntSet::insert(int value) {
  checkIndex(value);
  store[value] = true;
}

// O(1)
void MaxIntSet::remove(int value) {
  checkIndex(value);
  store[value] = false;
}

// O(1)
bool MaxIntSet::includes(int value) const {
  checkIndex(value);
  return !!store[value];
}

void MaxIntSet::print() const {
  std::cout << "{ ";
  for (int index = 0; index < capacity; index++) {
    std::cout << store[index];
    if (index < capacity - 1) std::cout << ", ";
  }
  std::cout << " }\n" << std::endl;
}

/* private */
void MaxIntSet::fill() {
  for (int index = 0; index < capacity; index++) {
    store[index] = false;
  }
}

void MaxIntSet::checkIndex(int index) const {
  if (isInvalid(index)) {
    throw std::out_of_range("Index out of bounds");
  }
}

bool MaxIntSet::isInvalid(int index) const {
  return (index < 0) || (index >= capacity);
}
