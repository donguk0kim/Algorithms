#include <string>
#include <sstream>
#include <iostream>
#include "Bucket.hpp"

/* constructor */
Bucket::Bucket() {
}

/* Accessors */
int& Bucket::operator[](int index) {
  return store[index];
}

/* Basic Operations */
int Bucket::length() const {
  return (int) store.size();
}

// O(1)
void Bucket::push(int value) {
  store.push_back(value);
}

// O(1) but worst case O(n)
void Bucket::remove(int value) {
  int index = -1;
  for (int k = 0; k < store.size(); k++) {
    if (store[k] == value) {
      index = k;
      break;
    }
  }
  if (index == -1) return;
  store.erase(store.begin() + index);
}

// O(1) but worst case O(n)
bool Bucket::includes(int value) const {
  for (int index = 0; index < store.size(); index++) {
    if (store[index] == value) return true;
  }
  return false;
}
