#include "max_int_set.hpp"

#include <iostream>
#include <stdexcept>

/* constructor */
MaxIntSet::MaxIntSet(int max) : capacity_{max} {
  store_ = new bool[capacity_];
  Fill();
}

/* public */
// O(1)
void MaxIntSet::Insert(int value) {
  CheckIndex(value);
  store_[value] = true;
}

// O(1)
void MaxIntSet::Remove(int value) {
  CheckIndex(value);
  store_[value] = false;
}

// O(1)
bool MaxIntSet::Includes(int value) const {
  CheckIndex(value);
  return !!store_[value];
}

void MaxIntSet::Print() const {
  std::cout << "{ ";
  for (int index = 0; index < capacity_; index++) {
    std::cout << store_[index];
    if (index < capacity_ - 1) std::cout << ", ";
  }
  std::cout << " }\n" << std::endl;
}

/* private */
void MaxIntSet::Fill() {
  for (int index = 0; index < capacity_; index++) {
    store_[index] = false;
  }
}

void MaxIntSet::CheckIndex(int index) const {
  if (IsInvalid(index)) {
    throw std::out_of_range("Index out of bounds");
  }
}

bool MaxIntSet::IsInvalid(int index) const {
  return (index < 0) || (index >= capacity_);
}
