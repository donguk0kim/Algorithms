#pragma once

#include "tree_node.hpp"

class BinarySearchTree {
public:
  // member variables
  TreeNode* root_;

public:
  // constructor & destructor
  BinarySearchTree(TreeNode* root = nullptr);
  ~BinarySearchTree();

  // basic operations
  void remove(int value);
  TreeNode* insert(int value);
  bool includes(int value) const;
  TreeNode* find(int value) const;

  // advanced operations
  int depth(TreeNode* node) const;
  bool isBalanced(TreeNode* node) const;

private:
  // internal
  std::vector<TreeNode*> getTarget(int value) const;
};
