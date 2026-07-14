#include "edge.hpp"

#include <iostream>

// constructor
Edge::Edge(Node* prev_node, Node* next_node, int weight) :
prev_node_{prev_node},
next_node_{next_node},
weight_{weight} {
  Connect();
}

// basic operations
void Edge::Destroy() {
  prev_node_->next_edges_.remove(this);
  next_node_->prev_edges_.remove(this);
  prev_node_ = nullptr;
  next_node_ = nullptr;
}

// private members
void Edge::Connect() {
  prev_node_->next_edges_.push_back(this);
  next_node_->prev_edges_.push_back(this);
}
