#include "DepthFirstSearch.hpp"

inline void dfs(std::vector<BSTNode*>& order, BSTNode* root) {
  BSTNode* child;
  order.push_back(root);
  std::vector<BSTNode*> children = root->children();
  for (int index = 0; index < children.size(); index++) {
    child = children[index];
    child->dfs(order);
  }
}
