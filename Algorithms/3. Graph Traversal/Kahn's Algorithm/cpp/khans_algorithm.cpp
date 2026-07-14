#include "khans_algorithm.hpp"

#include <iostream>
#include <map>
#include <queue>

#include "../Graphs/edge.hpp"
#include "../Graphs/node.hpp"


// Kahn's Algorithm - Topological Sorting
std::vector<Node*> Kahn(std::vector<Node*>& nodes) {
  std::queue<Node*> queue;
  std::vector<Node*> result;
  std::map<Node*, int> num_edges;

  for (int k = 0; k < nodes.size(); k++) {
    Node* node = nodes[k];
    num_edges[node] = (int) node->prev_edges_.size();
  }

  for (int k = 0; k < nodes.size(); k++) {
    Node* node = nodes[k];
    if (num_edges[node] == 0) queue.push(node);
  }

  while (!queue.empty()) {
    Node* node = queue.front();
    queue.pop();
    result.push_back(node);
    Vprint(result);

    std::list<Edge*>::iterator iter;
    std::list<Edge*> edges = node->next_edges_;

    for (iter = edges.begin(); iter != edges.end(); iter++) {
      Edge* edge = *iter;
      num_edges[edge->next_node_]--;

      if (num_edges[edge->next_node_] == 0) {
        queue.push(edge->next_node_);
      }
    }
  }

  if (result.size() != nodes.size()) result.clear();
  return result;
}


// debugger
void Vprint(std::vector<Node*>& array) {
  std::cout << "{ ";
  for (int index = 0; index < array.size(); index++) {
    std::cout << array[index]->value_;
    if (index < array.size() - 1) std::cout << ", ";
  }
  std::cout << " }\n" << std::endl;
}
