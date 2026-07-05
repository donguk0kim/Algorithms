#pragma once
#include "Node.hpp"

class Node;

class Edge {
public:
  // member variables
  Node* prevNode;
  Node* nextNode;
  int weight;
  
public:
  // constructor
  Edge(Node* prevNode, Node* nextNode, int weight = 1);
  
  // basic operations
  void destroy();
  
private:
  // private members
  void connect();
};
