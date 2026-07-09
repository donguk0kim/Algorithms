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
  static int parent_index(int childIndex);
  static std::vector<int> child_indices(int parent_index, int count);
  static int index_of_max(std::vector<int>& array, std::vector<int>& indices);
  
  // advanced operations
  static void heapify_up(std::vector<int>& array, int childIndex);
  static void heapify_down(std::vector<int>& array, int parent_index, int count);
  
  // debugger
  static void print(std::vector<int>& array);
};
