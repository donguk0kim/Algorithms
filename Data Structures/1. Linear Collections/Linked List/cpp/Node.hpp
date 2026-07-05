class Node {
public:
  // member variables
  int key;
  int val;
  Node* next;
  Node* prev;
  
public:
  // constructor
  Node(int key = 0, int val = 0);
  
  // basic operations
  void destroy();
};
