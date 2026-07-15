#include "heapsort.hpp"

#include "binary_max_heap.hpp"

int main() {

  // test case BinaryMaxHeap::insert
  BinaryMaxHeap bmh;
  std::vector<int> array { 0, 1, 2, 3, 4, 5 };
  for (int k = 0; k < array.size(); k++) bmh.insert(array[k]);

  // test case BinaryMaxHeap::extract
  BinaryMaxHeap::print(bmh.store_);
  bmh.extract();
  BinaryMaxHeap::print(bmh.store_);
  bmh.extract();
  BinaryMaxHeap::print(bmh.store_);

  // test case heapsort
  std::vector<int> result = heapsort(array);
  BinaryMaxHeap::print(result);

  // test case heapsort inplace
  heapsortInplace(array);
  BinaryMaxHeap::print(array);

  return 0;
}
