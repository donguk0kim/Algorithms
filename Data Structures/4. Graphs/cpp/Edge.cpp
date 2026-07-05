#include <iostream>
#include "Edge.hpp"

// constructor
Edge::Edge(Node* prevNode, Node* nextNode, int weight) :
prevNode{prevNode},
nextNode{nextNode},
weight{weight} {
  connect();
}

// basic operations
void Edge::destroy() {
  prevNode->nextEdges.remove(this);
  nextNode->prevEdges.remove(this);
  prevNode = nullptr;
  nextNode = nullptr;
}

// private members
void Edge::connect() {
  prevNode->nextEdges.push_back(this);
  nextNode->prevEdges.push_back(this);
}
