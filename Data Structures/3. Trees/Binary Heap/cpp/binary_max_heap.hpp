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
  int max();
  int count();
  int extract();
  void insert(int value);

  // helper methods
  static int parentIndex(int child_index);
  static std::vector<int> childIndices(int parent_index, int count);
  static int indexOfMax(std::vector<int>& array, std::vector<int>& indices);

  // advanced operations
  static void heapifyUp(std::vector<int>& array, int child_index);
  static void heapifyDown(std::vector<int>& array, int parent_index, int count);

  // debugger
  static void print(std::vector<int>& array);
};
