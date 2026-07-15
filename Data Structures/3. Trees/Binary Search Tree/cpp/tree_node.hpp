#pragma once

#include <iostream>
#include <vector>

class TreeNode {
public:
  // member variables
  int value_;
  TreeNode* left_;
  TreeNode* rite_;

public:
  // constructor & destructor
  TreeNode(int value = 0);
  ~TreeNode();

  // basic operations
  TreeNode* max();
  bool unbound() const;
  void append(TreeNode* node);
  std::vector<TreeNode*> children() const;

  // traversal
  std::vector<TreeNode*> bfs();
  void dfs(std::vector<TreeNode*>& order);

  // debugger
  void printBfs();
  void printDfs();
};
