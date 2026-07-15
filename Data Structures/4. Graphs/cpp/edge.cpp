#include "edge.hpp"

#include <iostream>

// constructor
Edge::Edge(Node* prev_node, Node* next_node, int weight) :
prev_node_{prev_node},
next_node_{next_node},
weight_{weight} {
  connect();
}

// basic operations
void Edge::destroy() {
  prev_node_->next_edges_.remove(this);
  next_node_->prev_edges_.remove(this);
  prev_node_ = nullptr;
  next_node_ = nullptr;
}

// private members
void Edge::connect() {
  prev_node_->next_edges_.push_back(this);
  next_node_->prev_edges_.push_back(this);
}
