#include "BinarySearchTree.hpp"

// debugger
void print(int value) {
  std::cout << value << std::endl;
}

// print string
void sprint(const char* string) {
  std::cout << string << std::endl;
}

int main() {
  
  // create tree
  BinarySearchTree bst;
  int values[9] { 5, 3, 7, 1, 4, 9, 0, 2, 10 };
  int length = sizeof(values) / sizeof(values[0]);
  
  for (int index = 0; index < length; index++) {
    bst.insert(values[index]);
  }
  
  // BST::insert test case
  sprint("BST::insert test case");
  print(bst.root->value == 5);
  print(bst.root->left->value == 3);
  print(bst.root->left->left->value == 1);
  print(bst.root->left->left->left->value == 0);
  print(bst.root->left->left->rite->value == 2);
  print(bst.root->left->rite->value == 4);
  print(bst.root->rite->value == 7);
  print(bst.root->rite->rite->value == 9);
  print(bst.root->rite->rite->rite->value == 10);
  sprint("");
  
  // BST::depth test case
  sprint("BST::depth test case");
  print(bst.depth(bst.root->rite));
  sprint("");
  
  // BST::isBalanced test case
  sprint("BST::isBalanced test case");
  print(bst.isBalanced(bst.root) == 0);
  print(bst.isBalanced(bst.root->left) == 1);
  print(bst.isBalanced(bst.root->rite) == 0);
  print(bst.isBalanced(bst.root->rite->rite) == 1);
  print(bst.isBalanced(bst.root->left->left) == 1);
  sprint("");
  
  // BST::remove test case
  sprint("BST::remove test case");
  bst.remove(2);
  bst.root->printBFS();
  bst.remove(3);
  bst.root->printBFS();
  bst.remove(5);
  bst.root->printBFS();
  bst.remove(7);
  bst.root->printBFS();
  sprint("");

  return 0;
}
