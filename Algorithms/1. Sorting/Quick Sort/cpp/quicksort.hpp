#pragma once

#include <iostream>
#include <vector>

// naive
std::vector<int> Quicksort(std::vector<int> array);

// in place
void QuicksortInplace(std::vector<int>& array, int start, int numel);
int Partition(std::vector<int>& array, int start, int numel);

// iterative
std::vector<int> QuicksortIterative(std::vector<int> array);

// debugger
void Print(std::vector<int> array);
