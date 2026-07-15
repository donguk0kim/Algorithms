#include "hash_set.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

/* constructor */
HashSet::HashSet() : count_{0}, num_buckets_{5} {
  store_ = new std::vector<int>[num_buckets_];
}


/* basic operations */
int HashSet::length() const {
  return count_;
}

// O(1)
void HashSet::insert(int value) {
  if (includes(value)) return;
  if (count_ == num_buckets_) resize();
  int internal = bucketIndex(value, num_buckets_);
  std::vector<int>* bucket = &store_[internal];
  bucket->push_back(value);
  count_++;
}

// O(1) but worst case O(k)
void HashSet::remove(int value) {
  int internal = bucketIndex(value, num_buckets_);
  std::vector<int>* bucket = &store_[internal];
  int index = indexAt(*bucket, value);
  if (index == -1) return;
  bucket->erase(bucket->begin() + index);
  count_--;
}

// O(1) but worst case O(k)
bool HashSet::includes(int value) const {
  int internal = bucketIndex(value, num_buckets_);
  std::vector<int> bucket = store_[internal];
  return std::find(bucket.begin(), bucket.end(), value) != bucket.end();
}

/* debugger */
void HashSet::print() const {
  std::cout << "{\n";
  for (int index_row = 0; index_row < num_buckets_; index_row++) {
    std::cout << "{ ";
    for (int index_col = 0; index_col < store_[index_row].size(); index_col++) {
      std::cout << store_[index_row][index_col];
      if (index_col < store_[index_row].size() - 1) std::cout << ", ";
    }
    std::cout << " }";
    if (index_row < num_buckets_ - 1) std::cout << ",\n";
  }
  std::cout << "\n}\n" << std::endl;
}


/* private */
int HashSet::hash(int value) const {
  std::hash<std::string> hasher;
  std::stringstream string;
  string << value;
  return (int) hasher(string.str());
}

int HashSet::bucketIndex(int value, int n_buckets) const {
  int hash_value = hash(value);
  if (hash_value >= 0) return hash_value % n_buckets;
  return (-1 * hash_value) % n_buckets;
}

int HashSet::indexAt(std::vector<int> bucket, int value) const {
  for (int index = 0; index < bucket.size(); index++) {
    if (bucket[index] == value) return index;
  }
  return -1;
}

void HashSet::resize() {
  int value;
  int new_index;
  int new_buckets = num_buckets_ * 2;
  std::vector<int>* new_store = new std::vector<int>[new_buckets];

  for (int bucket_idx = 0; bucket_idx < num_buckets_; bucket_idx++) {
    for (int index = 0; index < store_[bucket_idx].size(); index++) {
      value = store_[bucket_idx][index];
      new_index = bucketIndex(value, new_buckets);
      new_store[new_index].push_back(value);
    }
  }

  delete[] store_;
  store_ = new_store;
  num_buckets_ = new_buckets;
}
