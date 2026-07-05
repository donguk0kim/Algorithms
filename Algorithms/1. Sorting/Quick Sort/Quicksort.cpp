#include <iostream>
#include "Quicksort.hpp"

// debugger
void print(std::vector<int> array) {
  std::cout << "{ ";
  for (int index = 0; index < array.size(); index++) {
    std::cout << array[index];
    if (index < array.size() - 1) std::cout << ", ";
  }
  std::cout << " }\n" << std::endl;
}

// nlog(n) but worst case n^2
std::vector<int> quicksort(std::vector<int> array) {
  int length = (int) array.size();
  if (length <= 1) return array;
  
  int pivotIndex = length / 2;
  int pivot = array[pivotIndex];
  
  std::vector<int> left;
  std::vector<int> pivs;
  std::vector<int> rite;
  
  for (int index = 0; index < length; index++) {
    int element = array[index];
    
    if (element < pivot) {
      left.push_back(element);
    } else if (element > pivot) {
      rite.push_back(element);
    } else {
      pivs.push_back(element);
    }
  }
  
  left = quicksort(left);
  rite = quicksort(rite);
  left.insert(left.end(), pivs.begin(), pivs.end());
  left.insert(left.end(), rite.begin(), rite.end());
  return left;
}


// nlog(n) but worst case n^2
void quicksortInplace(std::vector<int>& array, int start, int end) {
  if (end <= start) return;
  int wall = partition(array, start, end);
  quicksortInplace(array, start, wall - 1);
  quicksortInplace(array, wall + 1, end);
}

int partition(std::vector<int>& array, int start, int end) {
  int wall = start;
  int pivot = array[start];

  for (int k = (start + 1); k <= end; k++) {
    int element = array[k];
    
    if (element <= pivot) {
      wall++;
      array[k] = array[wall];
      array[wall] = element;
    }
  }
  
  array[start] = array[wall];
  array[wall] = pivot;
  return wall;
}
