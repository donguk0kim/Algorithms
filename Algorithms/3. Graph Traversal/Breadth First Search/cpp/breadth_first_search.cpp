#include "breadth_first_search.hpp"

inline std::vector<TreeNode*> Bfs(TreeNode* root) {
  TreeNode* node;
  std::vector<TreeNode*> children;
  std::vector<TreeNode*> queue { root };
  std::vector<TreeNode*> order { root };

  while (!queue.empty()) {
    node = queue[0];
    queue.erase(queue.begin());
    children = node->Children();

    for (int index = 0; index < children.size(); index++) {
      queue.push_back(children[index]);
      order.push_back(children[index]);
    }
  }

  return order;
}
