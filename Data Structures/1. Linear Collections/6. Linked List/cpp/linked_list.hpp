#pragma once

#include "node.hpp"

class LinkedList {
public:
  // member variables
  int count_;
  Node* head_;
  Node* tail_;

public:
  // constructor & destructor
  LinkedList();
  ~LinkedList();

  // accessors
  Node* first() const;
  Node* last() const;

  // basic operations
  void push(int key, int val);
  void remove(int key);
  bool isEmpty() const;
  bool includes(int key) const;
  Node* find(int key) const;

  // debugger
  void print() const;

private:
  // internal member functions
};
