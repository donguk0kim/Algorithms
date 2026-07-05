#include "../Graphs/Edge.hpp"
#include "TarjansAlgorithm.hpp"

int main() {
  
  // test case - graph with no cycles
  Node node1{1};
  Node node2{2};
  Node node3{3};
  Node node4{4};
  Node node5{5};
  
  Edge edge12 {&node1, &node2};
  Edge edge14 {&node1, &node4};
  Edge edge23 {&node2, &node3};
  Edge edge34 {&node3, &node4};
  Edge edge45 {&node4, &node5};
  
  std::vector<Node*> nodes { &node2, &node5, &node1, &node4, &node3 };
  std::list<Node*> result1 {tarjan(nodes)};
  lprint(result1);
  
  // test case - graph with a cycle
  Node vertex1{1};
  Node vertex2{2};
  Node vertex3{3};
  Node vertex4{4};
  Node vertex5{5};
  
  Edge line12 {&vertex1, &vertex2};
  Edge line23 {&vertex2, &vertex3};
  Edge line34 {&vertex3, &vertex4};
  Edge line42 {&vertex4, &vertex2};
  Edge line45 {&vertex4, &vertex5};
  
  std::vector<Node*> vertices { &vertex2, &vertex5, &vertex1, &vertex4, &vertex3 };
  std::list<Node*> result2 {tarjan(nodes)};
  lprint(result2);
  
  return 0;
}
