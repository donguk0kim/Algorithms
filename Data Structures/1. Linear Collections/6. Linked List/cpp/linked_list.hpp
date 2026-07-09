#include "node.hpp"

class LinkedList {
public:
  // member variables
  int count;
  Node* head;
  Node* tail;
  
public:
  // constructor & destructor
  LinkedList();
  ~LinkedList();
  
  // accessors
  Node* first() const;
  Node* last() const;
  
  // basic operations
  void push(int key, int val);
  void remove(int key);
  bool is_empty() const;
  bool includes(int key) const;
  Node* find(int key) const;
  
  // debugger
  void print() const;
  
private:
  // internal member functions
};
