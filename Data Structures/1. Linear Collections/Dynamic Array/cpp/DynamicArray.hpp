class DynamicArray {
  // member variables
  int count;
  int capacity;
  int* store;
  
public:
  // constructor & destructor
  DynamicArray();
  ~DynamicArray();
  
  // accessors
  int& operator[] (int index);
  
  // basic operations
  int pop();
  int shift();
  void push(int val);
  void unshift(int val);
  
  // debugger
  void print();

private:
  // internal members
  void fill();
  void resize();
  bool isInvalid(int index);
  void checkIndex(int index);
};
