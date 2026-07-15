#include "hash_map.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

/* constructor */
HashMap::HashMap():
  count_{0},
  num_buckets_{5} {
  store_ = new std::list<int>[num_buckets_];
}

/* accessors */
int HashMap::get(int key) const {
  int internal = bucketIndex(key, num_buckets_);
  std::list<int>* bucket = &store_[internal];
  Node* node = **std::find(bucket->begin(), bucket->end(), key);
  return node->val;
}

void HashMap::set(int key, int val) {
  if (count_ == num_buckets_) resize();
  int internal = bucketIndex(key, num_buckets_);
  std::list<int>* bucket = &store_[internal];
  bucket->push(key, val);
}

/* basic operations */
void HashMap::remove(int key) {
  int internal = bucketIndex(key, num_buckets_);
  std::list<int>* bucket = &store_[internal];
  bucket->remove(key);
}

bool HashMap::includes(int key) const {
  int internal = bucketIndex(key, num_buckets_);
  std::list<int>* bucket = &store_[internal];
  return bucket->includes(key);
}

/* debugger */
void HashMap::print() const {
  std::cout << "\n{\n";
  for (int index_row = 0; index_row < num_buckets_; index_row++) {
    store_[index_row].print();
  }
  std::cout << "}\n" << std::endl;
}

/* private */
int HashMap::bucketIndex(int key, int n_buckets) const {
  int hash_value = hash(key);
  if (hash_value >= 0) return hash_value % n_buckets;
  return (-1 * hash_value) % n_buckets;
}

int HashMap::hash(int value) const {
  std::hash<std::string> hasher;
  std::stringstream string;
  string << value;
  return (int) hasher(string.str());
}

void HashMap::resize() {
  int new_buckets = num_buckets_ * 2;
  LinkedList* new_store = new LinkedList[new_buckets];

  for (int bucket_idx = 0; bucket_idx < num_buckets_; bucket_idx++) {
    for (int index = 0; index < store_[bucket_idx].count; index++) {
      int value = store_[bucket_idx][index];
      int new_index = bucketIndex(value, new_buckets);
      new_store[new_index].push_back(value);
    }
  }

  delete[] store_;
  store_ = new_store;
  num_buckets_ = new_buckets;
}
