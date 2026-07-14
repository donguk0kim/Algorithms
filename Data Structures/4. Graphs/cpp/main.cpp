#include "edge.hpp"
#include "node.hpp"

#include <iostream>

// debugger
void Print(int value) {
  std::cout << value << std::endl;
}

// debugger
void Sprint(const char* string) {
  std::cout << string << std::endl;
}

// debugger
void Lprint(std::list<Edge*> list) {
  int k = 0;
  std::cout << "{ ";
  for (std::list<Edge*>::iterator it = list.begin(); it != list.end(); it++) {
    std::cout << (*it)->next_node_->value_;
    if (k < list.size() - 1) std::cout << ", ";
    k++;
  }
  std::cout << " }" << std::endl;
}


int main() {

  // test case 1 - connection
  Sprint("test case 1 - connection");
  Node node1{1};
  Node node2{2};
  Node node3{3};

  Edge edge1_2{&node1, &node2};
  Edge edge2_1{&node2, &node1};
  Edge edge3_2{&node3, &node2};
  Edge edge2_3{&node2, &node3};

  Lprint(node1.next_edges_);
  Lprint(node2.next_edges_);
  Lprint(node3.next_edges_);
  Sprint("");


  // test case 2 - destruction
  Sprint("test case 2 - destruction");
  edge1_2.Destroy();
  edge3_2.Destroy();
  Lprint(node1.next_edges_);
  Lprint(node2.next_edges_);
  Lprint(node3.next_edges_);

  return 0;
}
