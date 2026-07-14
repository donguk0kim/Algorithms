#include "tree_node.hpp"

/* constructor */
TreeNode::TreeNode(int value) :
  value_{value},
  left_{nullptr},
  rite_{nullptr} {
}

TreeNode::~TreeNode() {
  if (left_) delete left_;
  if (rite_) delete rite_;
}

/* basic operations */
TreeNode* TreeNode::Max() {
  TreeNode* node = this;
  while (node->rite_) {
    node = node->rite_;
  }
  return node;
}

bool TreeNode::Unbound() const {
  return (left_ == nullptr) && (rite_ == nullptr);
}

void TreeNode::Append(TreeNode* node) {
  if (node->value_ <= value_) {
    if (left_) left_->Append(node);
    if (left_ == nullptr) left_ = node;

  } else {
    if (rite_) rite_->Append(node);
    if (rite_ == nullptr) rite_ = node;
  }
}

std::vector<TreeNode*> TreeNode::Children() const {
  std::vector<TreeNode*> children;
  if (left_) children.push_back(left_);
  if (rite_) children.push_back(rite_);
  return children;
}

/* traversal */
std::vector<TreeNode*> TreeNode::Bfs() {
  TreeNode* node;
  std::vector<TreeNode*> children;
  std::vector<TreeNode*> queue { this };
  std::vector<TreeNode*> order { this };

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

void TreeNode::Dfs(std::vector<TreeNode*>& order) {
  TreeNode* child;
  order.push_back(this);
  std::vector<TreeNode*> children = Children();
  for (int index = 0; index < children.size(); index++) {
    child = children[index];
    child->Dfs(order);
  }
}

/* debugger */
void TreeNode::PrintBfs() {
  std::vector<TreeNode*> order = Bfs();

  std::cout << "{ ";
  for (int index = 0; index < order.size(); index++) {
    std::cout << order[index]->value_;
    if (index < order.size() - 1) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}

void TreeNode::PrintDfs() {

  std::vector<TreeNode*> order;
  Dfs(order);

  std::cout << "{ ";
  for (int index = 0; index < order.size(); index++) {
    std::cout << order[index]->value_;
    if (index < order.size() - 1) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}
