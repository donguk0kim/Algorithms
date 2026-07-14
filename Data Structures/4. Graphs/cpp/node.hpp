#pragma once

#include <list>
#include <vector>

#include "edge.hpp"

class Edge;

class Node {
public:
  // member variables
  std::list<Edge*> prev_edges_;
  std::list<Edge*> next_edges_;
  int value_;

public:
  // constructor
  Node(int value = 0);
  ~Node();
};
