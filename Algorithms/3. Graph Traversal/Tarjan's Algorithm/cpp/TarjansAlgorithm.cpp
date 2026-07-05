#include "../Graphs/Edge.hpp"
#include "TarjansAlgorithm.hpp"

// Tarjan's Algorithm - Topological Sorting
std::list<Node*> tarjan(std::vector<Node*>& nodes) {
  std::list<Node*> result;
  std::unordered_set<Node*> stack;
  std::unordered_set<Node*> visited;
  
  for (int k = 0; k < nodes.size(); k++) {
    Node* node = nodes[k];
    
    if (visited.find(node) == visited.end()) {
      bool isCyclic = visit(node, stack, visited, result);
      if (isCyclic) result.clear(); return result;
    }
  }
  
  return result;
}

bool visit(Node* node,
           std::unordered_set<Node*>& stack,
           std::unordered_set<Node*>& visited,
           std::list<Node*>& result) {
  
  stack.insert(node);
  visited.insert(node);
  std::list<Edge*>::const_iterator edgeIter;
  
  for (edgeIter = node->nextEdges.begin(); edgeIter != node->nextEdges.end(); edgeIter++) {
    Edge* edge = *edgeIter;
    Node* next = edge->nextNode;
    if (stack.find(next) != stack.end()) return true;
    if (visited.find(next) == visited.end()) {
      bool isCyclic = visit(next, stack, visited, result);
      if (isCyclic) return true;
    }
  }
  
  stack.erase(node);
  result.push_front(node);
  return false;
}


// debugger
void lprint(std::list<Node*>& list) {
  int index = 0;
  std::cout << "{ ";
  std::list<Node*>::const_iterator iter;
  for (iter = list.begin(); iter != list.end(); iter++) {
    std::cout << (*iter)->value;
    if (index < list.size() - 1) std::cout << ", ";
    index++;
  }
  std::cout << " }\n" << std::endl;
}
