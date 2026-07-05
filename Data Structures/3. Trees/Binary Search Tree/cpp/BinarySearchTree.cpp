#include "BinarySearchTree.hpp"

/* constructor */
BinarySearchTree::BinarySearchTree(BSTNode* root) :
  root{root} {
}

BinarySearchTree::~BinarySearchTree() {
  if (root) delete root;
}

/* basic operations */
// O(log(n))
BSTNode* BinarySearchTree::insert(int value) {
  BSTNode* node = new BSTNode(value);
  if (root == nullptr) {
    root = node;
  } else {
    root->append(node);
  }
  return node;
}

// O(log(n))
void BinarySearchTree::remove(int value) {
  std::vector<BSTNode*> pair = getTarget(value);
  BSTNode* target = pair[0];
  BSTNode* parent = pair[1];
  
  if (target == root) {
    BSTNode* replacement = root->left->max();
    remove(replacement->value);
    replacement->left = root->left;
    replacement->rite = root->rite;
    root = replacement;
    return;
  }
  
  bool isLeft = false;
  if (target->value <= parent->value) isLeft = true;
  
  if (target->children().size() == 0) {
    isLeft ? parent->left = nullptr : parent->rite = nullptr;
    return;
  }
  
  if (target->children().size() == 1) {
    if (target->left) {
      isLeft ? parent->left = target->left : parent->rite = target->left;
    } else {
      isLeft ? parent->left = target->rite : parent->rite = target->rite;
    }
    return;
  }
  
  if (target->children().size() == 2) {
    BSTNode* replacement = target->left->max();
    remove(replacement->value);
    replacement->left = target->left;
    replacement->rite = target->rite;
    isLeft ? parent->left = replacement : parent->rite = replacement;
  }
}

// O(log(n))
BSTNode* BinarySearchTree::find(int value) const {
  BSTNode* node = root;
  while (node) {
    if (node->value == value) return node;
    node = (value < node->value) ? node->left : node->rite;
  }
  return nullptr;
}

// O(log(n))
bool BinarySearchTree::includes(int value) const {
  BSTNode* node = root;
  while (node) {
    if (node->value == value) return true;
    node = (value < node->value) ? node->left : node->rite;
  }
  return false;
}

std::vector<BSTNode*> BinarySearchTree::getTarget(int value) const {
  BSTNode* target = root;
  BSTNode* parent = nullptr;
  std::vector<BSTNode*> pair;
  
  while (target) {
    if (target->value == value) {
      pair.push_back(target);
      pair.push_back(parent);
      return pair;
    }
    parent = target;
    target = (value < target->value) ? target->left : target->rite;
  }
  
  return pair;
}

int BinarySearchTree::depth(BSTNode* node) const {
  if (!node) return 0;
  int left = depth(node->left) + 1;
  int rite = depth(node->rite) + 1;
  return left >= rite ? left : rite;
}

bool BinarySearchTree::isBalanced(BSTNode* node) const {
  if (!node) return true;
  int left = depth(node->left);
  int rite = depth(node->rite);
  int difference = abs(left - rite);
  
  if (difference <= 1) {
    bool leftBal = isBalanced(node->rite);
    bool riteBal = isBalanced(node->left);
    return leftBal && riteBal;
  } else {
    return false;
  }
}
