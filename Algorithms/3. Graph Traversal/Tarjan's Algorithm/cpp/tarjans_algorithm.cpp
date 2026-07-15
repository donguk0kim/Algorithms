#include "tarjans_algorithm.hpp"

#include "edge.hpp"

// Tarjan's Algorithm - Topological Sorting
std::list<Node*> tarjan(std::vector<Node*>& nodes) {
  std::list<Node*> result;
  std::unordered_set<Node*> stack;
  std::unordered_set<Node*> visited;

  for (int k = 0; k < nodes.size(); k++) {
    Node* node = nodes[k];

    if (visited.find(node) == visited.end()) {
      bool is_cyclic = visit(node, stack, visited, result);
      if (is_cyclic) result.clear(); return result;
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
  std::list<Edge*>::const_iterator edge_iter;

  for (edge_iter = node->next_edges_.begin(); edge_iter != node->next_edges_.end(); edge_iter++) {
    Edge* edge = *edge_iter;
    Node* next = edge->next_node_;
    if (stack.find(next) != stack.end()) return true;
    if (visited.find(next) == visited.end()) {
      bool is_cyclic = visit(next, stack, visited, result);
      if (is_cyclic) return true;
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
    std::cout << (*iter)->value_;
    if (index < list.size() - 1) std::cout << ", ";
    index++;
  }
  std::cout << " }\n" << std::endl;
}
