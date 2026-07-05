#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "IntegerSet.hpp"

/* constructor */
IntegerSet::IntegerSet() : count{0}, numBuckets{5} {
  store = new Bucket[numBuckets];
  fill();
}

/* basic operations */
int IntegerSet::length() const {
  return count;
}

// O(1) ammortized
void IntegerSet::insert(int val) {
  if (count == numBuckets) resize();
  int internal = bucketIndex(val, numBuckets);
  Bucket* bucket = &store[internal];
  bucket->push(val);
  count++;
}

// O(1) but worst case O(k)
void IntegerSet::remove(int val) {
  Bucket* bucket = &store[bucketIndex(val, numBuckets)];
  bucket->remove(val);
  count--;
}

// O(1) but worst case O(k)
bool IntegerSet::includes(int val) const {
  int internal = bucketIndex(val, numBuckets);
  Bucket* bucket = &store[internal];
  return bucket->includes(val);
}

/* debugger */
void IntegerSet::print() const {
  std::cout << "{\n";
  for (int indexRow = 0; indexRow < numBuckets; indexRow++) {
    std::cout << "{ ";
    for (int indexCol = 0; indexCol < store[indexRow].length(); indexCol++) {
      std::cout << store[indexRow][indexCol];
      if (indexCol < store[indexRow].length() - 1) std::cout << ", ";
    }
    std::cout << " }";
    if (indexRow < numBuckets - 1) std::cout << ",\n";
  }
  std::cout << "\n}\n" << std::endl;
}

/* private */
void IntegerSet::fill() {
  for (int indexRow = 0; indexRow < numBuckets; indexRow++) {
    store[indexRow] = *(new Bucket);
  }
}

int IntegerSet::bucketIndex(int val, int nBuckets) const {
  int hashValue = hash(val);
  if (hashValue > 0) {
    return hashValue % nBuckets;
  } else {
    return (-1 * hashValue) % nBuckets;
  }
}

int IntegerSet::hash(int val) const {
  std::hash<std::string> hasher;
  std::stringstream string;
  string << val;
  return (int) hasher(string.str());
}

void IntegerSet::resize() {
  int value;
  int bucketIdx;
  Bucket* bucket;
  int new_buckets = numBuckets * 2;
  Bucket* new_store = new Bucket[new_buckets];
  
  for (int indexRow = 0; indexRow < new_buckets; indexRow++) {
    new_store[indexRow] = *(new Bucket);
  }
  
  for (int indexRow = 0; indexRow < numBuckets; indexRow++) {
    bucket = &store[indexRow];
    for (int indexCol = 0; indexCol < bucket->length(); indexCol++) {
      value = (*bucket)[indexCol];
      bucketIdx = bucketIndex(value, new_buckets);
      bucket = &new_store[bucketIdx];
      bucket->push(value);
    }
  }
  
  delete[] store;
  store = new_store;
  numBuckets = new_buckets;
}
