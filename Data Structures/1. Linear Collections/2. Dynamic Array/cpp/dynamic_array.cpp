#include "dynamic_array.hpp"

#include <iostream>
#include <stdexcept>

/* Constructor & Destructor */
DynamicArray::DynamicArray() : count_{0}, capacity_{5} {
  store_ = new int[capacity_];
  Fill();
}

DynamicArray::~DynamicArray() {
  delete[] store_;
}

/* Basic Operations */

// O(1)
int& DynamicArray::operator[] (int index) {
  CheckIndex(index);
  return store_[index];
}

// O(1)
void DynamicArray::Push(int val) {
  if (count_ == capacity_) Resize();
  (*this)[count_] = val;
  count_++;
}

// O(1)
int DynamicArray::Pop() {
  CheckIndex(count_ - 1);
  count_--;
  (*this)[count_] = NULL;
  return store_[count_];
}

// O(n)
void DynamicArray::Unshift(int val) {
  if (count_ == capacity_) Resize();
  for (int index = count_ - 1; index >= 0; index--) {
    (*this)[index + 1] = (*this)[index];
  }
  (*this)[0] = val;
  count_++;
}

// O(n)
int DynamicArray::Shift() {
  CheckIndex(0);
  int first = (*this)[0];
  for (int index = 1; index < count_; index++) {
    (*this)[index - 1] = (*this)[index];
  }
  count_--;
  (*this)[count_] = NULL;
  return first;
}

void DynamicArray::Print() {
  std::cout << "{ ";
  for (int index = 0; index < capacity_; index++) {
    std::cout << store_[index];
    if (index < capacity_ - 1) std::cout << ", ";
  }
  std::cout << " }\n" << std::endl;
}

/* Private */
void DynamicArray::CheckIndex(int index) {
  if (IsInvalid(index)) {
    throw std::out_of_range("Index out of bounds");
  }
}

bool DynamicArray::IsInvalid(int index) {
  return index < 0;
}

void DynamicArray::Resize() {
  int new_capacity = capacity_ * 2;
  int* new_store = new int[capacity_];

  for (int index = 0; index < count_; index++) {
    new_store[index] = (*this)[index];
  }

  delete[] store_;
  store_ = new_store;
  capacity_ = new_capacity;
  Fill();
}

void DynamicArray::Fill() {
  for (int index = count_; index < capacity_; index++) {
    (*this)[index] = NULL;
  }
}
