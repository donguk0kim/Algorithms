#include "integer_set.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/* constructor */
IntegerSet::IntegerSet() : count_{0}, num_buckets_{5} {
  store_ = new Bucket[num_buckets_];
  Fill();
}

/* basic operations */
int IntegerSet::Length() const {
  return count_;
}

// O(1) ammortized
void IntegerSet::Insert(int val) {
  if (count_ == num_buckets_) Resize();
  int internal = BucketIndex(val, num_buckets_);
  Bucket* bucket = &store_[internal];
  bucket->Push(val);
  count_++;
}

// O(1) but worst case O(k)
void IntegerSet::Remove(int val) {
  Bucket* bucket = &store_[BucketIndex(val, num_buckets_)];
  bucket->Remove(val);
  count_--;
}

// O(1) but worst case O(k)
bool IntegerSet::Includes(int val) const {
  int internal = BucketIndex(val, num_buckets_);
  Bucket* bucket = &store_[internal];
  return bucket->Includes(val);
}

/* debugger */
void IntegerSet::Print() const {
  std::cout << "{\n";
  for (int index_row = 0; index_row < num_buckets_; index_row++) {
    std::cout << "{ ";
    for (int index_col = 0; index_col < store_[index_row].Length(); index_col++) {
      std::cout << store_[index_row][index_col];
      if (index_col < store_[index_row].Length() - 1) std::cout << ", ";
    }
    std::cout << " }";
    if (index_row < num_buckets_ - 1) std::cout << ",\n";
  }
  std::cout << "\n}\n" << std::endl;
}

/* private */
void IntegerSet::Fill() {
  for (int index_row = 0; index_row < num_buckets_; index_row++) {
    store_[index_row] = *(new Bucket);
  }
}

int IntegerSet::BucketIndex(int val, int n_buckets) const {
  int hash_value = Hash(val);
  if (hash_value > 0) {
    return hash_value % n_buckets;
  } else {
    return (-1 * hash_value) % n_buckets;
  }
}

int IntegerSet::Hash(int val) const {
  std::hash<std::string> hasher;
  std::stringstream string;
  string << val;
  return (int) hasher(string.str());
}

void IntegerSet::Resize() {
  int value;
  int bucket_idx;
  Bucket* bucket;
  int new_buckets = num_buckets_ * 2;
  Bucket* new_store = new Bucket[new_buckets];

  for (int index_row = 0; index_row < new_buckets; index_row++) {
    new_store[index_row] = *(new Bucket);
  }

  for (int index_row = 0; index_row < num_buckets_; index_row++) {
    bucket = &store_[index_row];
    for (int index_col = 0; index_col < bucket->Length(); index_col++) {
      value = (*bucket)[index_col];
      bucket_idx = BucketIndex(value, new_buckets);
      bucket = &new_store[bucket_idx];
      bucket->Push(value);
    }
  }

  delete[] store_;
  store_ = new_store;
  num_buckets_ = new_buckets;
}
