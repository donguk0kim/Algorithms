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
  Node* First() const;
  Node* Last() const;

  // basic operations
  void Push(int key, int val);
  void Remove(int key);
  bool IsEmpty() const;
  bool Includes(int key) const;
  Node* Find(int key) const;

  // debugger
  void Print() const;

private:
  // internal member functions
};
