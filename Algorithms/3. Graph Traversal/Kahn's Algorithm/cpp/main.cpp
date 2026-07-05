#include "KhansAlgorithm.hpp"

int main() {
  
  // test case
  
  Node node1(1);
  Node node2(2);
  Node node3(3);
  Node node4(4);
  Node node5(5);
  
  Edge edge12 {&node1, &node2};
  Edge edge14 {&node1, &node4};
  Edge edge23 {&node2, &node3};
  Edge edge24 {&node2, &node4};
  Edge edge45 {&node4, &node5};

  std::vector<Node*> nodes {&node5, &node3, &node1, &node2, &node4};
  std::vector<Node*> result {kahn(nodes)};
  vprint(result);
  
  return 0;
}
