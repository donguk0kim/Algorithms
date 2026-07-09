#include <vector>
#include <iostream>

// naive
std::vector<int> quicksort(std::vector<int> array);

// in place
void quicksort_inplace(std::vector<int>& array, int start, int numel);
int partition(std::vector<int>& array, int start, int numel);

// iterative
std::vector<int> quicksort_iterative(std::vector<int> array);

// debugger
void print(std::vector<int> array);
