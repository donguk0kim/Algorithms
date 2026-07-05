#include "Bucket.hpp"

class IntegerSet {
private:
  // member variables
  int count;
  int numBuckets;
  Bucket* store;
  
public:
  // constructor
  IntegerSet();
  
  // basic operations
  int length() const;
  void insert(int val);
  void remove(int val);
  bool includes(int val) const;
  
  // debugger
  void print() const;
  
private:
  // internal member functions
  void fill();
  void resize();
  int hash(int val) const;
  int bucketIndex(int val, int nBuckets) const;
};
