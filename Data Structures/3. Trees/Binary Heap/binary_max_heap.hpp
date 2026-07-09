#include <vector>
#include <iostream>
#include <stdexcept>

class BinaryMaxHeap {
  // member variables
public:
  std::vector<int> store;
  
public:
  // constructor & destructor
  BinaryMaxHeap();
  ~BinaryMaxHeap();
  
  // basic operations
  int max();
  int count();
  int extract();
  void insert(int value);
  
  // helper methods
  static int parentIndex(int childIndex);
  static std::vector<int> childIndices(int parentIndex, int count);
  static int indexOfMax(std::vector<int>& array, std::vector<int>& indices);
  
  // advanced operations
  static void heapifyUp(std::vector<int>& array, int childIndex);
  static void heapifyDown(std::vector<int>& array, int parentIndex, int count);
  
  // debugger
  static void print(std::vector<int>& array);
};
