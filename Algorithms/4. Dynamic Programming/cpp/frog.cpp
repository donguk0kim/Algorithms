#include "frog.hpp"

Frog::Frog() {
  cache_[1] = std::vector<std::vector<int>> { { 1 } };
  cache_[2] = std::vector<std::vector<int>> { { 1, 1 }, { 2 } };
  cache_[3] = std::vector<std::vector<int>> { { 1, 1, 1 }, { 1, 2 }, { 2, 1 }, { 3 } };
}

// Top Down
std::vector<std::vector<int>> Frog::TopDown(int num_steps) {
  if (!cache_[num_steps].empty()) return cache_[num_steps];

  for (int add = 1; add <= 3; add++) {
    std::vector<std::vector<int>> steps = TopDown(num_steps - add);

    for (int k = 0; k < steps.size(); k++) {
      std::vector<int> step = steps[k];
      step.push_back(add);
      cache_[num_steps].push_back(step);
    }
  }

  return cache_[num_steps];
}

// Bottom Up
std::vector<std::vector<int>> Frog::BottomUp(int num_steps) {
  for (int index = 4; index <= num_steps; index++) {

    for (int add = 1; add <= 3; add++) {
      std::vector<std::vector<int>> steps = cache_[index - add];

      for (int k = 0; k < steps.size(); k++) {
        std::vector<int> step = steps[k];
        step.push_back(add);
        cache_[index].push_back(step);
      }
    }
  }

  return cache_[num_steps];
}
