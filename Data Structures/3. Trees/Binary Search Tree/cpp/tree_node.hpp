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
  TreeNode* Max();
  bool Unbound() const;
  void Append(TreeNode* node);
  std::vector<TreeNode*> Children() const;

  // traversal
  std::vector<TreeNode*> Bfs();
  void Dfs(std::vector<TreeNode*>& order);

  // debugger
  void PrintBfs();
  void PrintDfs();
};
