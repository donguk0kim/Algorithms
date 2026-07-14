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
  int Length() const;
  void Insert(int val);
  void Remove(int val);
  bool Includes(int val) const;

  // debugger
  void Print() const;

private:
  // internal member functions
  void Fill();
  void Resize();
  int Hash(int val) const;
  int BucketIndex(int val, int n_buckets) const;
};
