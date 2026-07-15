#include "node.hpp"

/* constructor */
Node::Node(int key, int val) :
  key_{key},
  val_{val},
  next_{nullptr},
  prev_{nullptr} {
}

/* basic operations */
void Node::destroy() {
  next_->prev_ = prev_;
  prev_->next_ = next_;
  next_ = nullptr;
  prev_ = nullptr;
}
