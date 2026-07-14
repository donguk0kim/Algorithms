#include "node.hpp"

// constructor
Node::Node(int value) :
  value_{value} {
}

// destructor
Node::~Node() {
  prev_edges_.clear();
  next_edges_.clear();
  value_ = 0;
}
