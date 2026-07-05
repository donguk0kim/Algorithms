#include <iostream>
#include "LinkedList.hpp"

/* constructor */
LinkedList::LinkedList() : count{0} {
  this->head = new Node;
  this->tail = new Node;
  this->head->next = tail;
  this->tail->prev = head;
}

LinkedList::~LinkedList() {
  while (!isEmpty()) {
    last()->destroy();
  }
}

/* public */

// O(1)
Node* LinkedList::first() const {
  return head->next;
}

// O(1)
Node* LinkedList::last() const {
  return tail->prev;
}

// O(1)
void LinkedList::push(int key, int val) {
  Node* node = new Node(key, val);
  node->next = tail;
  node->prev = last();
  last()->next = node;
  tail->prev = node;
  count++;
}

// O(n)
void LinkedList::remove(int key) {
  Node* node = find(key);
  node->destroy();
  count--;
}

// O(n)
Node* LinkedList::find(int key) const {
  Node* node = first();
  while (node != tail) {
    if (node->key == key) return node;
    node = node->next;
  }
  return nullptr;
}

// O(n)
bool LinkedList::includes(int key) const {
  Node* node = first();
  while (node != tail) {
    if (node->key == key) {
      return true;
    }
    node = node->next;
  }
  return false;
}

bool LinkedList::isEmpty() const {
  return first() == tail;
}

// debugger
void LinkedList::print() const {
  int iter = 1;
  Node* node = first();
  std::cout << "{ ";
  while (node != tail) {
    if (iter < count) std::cout << "[" << node->key << "," << node->val << "], ";
    if (iter == count) std::cout << "[" << node->key << "," << node->val << "]";
    iter++;
    node = node->next;
  }
  std::cout << " }" << std::endl;
}
