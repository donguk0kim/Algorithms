#pragma once
#include <list>
#include <vector>
#include "edge.hpp"

class Edge;

class Node {
public:
  // member variables
  std::list<Edge*> prevEdges;
  std::list<Edge*> nextEdges;
  int value;
  
public:
  // constructor
  Node(int value = 0);
  ~Node();
};
