#include "binary_max_heap.hpp"

#include <algorithm>

// constructor
BinaryMaxHeap::BinaryMaxHeap() {
  std::vector<int> store;
}

// destructor
BinaryMaxHeap::~BinaryMaxHeap() {
  store_.clear();
}

// basic operations
int BinaryMaxHeap::count() {
  return (int) store_.size();
}

int BinaryMaxHeap::max() {
  return store_.front();
}

// O(log(n))
int BinaryMaxHeap::extract() {
  int maximum = max();
  store_[0] = store_.back();
  store_.pop_back();
  heapifyDown(store_, 0, count());
  return maximum;
}

// O(log(n))
void BinaryMaxHeap::insert(int value) {
  store_.push_back(value);
  BinaryMaxHeap::heapifyUp(store_, count() - 1);
}

// helper methods
int BinaryMaxHeap::parentIndex(int child_index) {
  int index = (child_index - 1) / 2;
  if (child_index < 0) throw std::out_of_range("Root has no parent");
  return index;
}

std::vector<int> BinaryMaxHeap::childIndices(int parent_index, int count) {
  std::vector<int> indices;
  int left = (parent_index * 2 + 1);
  int rite = (parent_index * 2 + 2);
  if (left < count) indices.push_back(left);
  if (rite < count) indices.push_back(rite);
  return indices;
}

int BinaryMaxHeap::indexOfMax(std::vector<int>& array, std::vector<int>& indices) {
  if (indices.size() == 0) return -1;
  if (indices.size() == 1) return indices.front();

  int left = indices[0];
  int rite = indices[1];
  return array[left] > array[rite] ? left : rite;
}

// advanced methods
void BinaryMaxHeap::heapifyUp(std::vector<int>& array, int child_index) {
  if (child_index == 0) return;

  int parent_index = BinaryMaxHeap::parentIndex(child_index);
  int parent = array[parent_index];
  int child = array[child_index];

  if (child > parent) {
    array[child_index] = parent;
    array[parent_index] = child;
    BinaryMaxHeap::heapifyUp(array, parent_index);
  }
}

void BinaryMaxHeap::heapifyDown(std::vector<int>& array, int parent_index, int count) {
  std::vector<int> indices = BinaryMaxHeap::childIndices(parent_index, (int) count);
  int child_index = BinaryMaxHeap::indexOfMax(array, indices);
  if (child_index == -1) return;
  int parent = array[parent_index];
  int child = array[child_index];

  if (parent < child) {
    array[child_index] = parent;
    array[parent_index] = child;
    BinaryMaxHeap::heapifyDown(array, child_index, count);
  }
}

// debugger
void BinaryMaxHeap::print(std::vector<int>& array) {
  std::cout << "{ ";
  for (int index = 0; index < array.size(); index++) {
    std::cout << array[index];
    if (index < array.size() - 1) std::cout << ", ";
  }
  std::cout << " }\n" << std::endl;
}
