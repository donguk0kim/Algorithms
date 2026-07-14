#include "heapsort.hpp"

#include "binary_max_heap.hpp"

int main() {

  // test case BinaryMaxHeap::Insert
  BinaryMaxHeap bmh;
  std::vector<int> array { 0, 1, 2, 3, 4, 5 };
  for (int k = 0; k < array.size(); k++) bmh.Insert(array[k]);

  // test case BinaryMaxHeap::Extract
  BinaryMaxHeap::Print(bmh.store_);
  bmh.Extract();
  BinaryMaxHeap::Print(bmh.store_);
  bmh.Extract();
  BinaryMaxHeap::Print(bmh.store_);

  // test case Heapsort
  std::vector<int> result = Heapsort(array);
  BinaryMaxHeap::Print(result);

  // test case Heapsort inplace
  HeapsortInplace(array);
  BinaryMaxHeap::Print(array);

  return 0;
}
