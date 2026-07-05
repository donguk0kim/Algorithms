#include <vector>
#include <iostream>

class BSTNode {
public:
  // member variables
  int value;
  BSTNode* left;
  BSTNode* rite;

public:
  // constructor & destructor
  BSTNode(int value = 0);
  ~BSTNode();

  // basic operations
  BSTNode* max();
  bool unbound() const;
  void append(BSTNode* node);
  std::vector<BSTNode*> children() const;
  
  // traversal
  std::vector<BSTNode*> bfs();
  void dfs(std::vector<BSTNode*>& order);
  
  // debugger
  void printBFS();
  void printDFS();
};
