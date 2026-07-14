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
  int Get(int key) const;
  void Set(int key, int val);

  // basic operations
  void Remove(int key);
  bool Includes(int key) const;

  // debugger
  void Print() const;

private:
  // private members
  void Resize();
  void Insert(int value);
  int Hash(int value) const;
  int BucketIndex(int key, int n_buckets) const;
};
