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
  void Remove(int value);
  TreeNode* Insert(int value);
  bool Includes(int value) const;
  TreeNode* Find(int value) const;

  // advanced operations
  int Depth(TreeNode* node) const;
  bool IsBalanced(TreeNode* node) const;

private:
  // internal
  std::vector<TreeNode*> GetTarget(int value) const;
};
