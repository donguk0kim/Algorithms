#include "depth_first_search.hpp"

inline void dfs(std::vector<TreeNode*>& order, TreeNode* root) {
  TreeNode* child;
  order.push_back(root);
  std::vector<TreeNode*> children = root->children();
  for (int index = 0; index < children.size(); index++) {
    child = children[index];
    child->dfs(order);
  }
}
