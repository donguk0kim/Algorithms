class MaxIntSet {
  // member variables
  int capacity;
  bool* store;
    
public:
  // constructor
  MaxIntSet(int max);
  
  // basic operations
  void insert(int value);
  void remove(int value);
  bool includes(int value) const;
  
  // debugger
  void print() const;
    
private:
  // internal members
  void fill();
  bool isInvalid(int index) const;
  void checkIndex(int index) const;
};
