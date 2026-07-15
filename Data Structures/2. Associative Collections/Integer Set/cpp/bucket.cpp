#include "bucket.hpp"

#include <iostream>
#include <sstream>
#include <string>

/* constructor */
Bucket::Bucket() {
}

/* Accessors */
int& Bucket::operator[](int index) {
  return store_[index];
}

/* Basic Operations */
int Bucket::length() const {
  return (int) store_.size();
}

// O(1)
void Bucket::push(int value) {
  store_.push_back(value);
}

// O(1) but worst case O(n)
void Bucket::remove(int value) {
  int index = -1;
  for (int k = 0; k < store_.size(); k++) {
    if (store_[k] == value) {
      index = k;
      break;
    }
  }
  if (index == -1) return;
  store_.erase(store_.begin() + index);
}

// O(1) but worst case O(n)
bool Bucket::includes(int value) const {
  for (int index = 0; index < store_.size(); index++) {
    if (store_[index] == value) return true;
  }
  return false;
}
