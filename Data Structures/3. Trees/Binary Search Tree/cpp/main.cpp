#include "binary_search_tree.hpp"

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
  print(bst.root_->value_ == 5);
  print(bst.root_->left_->value_ == 3);
  print(bst.root_->left_->left_->value_ == 1);
  print(bst.root_->left_->left_->left_->value_ == 0);
  print(bst.root_->left_->left_->rite_->value_ == 2);
  print(bst.root_->left_->rite_->value_ == 4);
  print(bst.root_->rite_->value_ == 7);
  print(bst.root_->rite_->rite_->value_ == 9);
  print(bst.root_->rite_->rite_->rite_->value_ == 10);
  sprint("");

  // BST::depth test case
  sprint("BST::depth test case");
  print(bst.depth(bst.root_->rite_));
  sprint("");

  // BST::isBalanced test case
  sprint("BST::isBalanced test case");
  print(bst.isBalanced(bst.root_) == 0);
  print(bst.isBalanced(bst.root_->left_) == 1);
  print(bst.isBalanced(bst.root_->rite_) == 0);
  print(bst.isBalanced(bst.root_->rite_->rite_) == 1);
  print(bst.isBalanced(bst.root_->left_->left_) == 1);
  sprint("");

  // BST::remove test case
  sprint("BST::remove test case");
  bst.remove(2);
  bst.root_->printBfs();
  bst.remove(3);
  bst.root_->printBfs();
  bst.remove(5);
  bst.root_->printBfs();
  bst.remove(7);
  bst.root_->printBfs();
  sprint("");

  return 0;
}
