#pragma once

#include "node.hpp"

class Node;

class Edge {
public:
  // member variables
  Node* prev_node_;
  Node* next_node_;
  int weight_;

public:
  // constructor
  Edge(Node* prev_node, Node* next_node, int weight = 1);

  // basic operations
  void destroy();

private:
  // private members
  void connect();
};
