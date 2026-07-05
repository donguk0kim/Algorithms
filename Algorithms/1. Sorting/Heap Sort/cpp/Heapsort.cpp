#include "Heapsort.hpp"
#include "BinaryMaxHeap.hpp"

using BMH = BinaryMaxHeap;

// O(nlog(n))
std::vector<int> heapsort(std::vector<int> array) {
  BMH heap;
  std::vector<int> result;
  for (int k = 0; k < array.size(); k++) heap.insert(array[k]);
  while (heap.count() > 0) result.push_back(heap.extract());
  return result;
}

// O(nlog(n))
void heapsortInplace(std::vector<int>& array) {
  int count = (int) array.size();
  for (int k = 0; k < count; k++) BMH::heapifyUp(array, k);
  
  int temp;
  while (count > 0) {
    count--;
    temp = array[0];
    array[0] = array[count];
    array[count] = temp;
    BMH::heapifyDown(array, 0, count);
  }
}
