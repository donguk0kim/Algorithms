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
  while (!isEmpty()) {
    last()->destroy();
  }
}

/* public */

// O(1)
Node* LinkedList::first() const {
  return head_->next_;
}

// O(1)
Node* LinkedList::last() const {
  return tail_->prev_;
}

// O(1)
void LinkedList::push(int key, int val) {
  Node* node = new Node(key, val);
  node->next_ = tail_;
  node->prev_ = last();
  last()->next_ = node;
  tail_->prev_ = node;
  count_++;
}

// O(n)
void LinkedList::remove(int key) {
  Node* node = find(key);
  node->destroy();
  count_--;
}

// O(n)
Node* LinkedList::find(int key) const {
  Node* node = first();
  while (node != tail_) {
    if (node->key_ == key) return node;
    node = node->next_;
  }
  return nullptr;
}

// O(n)
bool LinkedList::includes(int key) const {
  Node* node = first();
  while (node != tail_) {
    if (node->key_ == key) {
      return true;
    }
    node = node->next_;
  }
  return false;
}

bool LinkedList::isEmpty() const {
  return first() == tail_;
}

// debugger
void LinkedList::print() const {
  int iter = 1;
  Node* node = first();
  std::cout << "{ ";
  while (node != tail_) {
    if (iter < count_) std::cout << "[" << node->key_ << "," << node->val_ << "], ";
    if (iter == count_) std::cout << "[" << node->key_ << "," << node->val_ << "]";
    iter++;
    node = node->next_;
  }
  std::cout << " }" << std::endl;
}
