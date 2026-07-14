#include "binary_search_tree.hpp"

// debugger
void Print(int value) {
  std::cout << value << std::endl;
}

// print string
void Sprint(const char* string) {
  std::cout << string << std::endl;
}

int main() {

  // create tree
  BinarySearchTree bst;
  int values[9] { 5, 3, 7, 1, 4, 9, 0, 2, 10 };
  int length = sizeof(values) / sizeof(values[0]);

  for (int index = 0; index < length; index++) {
    bst.Insert(values[index]);
  }

  // BST::Insert test case
  Sprint("BST::Insert test case");
  Print(bst.root_->value_ == 5);
  Print(bst.root_->left_->value_ == 3);
  Print(bst.root_->left_->left_->value_ == 1);
  Print(bst.root_->left_->left_->left_->value_ == 0);
  Print(bst.root_->left_->left_->rite_->value_ == 2);
  Print(bst.root_->left_->rite_->value_ == 4);
  Print(bst.root_->rite_->value_ == 7);
  Print(bst.root_->rite_->rite_->value_ == 9);
  Print(bst.root_->rite_->rite_->rite_->value_ == 10);
  Sprint("");

  // BST::Depth test case
  Sprint("BST::Depth test case");
  Print(bst.Depth(bst.root_->rite_));
  Sprint("");

  // BST::IsBalanced test case
  Sprint("BST::IsBalanced test case");
  Print(bst.IsBalanced(bst.root_) == 0);
  Print(bst.IsBalanced(bst.root_->left_) == 1);
  Print(bst.IsBalanced(bst.root_->rite_) == 0);
  Print(bst.IsBalanced(bst.root_->rite_->rite_) == 1);
  Print(bst.IsBalanced(bst.root_->left_->left_) == 1);
  Sprint("");

  // BST::Remove test case
  Sprint("BST::Remove test case");
  bst.Remove(2);
  bst.root_->PrintBfs();
  bst.Remove(3);
  bst.root_->PrintBfs();
  bst.Remove(5);
  bst.root_->PrintBfs();
  bst.Remove(7);
  bst.root_->PrintBfs();
  Sprint("");

  return 0;
}
