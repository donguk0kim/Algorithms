#pragma once
#include <list>
#include <vector>
#include "Edge.hpp"

class Edge;

class Node {
public:
  // member variables
  std::list<Edge*> prevEdges;
  std::list<Edge*> nextEdges;
  int value;
  
public:
  // constructor
  Node(int value = NULL);
  ~Node();
};
