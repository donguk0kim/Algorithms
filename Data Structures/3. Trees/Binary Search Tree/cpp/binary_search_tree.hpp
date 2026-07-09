#include "bst_node.hpp"

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
  bool is_balanced(BSTNode* node) const;
  
private:
  // internal
  std::vector<BSTNode*> get_target(int value) const;
};
