#include "linked_list.hpp"

#include <iostream>

/* constructor */
LinkedList::LinkedList() : count_{0} {
  head_ = new Node;
  tail_ = new Node;
  head_->next_ = tail_;
  tail_->prev_ = head_;
}

LinkedList::~LinkedList() {
  while (!IsEmpty()) {
    Last()->Destroy();
  }
}

/* public */

// O(1)
Node* LinkedList::First() const {
  return head_->next_;
}

// O(1)
Node* LinkedList::Last() const {
  return tail_->prev_;
}

// O(1)
void LinkedList::Push(int key, int val) {
  Node* node = new Node(key, val);
  node->next_ = tail_;
  node->prev_ = Last();
  Last()->next_ = node;
  tail_->prev_ = node;
  count_++;
}

// O(n)
void LinkedList::Remove(int key) {
  Node* node = Find(key);
  node->Destroy();
  count_--;
}

// O(n)
Node* LinkedList::Find(int key) const {
  Node* node = First();
  while (node != tail_) {
    if (node->key_ == key) return node;
    node = node->next_;
  }
  return nullptr;
}

// O(n)
bool LinkedList::Includes(int key) const {
  Node* node = First();
  while (node != tail_) {
    if (node->key_ == key) {
      return true;
    }
    node = node->next_;
  }
  return false;
}

bool LinkedList::IsEmpty() const {
  return First() == tail_;
}

// debugger
void LinkedList::Print() const {
  int iter = 1;
  Node* node = First();
  std::cout << "{ ";
  while (node != tail_) {
    if (iter < count_) std::cout << "[" << node->key_ << "," << node->val_ << "], ";
    if (iter == count_) std::cout << "[" << node->key_ << "," << node->val_ << "]";
    iter++;
    node = node->next_;
  }
  std::cout << " }" << std::endl;
}
