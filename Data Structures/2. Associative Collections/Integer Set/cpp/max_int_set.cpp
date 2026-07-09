#include <iostream>
#include <stdexcept>
#include "max_int_set.hpp"

/* constructor */
MaxIntSet::MaxIntSet(int max) : capacity{max} {
  store = new bool[capacity];
  fill();
}

/* public */
// O(1)
void MaxIntSet::insert(int value) {
  check_index(value);
  store[value] = true;
}

// O(1)
void MaxIntSet::remove(int value) {
  check_index(value);
  store[value] = false;
}

// O(1)
bool MaxIntSet::includes(int value) const {
  check_index(value);
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

void MaxIntSet::check_index(int index) const {
  if (is_invalid(index)) {
    throw std::out_of_range("Index out of bounds");
  }
}

bool MaxIntSet::is_invalid(int index) const {
  return (index < 0) || (index >= capacity);
}
