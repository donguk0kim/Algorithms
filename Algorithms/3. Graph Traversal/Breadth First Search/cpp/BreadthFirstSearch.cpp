#include "BreadthFirstSearch.hpp"

inline std::vector<BSTNode*> bfs(BSTNode* root) {
  BSTNode* node;
  std::vector<BSTNode*> children;
  std::vector<BSTNode*> queue { root };
  std::vector<BSTNode*> order { root };
  
  while (!queue.empty()) {
    node = queue[0];
    queue.erase(queue.begin());
    children = node->children();
    
    for (int index = 0; index < children.size(); index++) {
      queue.push_back(children[index]);
      order.push_back(children[index]);
    }
  }
  
  return order;
}
