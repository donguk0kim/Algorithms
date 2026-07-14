#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>

class BinaryMaxHeap {
  // member variables
public:
  std::vector<int> store_;

public:
  // constructor & destructor
  BinaryMaxHeap();
  ~BinaryMaxHeap();

  // basic operations
  int Max();
  int Count();
  int Extract();
  void Insert(int value);

  // helper methods
  static int ParentIndex(int child_index);
  static std::vector<int> ChildIndices(int parent_index, int count);
  static int IndexOfMax(std::vector<int>& array, std::vector<int>& indices);

  // advanced operations
  static void HeapifyUp(std::vector<int>& array, int child_index);
  static void HeapifyDown(std::vector<int>& array, int parent_index, int count);

  // debugger
  static void Print(std::vector<int>& array);
};
