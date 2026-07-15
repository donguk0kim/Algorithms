#pragma once

#include <iostream>
#include <vector>

// naive
std::vector<int> quicksort(std::vector<int> array);

// in place
void quicksortInplace(std::vector<int>& array, int start, int numel);
int partition(std::vector<int>& array, int start, int numel);

// iterative
std::vector<int> quicksortIterative(std::vector<int> array);

// debugger
void print(std::vector<int> array);
