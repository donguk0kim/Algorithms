#include "max_int_set.hpp"

#include <iostream>
#include <stdexcept>

/* constructor */
MaxIntSet::MaxIntSet(int max) : capacity_{max} {
  store_ = new bool[capacity_];
  fill();
}

/* public */
// O(1)
void MaxIntSet::insert(int value) {
  checkIndex(value);
  store_[value] = true;
}

// O(1)
void MaxIntSet::remove(int value) {
  checkIndex(value);
  store_[value] = false;
}

// O(1)
bool MaxIntSet::includes(int value) const {
  checkIndex(value);
  return !!store_[value];
}

void MaxIntSet::print() const {
  std::cout << "{ ";
  for (int index = 0; index < capacity_; index++) {
    std::cout << store_[index];
    if (index < capacity_ - 1) std::cout << ", ";
  }
  std::cout << " }\n" << std::endl;
}

/* private */
void MaxIntSet::fill() {
  for (int index = 0; index < capacity_; index++) {
    store_[index] = false;
  }
}

void MaxIntSet::checkIndex(int index) const {
  if (isInvalid(index)) {
    throw std::out_of_range("Index out of bounds");
  }
}

bool MaxIntSet::isInvalid(int index) const {
  return (index < 0) || (index >= capacity_);
}
