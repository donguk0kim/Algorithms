#include <algorithm>
#include "BinaryMaxHeap.hpp"

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
  heapifyDown(store, 0, count());
  return maximum;
}

// O(log(n))
void BinaryMaxHeap::insert(int value) {
  store.push_back(value);
  BinaryMaxHeap::heapifyUp(store, count() - 1);
}

// helper methods
int BinaryMaxHeap::parentIndex(int childIndex) {
  int index = (childIndex - 1) / 2;
  if (childIndex < 0) throw std::out_of_range("Root has no parent");
  return index;
}

std::vector<int> BinaryMaxHeap::childIndices(int parentIndex, int count) {
  std::vector<int> indices;
  int left = (parentIndex * 2 + 1);
  int rite = (parentIndex * 2 + 2);
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
void BinaryMaxHeap::heapifyUp(std::vector<int>& array, int childIndex) {
  if (childIndex == 0) return;
  
  int parentIndex = BinaryMaxHeap::parentIndex(childIndex);
  int parent = array[parentIndex];
  int child = array[childIndex];
  
  if (child > parent) {
    array[childIndex] = parent;
    array[parentIndex] = child;
    BinaryMaxHeap::heapifyUp(array, parentIndex);
  }
}

void BinaryMaxHeap::heapifyDown(std::vector<int>& array, int parentIndex, int count) {
  std::vector<int> indices = BinaryMaxHeap::childIndices(parentIndex, (int) count);
  int childIndex = BinaryMaxHeap::indexOfMax(array, indices);
  if (childIndex == -1) return;
  int parent = array[parentIndex];
  int child = array[childIndex];
  
  if (parent < child) {
    array[childIndex] = parent;
    array[parentIndex] = child;
    BinaryMaxHeap::heapifyDown(array, childIndex, count);
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
