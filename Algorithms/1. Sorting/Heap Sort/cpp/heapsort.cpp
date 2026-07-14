#include "heapsort.hpp"

#include "binary_max_heap.hpp"

// nlog(n)
std::vector<int> Heapsort(std::vector<int> array) {
  BinaryMaxHeap heap;
  std::vector<int> result;

  for (int k = 0; k < array.size(); k++) {
    heap.Insert(array[k]);
  }

  while (heap.Count() > 0) {
    result.push_back(heap.Extract());
  }

  return result;
}

// nlog(n)
void HeapsortInplace(std::vector<int>& array) {
  int count = (int) array.size();

  for (int k = 0; k < count; k++) {
    BinaryMaxHeap::HeapifyUp(array, k);
  }

  int temp;

  while (count > 0) {
    count--;
    temp = array[0];
    array[0] = array[count];
    array[count] = temp;
    BinaryMaxHeap::HeapifyDown(array, 0, count);
  }
}
