#pragma once

#include <list>

class HashMap {
  // member variables
  int count_;
  int num_buckets_;
  std::list<int>* store_;

public:
  // constructor
  HashMap();

  // accessors
  int get(int key) const;
  void set(int key, int val);

  // basic operations
  void remove(int key);
  bool includes(int key) const;

  // debugger
  void print() const;

private:
  // private members
  void resize();
  void insert(int value);
  int hash(int value) const;
  int bucketIndex(int key, int n_buckets) const;
};
