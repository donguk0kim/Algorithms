#pragma once

class Node {
public:
  // member variables
  int key_;
  int val_;
  Node* next_;
  Node* prev_;

public:
  // constructor
  Node(int key = 0, int val = 0);

  // basic operations
  void Destroy();
};
