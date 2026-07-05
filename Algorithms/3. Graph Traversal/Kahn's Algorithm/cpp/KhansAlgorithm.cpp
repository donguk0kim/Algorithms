#include <map>
#include <queue>
#include <iostream>
#include "../Graphs/Node.hpp"
#include "../Graphs/Edge.hpp"
#include "KhansAlgorithm.hpp"


// Kahn's Algorithm - Topological Sorting
std::vector<Node*> kahn(std::vector<Node*>& nodes) {
  std::queue<Node*> queue;
  std::vector<Node*> result;
  std::map<Node*, int> numEdges;
  
  for (int k = 0; k < nodes.size(); k++) {
    Node* node = nodes[k];
    numEdges[node] = (int) node->prevEdges.size();
  }
  
  for (int k = 0; k < nodes.size(); k++) {
    Node* node = nodes[k];
    if (numEdges[node] == 0) queue.push(node);
  }
  
  while (!queue.empty()) {
    Node* node = queue.front();
    queue.pop();
    result.push_back(node);
    vprint(result);
    
    std::list<Edge*>::iterator iter;
    std::list<Edge*> edges = node->nextEdges;
    
    for (iter = edges.begin(); iter != edges.end(); iter++) {
      Edge* edge = *iter;
      numEdges[edge->nextNode]--;
      
      if (numEdges[edge->nextNode] == 0) {
        queue.push(edge->nextNode);
      }
    }
  }
  
  if (result.size() != nodes.size()) result.clear();
  return result;
}


// debugger
void vprint(std::vector<Node*>& array) {
  std::cout << "{ ";
  for (int index = 0; index < array.size(); index++) {
    std::cout << array[index]->value;
    if (index < array.size() - 1) std::cout << ", ";
  }
  std::cout << " }\n" << std::endl;
}
