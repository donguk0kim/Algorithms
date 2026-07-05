#include <vector>
#include <unordered_map>

class Frog {
public:
  std::unordered_map<int, std::vector<std::vector<int>>> cache;
  
public:
  Frog();
  std::vector<std::vector<int>> topDown(int numSteps);
  std::vector<std::vector<int>> bottomUp(int numSteps);
};
