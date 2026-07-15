#pragma once

#include <unordered_map>
#include <vector>

class Frog {
public:
  std::unordered_map<int, std::vector<std::vector<int>>> cache_;

public:
  Frog();
  std::vector<std::vector<int>> topDown(int num_steps);
  std::vector<std::vector<int>> bottomUp(int num_steps);
};
