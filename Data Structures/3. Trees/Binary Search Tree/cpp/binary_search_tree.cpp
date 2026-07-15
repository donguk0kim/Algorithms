#include "binary_search_tree.hpp"

/* constructor */
BinarySearchTree::BinarySearchTree(TreeNode* root) :
  root_{root} {
}

BinarySearchTree::~BinarySearchTree() {
  if (root_) delete root_;
}

/* basic operations */
// O(log(n))
TreeNode* BinarySearchTree::insert(int value) {
  TreeNode* node = new TreeNode(value);
  if (root_ == nullptr) {
    root_ = node;
  } else {
    root_->append(node);
  }
  return node;
}

// O(log(n))
void BinarySearchTree::remove(int value) {
  std::vector<TreeNode*> pair = getTarget(value);
  TreeNode* target = pair[0];
  TreeNode* parent = pair[1];

  if (target == root_) {
    TreeNode* replacement = root_->left_->max();
    remove(replacement->value_);
    replacement->left_ = root_->left_;
    replacement->rite_ = root_->rite_;
    root_ = replacement;
    return;
  }

  bool is_left = false;
  if (target->value_ <= parent->value_) is_left = true;

  if (target->children().size() == 0) {
    is_left ? parent->left_ = nullptr : parent->rite_ = nullptr;
    return;
  }

  if (target->children().size() == 1) {
    if (target->left_) {
      is_left ? parent->left_ = target->left_ : parent->rite_ = target->left_;
    } else {
      is_left ? parent->left_ = target->rite_ : parent->rite_ = target->rite_;
    }
    return;
  }

  if (target->children().size() == 2) {
    TreeNode* replacement = target->left_->max();
    remove(replacement->value_);
    replacement->left_ = target->left_;
    replacement->rite_ = target->rite_;
    is_left ? parent->left_ = replacement : parent->rite_ = replacement;
  }
}

// O(log(n))
TreeNode* BinarySearchTree::find(int value) const {
  TreeNode* node = root_;
  while (node) {
    if (node->value_ == value) return node;
    node = (value < node->value_) ? node->left_ : node->rite_;
  }
  return nullptr;
}

// O(log(n))
bool BinarySearchTree::includes(int value) const {
  TreeNode* node = root_;
  while (node) {
    if (node->value_ == value) return true;
    node = (value < node->value_) ? node->left_ : node->rite_;
  }
  return false;
}

std::vector<TreeNode*> BinarySearchTree::getTarget(int value) const {
  TreeNode* target = root_;
  TreeNode* parent = nullptr;
  std::vector<TreeNode*> pair;

  while (target) {
    if (target->value_ == value) {
      pair.push_back(target);
      pair.push_back(parent);
      return pair;
    }
    parent = target;
    target = (value < target->value_) ? target->left_ : target->rite_;
  }

  return pair;
}

int BinarySearchTree::depth(TreeNode* node) const {
  if (!node) return 0;
  int left = depth(node->left_) + 1;
  int rite = depth(node->rite_) + 1;
  return left >= rite ? left : rite;
}

bool BinarySearchTree::isBalanced(TreeNode* node) const {
  if (!node) return true;
  int left = depth(node->left_);
  int rite = depth(node->rite_);
  int difference = abs(left - rite);

  if (difference <= 1) {
    bool left_bal = isBalanced(node->rite_);
    bool rite_bal = isBalanced(node->left_);
    return left_bal && rite_bal;
  } else {
    return false;
  }
}
