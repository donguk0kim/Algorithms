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
int BinaryMaxHeap::Count() {
  return (int) store_.size();
}

int BinaryMaxHeap::Max() {
  return store_.front();
}

// O(log(n))
int BinaryMaxHeap::Extract() {
  int maximum = Max();
  store_[0] = store_.back();
  store_.pop_back();
  HeapifyDown(store_, 0, Count());
  return maximum;
}

// O(log(n))
void BinaryMaxHeap::Insert(int value) {
  store_.push_back(value);
  BinaryMaxHeap::HeapifyUp(store_, Count() - 1);
}

// helper methods
int BinaryMaxHeap::ParentIndex(int child_index) {
  int index = (child_index - 1) / 2;
  if (child_index < 0) throw std::out_of_range("Root has no parent");
  return index;
}

std::vector<int> BinaryMaxHeap::ChildIndices(int parent_index, int count) {
  std::vector<int> indices;
  int left = (parent_index * 2 + 1);
  int rite = (parent_index * 2 + 2);
  if (left < count) indices.push_back(left);
  if (rite < count) indices.push_back(rite);
  return indices;
}

int BinaryMaxHeap::IndexOfMax(std::vector<int>& array, std::vector<int>& indices) {
  if (indices.size() == 0) return -1;
  if (indices.size() == 1) return indices.front();

  int left = indices[0];
  int rite = indices[1];
  return array[left] > array[rite] ? left : rite;
}

// advanced methods
void BinaryMaxHeap::HeapifyUp(std::vector<int>& array, int child_index) {
  if (child_index == 0) return;

  int parent_index = BinaryMaxHeap::ParentIndex(child_index);
  int parent = array[parent_index];
  int child = array[child_index];

  if (child > parent) {
    array[child_index] = parent;
    array[parent_index] = child;
    BinaryMaxHeap::HeapifyUp(array, parent_index);
  }
}

void BinaryMaxHeap::HeapifyDown(std::vector<int>& array, int parent_index, int count) {
  std::vector<int> indices = BinaryMaxHeap::ChildIndices(parent_index, (int) count);
  int child_index = BinaryMaxHeap::IndexOfMax(array, indices);
  if (child_index == -1) return;
  int parent = array[parent_index];
  int child = array[child_index];

  if (parent < child) {
    array[child_index] = parent;
    array[parent_index] = child;
    BinaryMaxHeap::HeapifyDown(array, child_index, count);
  }
}

// debugger
void BinaryMaxHeap::Print(std::vector<int>& array) {
  std::cout << "{ ";
  for (int index = 0; index < array.size(); index++) {
    std::cout << array[index];
    if (index < array.size() - 1) std::cout << ", ";
  }
  std::cout << " }\n" << std::endl;
}
