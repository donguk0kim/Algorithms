#include <algorithm>
#include "binary_max_heap.hpp"

// constructor
BinaryMaxHeap::BinaryMaxHeap() {
  std::vector<int> store;
}

// destructor
BinaryMaxHeap::~BinaryMaxHeap() {
  store.clear();
}

// basic operations
int BinaryMaxHeap::count() {
  return (int) store.size();
}

int BinaryMaxHeap::max() {
  return store.front();
}

// O(log(n))
int BinaryMaxHeap::extract() {
  int maximum = max();
  store[0] = store.back();
  store.pop_back();
  heapify_down(store, 0, count());
  return maximum;
}

// O(log(n))
void BinaryMaxHeap::insert(int value) {
  store.push_back(value);
  BinaryMaxHeap::heapify_up(store, count() - 1);
}

// helper methods
int BinaryMaxHeap::parent_index(int childIndex) {
  int index = (childIndex - 1) / 2;
  if (childIndex < 0) throw std::out_of_range("Root has no parent");
  return index;
}

std::vector<int> BinaryMaxHeap::child_indices(int parent_index, int count) {
  std::vector<int> indices;
  int left = (parent_index * 2 + 1);
  int rite = (parent_index * 2 + 2);
  if (left < count) indices.push_back(left);
  if (rite < count) indices.push_back(rite);
  return indices;
}

int BinaryMaxHeap::index_of_max(std::vector<int>& array, std::vector<int>& indices) {
  if (indices.size() == 0) return -1;
  if (indices.size() == 1) return indices.front();
  
  int left = indices[0];
  int rite = indices[1];
  return array[left] > array[rite] ? left : rite;
}

// advanced methods
void BinaryMaxHeap::heapify_up(std::vector<int>& array, int childIndex) {
  if (childIndex == 0) return;
  
  int parent_index = BinaryMaxHeap::parent_index(childIndex);
  int parent = array[parent_index];
  int child = array[childIndex];
  
  if (child > parent) {
    array[childIndex] = parent;
    array[parent_index] = child;
    BinaryMaxHeap::heapify_up(array, parent_index);
  }
}

void BinaryMaxHeap::heapify_down(std::vector<int>& array, int parent_index, int count) {
  std::vector<int> indices = BinaryMaxHeap::child_indices(parent_index, (int) count);
  int childIndex = BinaryMaxHeap::index_of_max(array, indices);
  if (childIndex == -1) return;
  int parent = array[parent_index];
  int child = array[childIndex];
  
  if (parent < child) {
    array[childIndex] = parent;
    array[parent_index] = child;
    BinaryMaxHeap::heapify_down(array, childIndex, count);
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
