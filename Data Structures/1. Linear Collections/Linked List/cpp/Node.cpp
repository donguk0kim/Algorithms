#include "Node.hpp"

/* constructor */
Node::Node(int key, int val) :
  key{key},
  val{val},
  next{nullptr},
  prev{nullptr} {
}

/* basic operations */
void Node::destroy() {
  next -> prev = prev;
  prev -> next = next;
  next = nullptr;
  prev = nullptr;
}
