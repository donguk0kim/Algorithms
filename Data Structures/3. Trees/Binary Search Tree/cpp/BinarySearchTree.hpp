#include "BSTNode.hpp"

class BinarySearchTree {
public:
  // member variables
  BSTNode* root;
    
public:
  // constructor & destructor
  BinarySearchTree(BSTNode* root = nullptr);
  ~BinarySearchTree();
  
  // basic operations
  void remove(int value);
  BSTNode* insert(int value);
  bool includes(int value) const;
  BSTNode* find(int value) const;
  
  // advanced operations
  int depth(BSTNode* node) const;
  bool isBalanced(BSTNode* node) const;
  
private:
  // internal
  std::vector<BSTNode*> getTarget(int value) const;
};
