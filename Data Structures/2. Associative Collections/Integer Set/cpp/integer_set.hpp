#pragma once

#include "bucket.hpp"

class IntegerSet {
private:
  // member variables
  int count_;
  int num_buckets_;
  Bucket* store_;

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
  int bucketIndex(int val, int n_buckets) const;
};
